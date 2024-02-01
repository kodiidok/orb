
#include <GL/glut.h>
#include "Colors.h"
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
