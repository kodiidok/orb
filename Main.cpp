
#include <iostream>
#include <math.h>
#include <vector>
#include <string>

#include <GL/glut.h>
#include <SOIL2.h>

#include "Constants.h"
#include "Materials.h"
#include "Utils.h"
#include "Lights.h"
#include "Axes.h"
#include "Cube.h"
#include "Castle.h"
#include "Props.h"

using namespace std;

float win_h = 480.0f, win_w = 720.0f;
float win_posx = 300.0f, win_posy = 300.0f;

float cam_posx = 0.0f, cam_posy = 0.0f, cam_posz = 0.0f;
float cam_rotx = 0.0f, cam_roty = 0.0f, cam_rotz = 0.0f;

float fovy = 90.0f, aspect = win_w / win_h, zNear = 0.1, zfar = 100.0f;

RGBcolor lightGray = { 0.90f, 0.90f, 0.90f };      // Light Gray
RGBcolor mediumGray = { 0.5f, 0.5f, 0.5f };        // Medium Gray
RGBcolor darkGray = { 0.25f, 0.25f, 0.25f };        // Dark Gray
RGBcolor lightBrown = { 0.7f, 0.5f, 0.25f };       // Light Brown
RGBcolor oliveGreen = { 0.5f, 0.5f, 0.0f };        // Olive Green
RGBcolor steelBlue = { 0.27f, 0.51f, 0.71f };      // Steel Blue
RGBcolor darkCyan = { 0.0f, 0.55f, 0.55f };        // Dark Cyan
RGBcolor plum = { 0.87f, 0.63f, 0.87f };           // Plum
RGBcolor sienna = { 0.63f, 0.32f, 0.18f };         // Sienna
RGBcolor slateGray = { 0.44f, 0.5f, 0.56f };       // Slate Gray
RGBcolor lightMagenta = { 0.77f, 0.56f, 0.77f };    // Light Magenta
RGBcolor darkOliveGreen = { 0.33f, 0.42f, 0.18f };  // Dark Olive Green
RGBcolor skyBlue = { 0.53f, 0.81f, 0.98f };         // Sky Blue
RGBcolor darkSlateGray = { 0.18f, 0.31f, 0.31f };   // Dark Slate Gray
RGBcolor salmon = { 0.98f, 0.5f, 0.45f };           // Salmon
RGBcolor goldenrod = { 0.85f, 0.65f, 0.13f };       // Goldenrod
RGBcolor mediumPurple = { 0.58f, 0.44f, 0.86f };    // Medium Purple
RGBcolor chocolate = { 0.82f, 0.41f, 0.12f };      // Chocolate
RGBcolor lightSlateGray = { 0.47f, 0.53f, 0.6f };   // Light Slate Gray

void textures() {
	Textures::setTextureFilePath("cliff_rocks_1_col", "assets/textures/cliff_rocks_01_1k/cliff_rocks_01_color_1k.png");
}

void init() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
	glEnable(GL_BLEND);
	textures();
}

void camera() {

	float eyex = 0.0f, eyey = 2.0f, eyez = 8.0f;
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

	vector<GLfloat> pos0 = { 0.0f, 2.0f, 2.0f, 1.0f };
	vector<GLfloat> diff0 = { 1.0f, 1.0f, 1.0f, 1.0f };
	vector<GLfloat> dir0 = { 0.0f, -1.0f, -1.0f, 1.0f };
	GLfloat cutoff0 = 120.0f;
	spotLight(GL_LIGHT0, pos0, diff0, dir0, cutoff0);

	vector<GLfloat> pos1 = { 0.0f, 0.0f, 4.0f, 1.0f };
	vector<GLfloat> diff1 = { 1.0f, 1.0f, 0.0f, 1.0f };
	pointLight(GL_LIGHT1, pos1, diff1);
}

void posIndicator(Point3D& pos) {
	glEnable(GL_COLOR_MATERIAL);
	glPointSize(3.0f);
	glBegin(GL_POINTS);
	glVertex3f(pos.x, pos.y, pos.z);
	glEnd();
	glPointSize(1.0f);
	glDisable(GL_COLOR_MATERIAL);
}

