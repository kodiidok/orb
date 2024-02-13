#pragma once

#ifndef AXES_H
#define AXES_H

#include <GL/glut.h>
#include "Colors.h"
#include "Vertices.h"

void axis(Point3D& p1, Point3D& p2, RGBcolor color);
void axes();
void drawCartesianCoordinates();
void cell(int u, int v);
void grid();

#endif // !AXES_H
