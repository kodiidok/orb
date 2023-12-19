
#include <iostream>
#include "KOctagon.h"

#define PI 3.14159265358979323846

KOctagon::KOctagon() {}

KOctagon::~KOctagon() {}

void KOctagon::createFlatRing(Mesh& mesh, float scale_factor, float distortion = 0.0f) {

	for (int i = 0; i < 9; ++i) {
		float angle = i * (2 * PI / 8);
		float x = cos(angle);
		float z = sin(angle);
		mesh.vertex(x, 0.0f, z);
		mesh.vertex(x * scale_factor, 0.0f + distortion, z * scale_factor);
	}

	std::vector<float> vertices = mesh.getVertices();

	//std::cout << "Vertices vector array:" << std::endl;

	//for (size_t i = 0; i < vertices.size(); i += 3) {
	//	std::cout << "Vertex " << i / 3 << ": (" << vertices[i] << ", " << vertices[i + 1] << ", " << vertices[i + 2] << ")" << std::endl;
	//}

	//std::cout << "Length of vertices vector array: " << vertices.size() << std::endl;

	for (size_t i = 0; i < 16; i += 2) {
		mesh.face(i, i + 1, i + 3, i + 2);
	}
}