void dirIndicator(Point3D& src, Point3D& dest) {
	glEnable(GL_COLOR_MATERIAL);
	glBegin(GL_LINES);
	glVertex3f(src.x, src.y, src.z);
	glVertex3f(dest.x, dest.y, dest.z);
	glEnd();
	glDisable(GL_COLOR_MATERIAL);
}

void hexagonNormalIndicator() {
	float radius = 1.0f;  // Adjust the radius as needed

	for (int i = 0; i < 6; ++i) {
		glPushMatrix();

		// Calculate the position in a circle
		float angle = i * (M_PI / 3);  // 60 degrees in radians
		float x = radius * cos(angle);
		float z = radius * sin(angle);

		// Draw a line from the origin to the centroid
		Point3D origin = { 0.0f, 0.0f, 0.0f };
		Point3D n = { x, 0.0f, z };
		glColor3f(1.0f, 0.0f, 1.0f);
		dirIndicator(origin, n);
		drawLabel("n" + to_string(i), n.x, n.y, n.z);

		glPopMatrix();
	}
}

void indicators() {
	addMaterial(DARK_GRAY_MATTE);

	drawLabel("front", 0.0f, 0.0f, 3.0f);
	drawLabel("back", 0.0f, 0.0f, -3.0f);
	drawLabel("left", -3.0f, 0.0f, 0.0f);
	drawLabel("right", 3.0f, 0.0f, 0.0f);

	Point3D light0_pos = { 0.0f, 2.0f, 2.0f };
	Point3D light0_dir = { 0.0f, -1.0f, -1.0f };
	glColor3f(1.0f, 1.0f, 0.0f);
	posIndicator(light0_pos);
	dirIndicator(light0_pos, light0_dir);
	drawLabel("light 0", light0_pos.x, light0_pos.y, light0_pos.z);

	hexagonNormalIndicator();
}

void sceneMap() {
	// stairs
	glPushMatrix();
	glTranslatef(-5.0f, -1.0f, 1.5f);
	glRotatef(27.0f, 0.0f, 1.0f, 0.0f);
	stairs({ 3.5f, 1.0f, 0.5f });
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5.0f, -1.0f, 1.5f);
	glRotatef(-27.0f, 0.0f, 1.0f, 0.0f);
	stairs({ 3.5f, 1.0f, 0.5f });
	glPopMatrix();

	// railing base
	glPushMatrix();
	glTranslatef(0.0f, -0.25f, 0.0f);

	glPushMatrix();
	glTranslatef(2.0f, 0.0f, -4.0f);
	glRotatef(-60.0f, 0.0f, 1.0f, 0.0f);
	for (int i = 0; i < 4; i++) {
		glTranslatef(1.0f, 0.0f, 0.0f);
		railing(1.0f);
	}
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.5f, 0.0f, -7.0f);
	glRotatef(-60.0f, 0.0f, 1.0f, 0.0f);
	for (int i = 0; i < 7; i++) {
		glTranslatef(1.0f, 0.0f, 0.0f);
		railing(1.0f);
	}
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.0f, 0.0f, -4.0f);
	glRotatef(60.0f, 0.0f, 1.0f, 0.0f);
	for (int i = 0; i < 4; i++) {
		glTranslatef(-1.0f, 0.0f, 0.0f);
		railing(1.0f);
	}
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3.5f, 0.0f, -7.0f);
	glRotatef(60.0f, 0.0f, 1.0f, 0.0f);
	for (int i = 0; i < 7; i++) {
		glTranslatef(-1.0f, 0.0f, 0.0f);
		railing(1.0f);
	}
	glPopMatrix();

	glPopMatrix();

	// tower
	//glPushMatrix();
	//glTranslatef(0.0f, -0.2f, -7.0f);
	//glRotatef(-30.0f, 0.0f, 1.0f, 0.0f);
	//tower3({ 1.0f, 1.0f, 1.0f });
	//glPopMatrix();

	// back panel base
	glPushMatrix();
	glTranslatef(0.0f, -0.8f, -7.0f);
	hexagonBlock(0.0f, 0.0f, 4.0f, 1.0f, 0.0f);
	glPopMatrix();

	// 3 panel base
	//glPushMatrix();
	//glTranslatef(0.0f, -2.0f, 0.0f);
	//glRotatef(-120.0f, 0.0f, 1.0f, 0.0f);
	//partialHexagonBlock(3, 0.0f, 0.0f, 8.0f, 3.0f, 4.0f);
	//glPopMatrix();

	//glPushMatrix();
	//glTranslatef(0.0f, -4.0f, 0.0f);
	//glRotatef(-120.0f, 0.0f, 1.0f, 0.0f);
	//partialHexagonBlock(6, 0.0f, 0.0f, 8.0f, 1.0f, 4.0f);
	//glPopMatrix();
}

