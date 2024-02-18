

#pragma once

#ifndef ROOF_H
#define ROOF_H

#include "Mesh.h"

class Roof {
public:
	static Mesh init() {
		Mesh mesh;

		vertices(mesh);
		faces(mesh);

		return mesh;
	}

private:
	static void vertices(Mesh& mesh) {

		mesh.vertex({ -0.15f, -2.521f, 0.15f });
		mesh.vertex({ 1.422f, 2.164f, 1.422f });
		mesh.vertex({ -1.421f, 1.217f, 1.422f });
		mesh.vertex({ 0.0f, 2.164f, 2.011f });
		mesh.vertex({ -1.421f, 2.164f, 1.422f });
		mesh.vertex({ -2.01f, 2.164f, 0.0f });
		mesh.vertex({ -1.421f, 1.217f, -1.421f });
		mesh.vertex({ -2.01f, 1.217f, 0.0f });
		mesh.vertex({ -1.421f, 2.164f, -1.421f });
		mesh.vertex({ 0.0f, 1.217f, -2.01f });
		mesh.vertex({ 0.0f, 2.164f, -2.01f });
		mesh.vertex({ 1.422f, 2.164f, -1.421f });
		mesh.vertex({ 1.422f, 1.217f, -1.421f });
		mesh.vertex({ 1.422f, 1.217f, 1.422f });
		mesh.vertex({ 2.011f, 1.217f, 0.0f });
		mesh.vertex({ 2.01f, 2.164f, 0.0f });
		mesh.vertex({ 0.0f, 1.217f, 2.708f });
		mesh.vertex({ 0.0f, 1.217f, 2.011f });
		mesh.vertex({ 2.707f, 1.217f, 0.0f });
		mesh.vertex({ 1.915f, 1.217f, 1.915f });
		mesh.vertex({ 0.0f, 1.217f, -2.707f });
		mesh.vertex({ -1.914f, 1.217f, -1.914f });
		mesh.vertex({ -1.01f, -0.678f, 0.0f });
		mesh.vertex({ -0.456f, -1.682f, 0.0f });
		mesh.vertex({ -0.323f, -1.682f, -0.322f });
		mesh.vertex({ 0.0f, -1.682f, -0.456f });
		mesh.vertex({ -0.714f, -0.678f, -0.714f });
		mesh.vertex({ 0.0f, -0.678f, -1.01f });
		mesh.vertex({ 0.0f, 0.284f, -1.732f });
		mesh.vertex({ 0.456f, -1.682f, 0.0f });
		mesh.vertex({ 0.323f, -1.682f, -0.322f });
		mesh.vertex({ 1.732f, 0.284f, 0.0f });
		mesh.vertex({ 1.01f, -0.678f, 0.0f });
		mesh.vertex({ 0.714f, -0.678f, -0.714f });
		mesh.vertex({ 0.0f, -0.678f, 1.01f });
		mesh.vertex({ 0.714f, -0.678f, 0.714f });
		mesh.vertex({ -0.323f, -1.682f, 0.323f });
		mesh.vertex({ -1.225f, 0.284f, 1.225f });
		mesh.vertex({ -0.714f, -0.678f, 0.714f });
		mesh.vertex({ 1.915f, 1.217f, -1.914f });
		mesh.vertex({ -1.732f, 0.284f, 0.0f });
		mesh.vertex({ -1.225f, 0.284f, -1.224f });
		mesh.vertex({ 1.225f, 0.284f, -1.224f });
		mesh.vertex({ 1.225f, 0.284f, 1.225f });
		mesh.vertex({ 0.0f, 0.284f, 1.732f });
		mesh.vertex({ -2.707f, 1.217f, 0.0f });
		mesh.vertex({ -1.914f, 1.217f, 1.915f });
		mesh.vertex({ -0.15f, -2.521f, -0.149f });
		mesh.vertex({ 0.323f, -1.682f, 0.323f });
		mesh.vertex({ 0.0f, -1.682f, 0.456f });
		mesh.vertex({ 0.15f, -2.521f, -0.149f });
		mesh.vertex({ 0.15f, -2.521f, 0.15f });
		mesh.vertex({ -0.006f, -2.521f, -0.149f });
		mesh.vertex({ 0.15f, -2.521f, -0.003f });
		mesh.vertex({ 0.0f, -2.521f, 0.15f });
		mesh.vertex({ -0.15f, -2.521f, -0.009f });


	}

	static void faces(Mesh& mesh) {

		mesh.face({ {3, 4, 2, 17} });
		mesh.face({ {8, 10, 9, 6} });
		mesh.face({ {11, 15, 14, 12} });
		mesh.face({ {4, 5, 7, 2} });
		mesh.face({ {15, 1, 13, 14} });
		mesh.face({ {5, 8, 6, 7} });
		mesh.face({ {6, 21, 45, 7} });
		mesh.face({ {2, 46, 16, 17} });
		mesh.face({ {14, 18, 39, 12} });
		mesh.face({ {17, 16, 19, 13} });
		mesh.face({ {7, 45, 46, 2} });
		mesh.face({ {9, 20, 21, 6} });
		mesh.face({ {13, 19, 18, 14} });
		mesh.face({ {41, 21, 20, 28} });
		mesh.face({ {36, 38, 22, 23} });
		mesh.face({ {48, 35, 34, 49} });
		mesh.face({ {42, 33, 27, 28} });
		mesh.face({ {24, 26, 27, 25} });
		mesh.face({ {43, 35, 32, 31} });
		mesh.face({ {35, 48, 29, 32} });
		mesh.face({ {35, 43, 44, 34} });
		mesh.face({ {37, 38, 34, 44} });
		mesh.face({ {38, 36, 49, 34} });
		mesh.face({ {38, 37, 40, 22} });
		mesh.face({ {26, 24, 23, 22} });
		mesh.face({ {33, 42, 31, 32} });
		mesh.face({ {30, 33, 32, 29} });
		mesh.face({ {41, 26, 22, 40} });
		mesh.face({ {46, 37, 44, 16} });
		mesh.face({ {39, 42, 28, 20} });
		mesh.face({ {37, 46, 45, 40} });
		mesh.face({ {19, 43, 31, 18} });
		mesh.face({ {21, 41, 40, 45} });
		mesh.face({ {42, 39, 18, 31} });
		mesh.face({ {43, 19, 16, 44} });
		mesh.face({ {12, 39, 20, 9} });
		mesh.face({ {50, 52, 25, 30} });
		mesh.face({ {49, 54, 51, 48} });
		mesh.face({ {23, 55, 0, 36} });
		mesh.face({ {55, 23, 24, 47} });
		mesh.face({ {10, 11, 12, 9} });
		mesh.face({ {26, 41, 28, 27} });
		mesh.face({ {33, 30, 25, 27} });
		mesh.face({ {1, 3, 17, 13} });
		mesh.face({ {29, 53, 50, 30} });
		mesh.face({ {52, 47, 24, 25} });
		mesh.face({ {53, 29, 48, 51} });
		mesh.face({ {54, 49, 36, 0} });


	}

};

#endif
