#pragma once

#ifndef CASTLE_H
#define CASTLE_H

#include <vector>

using namespace std;

void hexagon(float centerX, float centerZ, float sideLength, int flipNorm);
vector<Point3D> hexagonStrip(float centerX, float centerZ, float radius, float height, int flipNorm);
void hexagonBlock(float centerX, float centerZ, float radius, float height, float innerRadius);
void arch(float centerX, float centerY, float width, float height);
void initRandomRotations(int numBlocks);
vector<Point3D> circle(float centerx, float centery, float z, float radius, int segments);
vector<Point3D> drawCircle(GLenum mode, float centerx, float centery, float z, float radius, int segments);
vector<Point3D> semiCircle(float centerx, float centery, float z, float radius, int segments);
vector<Point3D> drawSemiCircle(GLenum mode, float centerx, float centery, float z, float radius, int segments);
vector<Point3D> wallPanelOpenArch(float w, float h, float cx, float cy, float cz, float radius, int segments);
vector<vector<Point3D>> hexagonWallPanelAllOpenArch(float w, float h, float cx, float cy, float cz, float radius, int segments, int flipNorm);
void hexagonWallRingAllOpenArch(float w, float h, float cx, float cy, float cz, float radius, int segments, float thickness);
vector<Point3D> openArch(float h, float cx, float cy, float cz, float radius, int segments, float thickness);
vector<vector<Point3D>> hexagonOpenArch(float h, float cx, float cy, float cz, float radius, int segments, float thickness, float d);
void hexagonFloor(float cx, float cz, float sideLength);
void tower3(float scale);

#endif