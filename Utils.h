#pragma once

#ifndef UTILS_H
#define UTILS_H

#include "Mesh.h"

float generateRandomAngle();
void calculateNormal(const Point3D& p1, const Point3D& p2, const Point3D& p3, float& normalX, float& normalY, float& normalZ);
void drawLabel(string text, float x, float y, float z);

#endif