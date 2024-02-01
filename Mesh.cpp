#include <iostream>
#include <math.h>

#include <GL/glut.h>
#include "Vertices.h"
#include "Mesh.h"

Mesh::Mesh() {}

Mesh::~Mesh() {}

void Mesh::vertex(Point3D v)
{
	vertices.push_back(v);
}