void scene() {
	glPushMatrix();
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	addMaterial(WHITE_MATTE);

	//rocks();

	// right tower

	glPushMatrix();
	glTranslatef(5.0f, -2.0f, 3.0f);
	glRotatef(0.0f, 0.0f, 0.0f, 0.0f);
	glScalef(0.7f, 1.0f, 0.7f);

	glColor3f(lightBrown.r, lightBrown.g, lightBrown.b);
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -7.0f);
	glScalef(0.75f, 3.0f, 0.75f);
	hexagonOpenWall("");
	glPopMatrix();

	glColor3f(plum.r, plum.g, plum.b);
	glPushMatrix();
	glTranslatef(0.0f, 2.2f, -7.0f);
	glScalef(2.5f, 0.5f, 2.5f);
	hexagonBlock("");
	glPopMatrix();

	glPopMatrix();

	// left tower

	glPushMatrix();
	glTranslatef(-5.0f, -2.0f, 3.0f);
	glRotatef(0.0f, 0.0f, 0.0f, 0.0f);
	glScalef(0.7f, 1.0f, 0.7f);

	glColor3f(lightBrown.r, lightBrown.g, lightBrown.b);
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -7.0f);
	glScalef(0.75f, 3.0f, 0.75f);
	hexagonOpenWall("");
	glPopMatrix();

	glColor3f(plum.r, plum.g, plum.b);
	glPushMatrix();
	glTranslatef(0.0f, 2.2f, -7.0f);
	glScalef(2.5f, 0.5f, 2.5f);
	hexagonBlock("");
	glPopMatrix();

	glPopMatrix();

	// tower

	glColor3f(lightBrown.r, lightBrown.g, lightBrown.b);
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -7.0f);
	glScalef(0.75f, 3.0f, 0.75f);
	hexagonOpenWall("");
	glPopMatrix();

	glColor3f(plum.r, plum.g, plum.b);
	glPushMatrix();
	glTranslatef(0.0f, 2.2f, -7.0f);
	glScalef(2.5f, 0.5f, 2.5f);
	hexagonBlock("");
	glPopMatrix();

	glColor3f(lightBrown.r, lightBrown.g, lightBrown.b);
	glPushMatrix();
	glTranslatef(0.0f, -3.0f, -7.0f);
	glScalef(0.75f, 3.0f, 0.75f);
	hexagonOpenWall("");
	glPopMatrix();

	//glColor3f(goldenrod.r, goldenrod.g, goldenrod.b);
	//glPushMatrix();
	//glTranslatef(0.0f, 0.0f, -4.0f);
	//glScalef(3.5f, 4.0f, 3.5f);
	//hexagonOpenWall("");
	//glPopMatrix();

	// tower base plate

	glColor3f(sienna.r, sienna.g, sienna.b);
	glPushMatrix();
	glTranslatef(0.0f, -5.7f, -7.0f);
	glScalef(4.0f, 3.0f, 4.0f);
	hexagonBlock("");
	glPopMatrix();

	// orb holder

	glColor3f(oliveGreen.r, oliveGreen.g, oliveGreen.b);
	glPushMatrix();
	glTranslatef(0.0f, -4.0f, 4.0f);
	glScalef(2.0f, 1.0f, 2.0f);
	hexagonBlock("");
	glPopMatrix();

	// stairs

	glColor3f(steelBlue.r, steelBlue.g, steelBlue.b);
	
	//stairs();

	glPushMatrix();
	glTranslatef(4.0f, 0.0f, 2.0f);
	glScalef(1.0f, 1.0f, 1.0f);
	glRotatef(-60.0f, 0.0f, 1.0f, 0.0f);
	stairs();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4.0f, 0.0f, 2.0f);
	glScalef(1.0f, 1.0f, 1.0f);
	glRotatef(60.0f, 0.0f, 1.0f, 0.0f);
	stairs();
	glPopMatrix();

	// rocks

	glColor3f(salmon.r, salmon.g, salmon.b);
	
	glPushMatrix();
	glTranslatef(4.0f, -2.0f, -1.0f);
	glScalef(2.0f, 3.0f, 2.0f);
	glRotatef(90.0f, 0.5f, 1.0f, 1.0f);
	rock5("");
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4.0f, -2.0f, -1.0f);
	glScalef(2.0f, 3.0f, 2.0f);
	glRotatef(28.0f, 0.0f, 1.0f, 0.0f);
	rock4("");
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-5.0f, -2.0f, -3.0f);
	glScalef(3.0f, 5.0f, 2.0f);
	glRotatef(28.0f, 1.0f, 1.0f, 0.0f);
	rock2("");
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5.0f, -3.0f, -3.0f);
	glScalef(3.0f, 5.0f, 2.0f);
	glRotatef(84.0f, 1.0f, 0.0f, 1.0f);
	rock2("");
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3.0f, -2.0f, -6.0f);
	glScalef(4.0f, 6.0f, 3.0f);
	glRotatef(38.0f, 1.0f, 1.0f, 0.0f);
	rock3("");
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.0f, -2.0f, -6.0f);
	glScalef(4.0f, 6.0f, 3.0f);
	glRotatef(69.0f, 0.0f, 1.0f, 1.0f);
	rock3("");
	glPopMatrix();

	// 3 panel base

	glColor3f(sienna.r, sienna.g, sienna.b);
	
	glPushMatrix();
	glTranslatef(0.0f, -4.0f, 0.0f);
	glScalef(8.5f, 0.35f, 8.5f);
	hexagonWalkPath("");
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, -4.5f, 1.0f);
	glScalef(8.5f, 0.35f, 8.5f);
	hexagonWalkPath("");
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, -5.0f, 2.0f);
	glScalef(8.5f, 0.35f, 8.5f);
	hexagonWalkPath("");
	glPopMatrix();

	// orb

	glColor4f(0.5f, 0.5f, 1.0f, 0.5f);
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 4.0f);
	glScalef(1.0f, 1.0f, 1.0f);
	deformedCube("");
	glPopMatrix();

	// clouds

	glColor3f(lightGray.r, lightGray.g, lightGray.b);

	//glPushMatrix();
	//glTranslatef(-6.0f, 0.0f, 0.0f);
	//glScalef(1.35f, 1.35f, 1.35f);
	//glRotatef(30.0f, 0.0f, 1.0f, 0.0f);
	//cloud3("");
	//glPopMatrix();

	//glPushMatrix();
	//glTranslatef(5.0f, -3.0f, 0.0f);
	//glScalef(0.35f, 0.35f, 0.35f);
	//glRotatef(0.0f, 0.0f, 1.0f, 0.2f);
	//cloud1("");
	//glPopMatrix();

	//glPushMatrix();
	//glTranslatef(12.0f, -3.5f, 2.0f);
	//glScalef(0.35f, 0.46f, 0.35f);
	//glRotatef(45.0f, 0.0f, 1.0f, 0.0f);
	//cloud2("");
	//glPopMatrix();

	//glPushMatrix();
	//glTranslatef(-9.0f, -3.0f, 5.0f);
	//glScalef(0.45f, 0.25f, 0.35f);
	//glRotatef(-186.0f, 0.0f, 1.0f, 0.15f);
	//cloud2("");
	//glPopMatrix();

	//glPushMatrix();
	//glTranslatef(0.5f, -4.5f, 0.0f);
	//glScalef(0.85f, 0.76f, 1.25f);
	//glRotatef(15.0f, 0.0f, 1.0f, 0.0f);
	//cloud2("");
	//glPopMatrix();

	//sceneMap();

	glDisable(GL_COLOR_MATERIAL);
	glDisable(GL_NORMALIZE);
	glPopMatrix();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	camera();
	lights();

	axes();

	//glPushMatrix();
	//glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	//grid();
	//glPopMatrix();
	//drawCartesianCoordinates();

	indicators();

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