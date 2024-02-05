
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
	glShadeModel(GL_SMOOTH);
}

void camera() {

	float eyex = 2.0f, eyey = 2.0f, eyez = 2.0f;
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

void scene() {
	glPushMatrix();
	glEnable(GL_NORMALIZE);

	addMaterial(WHITE_MATTE);
	
	//Cube cube;
	//cube.draw();

	//hexagon(0, 0, 1);

	hexagonBlock(0, 0, 1, 1, 0.95);

	glDisable(GL_NORMALIZE);
	glPopMatrix();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	camera();
	lights();

	axes();
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