
#include <iostream>
#include <math.h>
#include <vector>

#include <GL/glut.h>
#include <SOIL2.h>

#include "Constants.h"
#include "Materials.h"
#include "Lights.h"
#include "Axes.h"
#include "Cube.h"
#include "Castle.h"
#include <string>

using namespace std;

float win_h = 480.0f, win_w = 720.0f;
float win_posx = 300.0f, win_posy = 300.0f;

float cam_posx = 0.0f, cam_posy = 0.0f, cam_posz = 0.0f;
float cam_rotx = 0.0f, cam_roty = 0.0f, cam_rotz = 0.0f;

float fovy = 90.0f, aspect = win_w / win_h, zNear = 0.1, zfar = 100.0f;

void init() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glShadeModel(GL_SMOOTH);
}

void camera() {

	float eyex = 0.0f, eyey = 0.0f, eyez = 2.0f;
	float centerx = 0.0f, centery = 0.0f, centerz = 0.0f;
	float upx = 0.0f, upy = 1.0f, upz = 0.0f;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(fovy, aspect, zNear, zfar);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(eyex, eyey, eyez, centerx, centery, centerz, upx, upy, upz);

	glTranslatef(cam_posx, cam_posy, cam_posz);

	glRotatef(cam_rotx, 1.0, 0.0f, 0.0f);
	glRotatef(cam_roty, 0.0f, 1.0f, 0.0f);
	glRotatef(cam_rotz, 0.0f, 0.0f, 1.0f);
}

void lights() {
	glEnable(GL_LIGHTING);

	vector<GLfloat> pos0 = { 0.0f, 5.0f, 0.0f, 1.0f };
	vector<GLfloat> diff0 = { 1.0f, 1.0f, 1.0f, 1.0f };
	vector<GLfloat> dir0 = { 0.0f, -1.0f, 0.0f, 1.0f };
	GLfloat cutoff0 = 120.0f;
	spotLight(GL_LIGHT0, pos0, diff0, dir0, cutoff0);
}

void drawLabel(string text, float x, float y, float z) {
	glColor3f(0.5f, 0.5f, 0.5f);

	// Set the raster position to a visible location
	glRasterPos3f(x, y, z);

	// Render each character in the string
	for (char character : text) {
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, character);
	}
}

vector<Point3D> circle(float centerx, float centery, float z, float radius, int segments) {
	vector<Point3D> v;

	for (int i = 0; i < segments; ++i) {
		float theta = 2.0f * M_PI * float(i) / float(segments);  // Angle for each segment
		float x = centerx + radius * cos(theta);
		float y = centery + radius * sin(theta);
		Point3D p = { x, y, z };
		v.push_back(p);
	}

	return v;
}

vector<Point3D> drawCircle(GLenum mode, float centerx, float centery, float z, float radius, int segments) {
	vector<Point3D> circ_coord = circle(centerx, centery, z, radius, segments);
	glBegin(mode);
	for (size_t i = 0; i < circ_coord.size(); ++i) {
		const Point3D& c = circ_coord[i];
		float x = c.x;
		float y = c.y;
		float z = c.z;
		std::cout << "v" << i << ":\t" << x << ", " << y << ", " << z << '\n';
		glVertex3f(x, y, z);
	}
	glEnd();
	return circ_coord;
}

vector<Point3D> semiCircle(float centerx, float centery, float z, float radius, int segments) {
	vector<Point3D> v;

	for (int i = 0; i < 1 + (segments / 2); ++i) {
		float theta = 2.0f * M_PI * float(i) / float(segments);  // Angle for each segment
		float x = centerx + radius * cos(theta);
		float y = centery + radius * sin(theta);
		Point3D p = { x, y, z };
		v.push_back(p);
	}

	return v;
}

vector<Point3D> drawSemiCircle(GLenum mode, float centerx, float centery, float z, float radius, int segments) {
	vector<Point3D> semicirc_coord = semiCircle(centerx, centery, z, radius, segments);
	glBegin(mode);
	for (size_t i = 0; i < semicirc_coord.size(); ++i) {
		const Point3D& c = semicirc_coord[i];
		float x = c.x;
		float y = c.y;
		float z = c.z;
		std::cout << "v" << i << ":\t" << x << ", " << y << ", " << z << '\n';
		glVertex3f(x, y, z);
	}
	glEnd();
	return semicirc_coord;
}

vector<Point3D> booleanDifference(const vector<Point3D>& subject, const vector<Point3D>& clip) {
	vector<Point3D> result;
	vector<Point3D> fromClip;

	// Iterate through each point in the subject
	for (const auto& s : subject) {
		bool insideClip = false;

		// Check if the point is inside the clip polygon
		for (size_t i = 0, j = clip.size() - 1; i < clip.size(); j = i++) {
			if (((clip[i].y > s.y) != (clip[j].y > s.y)) &&
				(s.x < (clip[j].x - clip[i].x) * (s.y - clip[i].y) / (clip[j].y - clip[i].y) + clip[i].x)) {
				insideClip = !insideClip;
			}
		}

		// If the point is inside the clip polygon, add it to the result
		if (!insideClip) {
			result.push_back(s);
		}
	}

	result.push_back(clip[clip.size() - 1]);

	// Iterate through each point in the clip
	for (const auto& c : clip) {
		bool insideSubject = false;

		// Check if the point is inside the subject polygon
		for (size_t i = 0, j = subject.size() - 1; i < subject.size(); j = i++) {
			if (((subject[i].y > c.y) != (subject[j].y > c.y)) &&
				(c.x < (subject[j].x - subject[i].x) * (c.y - subject[i].y) / (subject[j].y - subject[i].y) + subject[i].x)) {
				insideSubject = !insideSubject;
			}
		}

		// If the point is inside the clip polygon, add it to the result
		if (insideSubject) {
			fromClip.push_back(c);
		}
	}

	// Reverse the fromClip vector
	reverse(fromClip.begin(), fromClip.end());

	// Add the reversed fromClip vector to the result vector
	result.insert(result.end(), fromClip.begin(), fromClip.end());

	return result;
}

