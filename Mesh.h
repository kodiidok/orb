
#pragma once

#ifndef MESH_H
#define MESH_H

#include "Vertices.h"
#include <vector>

using namespace std;

struct Face {
	vector<int> vertices;
};

class Mesh
{
public:
	Mesh();
	~Mesh();

	void vertex(Point3D v);
	void face(Face f);

	const vector<Point3D>& getVertices() const {
		return vertices;
	}

	const vector<Face>& getFaces() const {
		return faces;
	}

private:
	vector<Point3D> vertices;
	vector<Face> faces;
	vector<Normal> normal;
};

#endif
