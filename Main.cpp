#include <iostream>
#include <sstream>
#include <GL/glut.h>
#include <math.h>
#include <SOIL2.h>

#include "Mesh.h"
#include "KCube.h"
#include "Materials.h"

int window_height = 480;
int window_width = 720;

float camX, camY, camZ = 0.0f;
float posX, posY, posZ = 0.0f;
float rotX, rotY, rotZ = 0.0f;

float pi = 3.14;

void init() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glShadeModel(GL_FLAT);
}

void text(float x, float y, float z, const std::string& text) {
	glRasterPos3f(x, y, z);
	for (const char& c : text) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
	}
}

void grid() {
	GLfloat ext = 30.0f;
	GLfloat step = 1.0f;
	GLfloat yGrid = -0.0f;
	GLint line;

	glBegin(GL_LINES);
	for (line = -ext; line <= ext; line += step) {
		glVertex3f(line, yGrid, ext);
		glVertex3f(line, yGrid, -ext);

		glVertex3f(ext, yGrid, line);
		glVertex3f(-ext, yGrid, line);
	}
	glEnd();

	// Label along x-axis
	text(2.0f, 0.0f, 0.0f, "2x");
	text(-2.0f, 0.0f, 0.0f, "-2x");

	// Label along y-axis
	text(0.0f, 2.0f, 0.0f, "2y");
	text(0.0f, -2.0f, 0.0f, "-2y");

	// Label along z-axis
	text(0.0f, 0.0f, 2.0f, "2z");
	text(0.0f, 0.0f, -2.0f, "-2z");

}

void camera(
	GLdouble eyex = 2.0f, GLdouble eyey = 2.0f, GLdouble eyez = -2.0f,
	GLdouble cx = 0.0f, GLdouble cy = 0.0f, GLdouble cz = 0.0f,
	GLdouble upx = 0.0f, GLdouble upy = 1.0f, GLdouble upz = 0.0f
) {

	gluLookAt(eyex + camX, eyey + camY, eyez + camZ, cx, cy, cz, upx, upy, upz);
	glColor3f(1.0, 1.0, 1.0);

	glTranslatef(posX, posY, posZ);

	glRotatef(rotX, 1.0f, 0.0f, 0.0f);
	glRotatef(rotY, 0.0f, 1.0f, 0.0f);
	glRotatef(rotZ, 0.0f, 0.0f, 1.0f);

	text(0.0f, 0.0f, -1.0f, "front face");
}

void lights() {

	// Light 0 - Key Light (main light)
	glEnable(GL_LIGHT0);
	GLfloat light0_position[] = { 5.0f, 5.0f, 5.0f, 1.0f }; // Positional light from the top-right-front
	GLfloat light0_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };  // Diffuse color (white)
	GLfloat light0_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // Specular color (white)

	glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);

	// Light 1 - Fill Light (soft, less intense)
	glEnable(GL_LIGHT1);
	GLfloat light1_position[] = { 1.0f, 2.0f, 0.0f, 1.0f }; // Positional light from the left-top-front
	GLfloat light1_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };  // Diffuse color (gray)
	GLfloat light1_specular[] = { 0.2f, 0.2f, 0.2f, 1.0f }; // Specular color (gray)

	glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);

	// Light 2 - Rim Light (accent light from the back)
	glEnable(GL_LIGHT2);
	GLfloat light2_position[] = { -3.0f, 3.0f, -3.0f, 1.0f }; // Positional light from the left-top-back
	GLfloat light2_diffuse[] = { 0.5f, 0.5f, 0.5f, 1.0f };  // Diffuse color (gray)
	GLfloat light2_specular[] = { 0.0f, 0.0f, 0.0f, 1.0f }; // Specular color (black)

	glLightfv(GL_LIGHT2, GL_POSITION, light2_position);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, light2_diffuse);
	glLightfv(GL_LIGHT2, GL_SPECULAR, light2_specular);

}

