
#include <GL/glut.h>
#include "Vertices.h"
#include "Axes.h"

void axis(Point3D& p1, Point3D& p2, RGBcolor color) {
	glColor3f(color.r, color.g, color.b);
	glBegin(GL_LINES);
	glVertex3f(p1.x, p1.y, p1.z);
	glVertex3f(p2.x, p2.y, p2.z);
	glEnd();
}

void axes() {
	glEnable(GL_COLOR_MATERIAL);
	
	RGBcolor red = { 1.0f, 0.0f, 0.0f };
	RGBcolor blue = { 0.0f, 0.0f, 1.0f };
	RGBcolor green = { 0.0f, 1.0f, 0.0f };

	// x axis
	Point3D x1 = { 10.0f, 0.0f, 0.0f };
	Point3D x2 = { -10.0f, 0.0f, 0.0f };
	axis(x1, x2, red);

	// y axis
	Point3D y1 = { 0.0f, 10.0f, 0.0f };
	Point3D y2 = { 0.0f, -10.0f, 0.0f };
	axis(y1, y2, green);

	// z axis
	Point3D z1 = { 0.0f, 0.0f, 10.0f };
	Point3D z2 = { 0.0f, 0.0f, -10.0f };
	axis(z1, z2, blue);

	glDisable(GL_COLOR_MATERIAL);
}

void cell(int u, int v) {
	glBegin(GL_LINE_LOOP);
	glVertex2f(u - 0.5f, v - 0.5f);
	glVertex2f(u + 0.5f, v - 0.5f);
	glVertex2f(u + 0.5f, v + 0.5f);
	glVertex2f(u - 0.5f, v + 0.5f);
	glEnd();
}

void grid() {
	glEnable(GL_COLOR_MATERIAL);
	int u = 0, v = 0, m = 0, n = 0;

	glPushMatrix();
	glColor3f(0.3f, 0.3f, 0.3f);

	for (int i = 0; i < 10; i++) {

		u = 0, v = 0;

		for (int j = 0; j < 10; j++) {

			cell(u, m);

			if (v != u) {
				cell(v, m);
			}

			if (m != n) {
				cell(u, n);

				if (v != u) {
					cell(v, n);
				}
			}

			u++;
			v--;

		}

		m++;
		n--;

	}

	glPopMatrix();
	glDisable(GL_COLOR_MATERIAL);
}

void drawCartesianCoordinates() {
	glEnable(GL_COLOR_MATERIAL);
	// Set the line color
	glColor3f(0.3f, 0.3f, 0.3f);

	// Display tick marks on x-axis
	for (int i = -10; i <= 10; ++i) {
		glBegin(GL_LINES);
		glVertex2f(i, -0.2);
		glVertex2f(i, 0.2);
		glEnd();
	}

	// Display tick marks on y-axis
	for (int i = -10; i <= 10; ++i) {
		glBegin(GL_LINES);
		glVertex2f(-0.2, i);
		glVertex2f(0.2, i);
		glEnd();
	}

	// Display the axis labels
	glColor3f(0.5f, 0.5f, 0.5f);
	glRasterPos2f(10.2, 0.0);
	glutBitmapCharacter(GLUT_BITMAP_8_BY_13, 'X');
	glRasterPos2f(0.0, 10.2);
	glutBitmapCharacter(GLUT_BITMAP_8_BY_13, 'Y');
	
	glDisable(GL_COLOR_MATERIAL);
}
