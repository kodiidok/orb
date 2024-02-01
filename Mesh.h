
#pragma once

#ifndef MESH_H
#define MESH_H

#include <vector>
#include "Vertices.h"

using namespace std;

class Mesh
{
public:
	Mesh();
	~Mesh();

	void vertex(Point3D v);

	const vector<Point3D>& getVertices() const {
		return vertices;
	}

private:
	vector<Point3D> vertices;
};

#endif