void kOctagonPlane(GLfloat size, GLfloat thickness) {
	GLfloat top[8][3]{};
	GLfloat bottom[8][3]{};

	for (int i = 0; i < 8; ++i) {
		float angle = i * (2 * pi / 8);
		float x = cos(angle);
		float z = sin(angle);

		top[i][0] = x;
		top[i][1] = 0.0f;
		top[i][2] = z;

		if (thickness > 0.0f) {
			bottom[i][0] = x;
			bottom[i][1] = 0.0f + thickness;
			bottom[i][2] = z;
		}
	}

	glPushMatrix();
	glScalef(1.0f * size, 1.0f * size, 1.0f * size);
	for (int i = 0; i < 8; ++i) {
		glBegin(GL_POLYGON);
		glVertex3f(top[i][0], top[i][1], top[i][2]);
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(bottom[i][0], bottom[i][1], bottom[i][2]);
		glEnd();
	}
	glPopMatrix();
}

void kOctagonStrip(GLfloat distort = 0.0f) {
	GLfloat sf = 0.5;

	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i < 9; ++i) {
		float angle = i * (2 * pi / 8);
		float x = cos(angle);
		float z = sin(angle);
		glVertex3f(x, 0.0f, z);
		glPushMatrix();
		glTranslatef(0.0f, 0.5f, 0.0f);
		glVertex3f(x * sf, distort, z * sf);
		glPopMatrix();
	}
	glEnd();
	glPopMatrix();
}

void watchTowerRoof() {
	glPushMatrix();
		glTranslatef(0.0f, 1.0f, 0.0f);
		kOctagonPlane(0.3, 1.0f);
	glPopMatrix();

	glPushMatrix();
		 glTranslatef(0.0f, 0.5f, 0.0f);
		 glScalef(0.25f, 2.0f, 0.25f);
		 kOctagonStrip(0.25f);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0.0f, 0.25f, 0.0f);
		glScalef(0.5f, 1.0f, 0.5f);
		kOctagonStrip(0.25f);
	glPopMatrix();

	kOctagonStrip(0.25f);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	camera();
	lights();

	grid();

	glPushMatrix();
	//watchTowerRoof();

	Mesh cubeMesh;
	KCube::create(cubeMesh, 1.0);
	cubeMesh.create();

	glPopMatrix();

	glutSwapBuffers();
}

void reshape(int w, int h) {
	glViewport(0, 0, w, h);
	GLfloat aspect_ratio = h == 0 ? w / 1 : (GLfloat)w / (GLfloat)h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(120, aspect_ratio, 0.1f, 100.0f);
}

void keyboardSpecial(int key, int x, int y) {
	if (key == GLUT_KEY_UP)
		if (glutGetModifiers() == GLUT_ACTIVE_SHIFT) {
			camZ += 0.5;
		}
		else {
			camY += 0.5;
		}

	if (key == GLUT_KEY_DOWN)
		if (glutGetModifiers() == GLUT_ACTIVE_SHIFT) {
			camZ -= 0.5;
		}
		else {
			camY -= 0.5;
		}

	if (key == GLUT_KEY_LEFT)
		camX -= 0.5;

	if (key == GLUT_KEY_RIGHT)
		camX += 0.5;

	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {

	if (key == 'd')
		rotY -= 5.0;

	if (key == 'a')
		rotY += 1.0;

	if (key == 's')
		if (glutGetModifiers() == GLUT_ACTIVE_SHIFT) {
			rotZ -= 5.0;
		}
		else {
			rotX -= 5.0;
		}

	if (key == 'w')
		if (glutGetModifiers() == GLUT_ACTIVE_SHIFT) {
			rotZ += 5.0;
		}
		else {
			rotX += 5.0;
		}

	glutPostRedisplay();
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);

	glutInitWindowSize(window_width, window_height);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Mid Review");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	glutSpecialFunc(keyboardSpecial);
	glutKeyboardFunc(keyboard);

	init();
	glutMainLoop();

	return 0;

}