vector<Point3D> drawBooleanDifference(vector<Point3D>& subject, vector<Point3D>& clip) {
	// Perform boolean difference
	vector<Point3D> result = booleanDifference(subject, clip);

	// Output the result
	glBegin(GL_POLYGON);
	for (size_t i = 0; i < result.size(); ++i) {
		const Point3D& c = result[i];
		float x = c.x;
		float y = c.y;
		float z = c.z;
		glVertex3f(x, y, z);
	}
	glEnd();

	return result;
}

vector<Point3D> quad() {
	vector<Point3D> v;

	return v;
};

vector<Point3D> wallWithOpenArch(float w, float h, float cx, float cy, float cz, float radius, int segments) {
	vector<Point3D> sc = semiCircle(cx, cy, cz, radius, segments);
	vector<Point3D> result;

	size_t changer = sc.size() / 4;

	float offsetx = (radius + w) / changer;
	float offsetyu = 0.0f;
	float offsetyd = 0.0f;

	glBegin(GL_QUAD_STRIP);
	for (size_t i = 0; i < sc.size(); i++) {
		const Point3D& c = sc[i];
		float x = c.x;
		float y = c.y;
		float z = c.z;

		glVertex3f(x, y, z);
		result.push_back({ x, y, z });

		if (i <= changer) {
			glVertex3f(radius + w, cy + offsetyu, z);
			result.push_back({ radius + w, cy + offsetyu, z });
			offsetyu += h / changer;
		} 
		else if (i < 3 * changer) {
			glVertex3f(radius + w - offsetx, h, z);
			result.push_back({ radius + w - offsetx, h, z });
			offsetx += (w + radius) / changer;
		}
		else {
			glVertex3f(-(radius + w), h - offsetyd, z);
			result.push_back({ -(radius + w), h - offsetyd, z });
			offsetyd += h / changer;
		}
	}
	glEnd();

	return result;
}

void scene() {
	glPushMatrix();
	glEnable(GL_NORMALIZE);

	addMaterial(DARK_GRAY_MATTE);

	vector<Point3D> wwoa = wallWithOpenArch(0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.5f, 16);

	addMaterial(WHITE_MATTE);
	//for (size_t i = 0; i < wwoa.size(); i++) {
	//	printf("%f, %f, %f\n", wwoa[i].x, wwoa[i].y, wwoa[i].z);
	//	string label = "v" + to_string(i) + ", " + to_string(wwoa[i].x) + ", " + to_string(wwoa[i].y);
	//	drawLabel(label, wwoa[i].x, wwoa[i].y, wwoa[i].z);
	//}

	//size_t changer = 5 / 4;
	//drawLabel(to_string(changer), 0.0f, 0.0f, 1.5f);

	glDisable(GL_NORMALIZE);
	glPopMatrix();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	camera();
	lights();

	axes();

	glPushMatrix();
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	grid();
	glPopMatrix();
	//drawCartesianCoordinates();

	scene();

	glutSwapBuffers();
}

void reshape(int w, int h) {
	glViewport(0, 0, w, h);
	GLfloat aspect = h == 0 ? w / 1 : (float)w / (float)h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(fovy, aspect, zNear, zfar);
}

void keyboardSpecial(int key, int x, int y) {
	if (key == GLUT_KEY_UP) {
		if (glutGetModifiers() == GLUT_ACTIVE_SHIFT) {
			cam_posy += 0.1;
		}
		else {
			if (glutGetModifiers() == GLUT_ACTIVE_CTRL) {
				cam_rotx += 5.0f;
			}
			else {
				cam_posz += 0.1f;
			}
		}
	}
	if (key == GLUT_KEY_DOWN) {
		if (glutGetModifiers() == GLUT_ACTIVE_SHIFT) {
			cam_posy -= 0.1;
		}
		else {
			if (glutGetModifiers() == GLUT_ACTIVE_CTRL) {
				cam_rotx -= 5.0f;
			}
			else {
				cam_posz -= 0.1f;
			}
		}
	}
	if (key == GLUT_KEY_LEFT) {
		if (glutGetModifiers() == GLUT_ACTIVE_CTRL) {
			cam_roty += 5.0f;
		}
		else {
			cam_posx -= 0.1f;
		}
	}
	if (key == GLUT_KEY_RIGHT) {
		if (glutGetModifiers() == GLUT_ACTIVE_CTRL) {
			cam_roty -= 5.0f;
		}
		else {
			cam_posx += 0.1f;
		}
	}

	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);

	glutInitWindowSize(win_w, win_h);
	glutInitWindowPosition(win_posx, win_posy);
	glutCreateWindow("Orb");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	glutSpecialFunc(keyboardSpecial);
	glutKeyboardFunc(keyboard);

	init();
	glutMainLoop();

	return 0;
}