
#ifndef MESH_H
#define MESH_H

#include <vector>

class Mesh
{
public:
	Mesh();
	~Mesh();

	void vertex(float x, float y, float z);
	void face(int v1, int v2, int v3, int v4);
	void create();
	void calculateNormals();

private:
	std::vector<float> vertices;
	std::vector<int> faces;
	std::vector<float> normals;
};

#endif
