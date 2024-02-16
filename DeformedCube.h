

#pragma once

#ifndef DEFORMED_CUBE_H
#define DEFORMED_CUBE_H

#include "Mesh.h"

class DeformedCube {
public:
	static Mesh init() {
		Mesh mesh;

		vertices(mesh);
		faces(mesh);

		return mesh;
	}

private:
	static void vertices(Mesh& mesh) {

		mesh.vertex({ -0.46f, 0.03f, -0.50f });
		mesh.vertex({ -0.19f, 0.00f, -0.50f });
		mesh.vertex({ 0.19f, -0.02f, -0.50f });
		mesh.vertex({ 0.50f, 0.04f, -0.49f });
		mesh.vertex({ -0.52f, 0.03f, -0.15f });
		mesh.vertex({ -0.19f, 0.04f, -0.12f });
		mesh.vertex({ 0.20f, 0.04f, -0.18f });
		mesh.vertex({ 0.52f, 0.04f, -0.15f });
		mesh.vertex({ -0.50f, -0.04f, 0.16f });
		mesh.vertex({ -0.15f, 0.04f, 0.21f });
		mesh.vertex({ 0.16f, 0.04f, 0.14f });
		mesh.vertex({ 0.53f, 0.00f, 0.12f });
		mesh.vertex({ -0.47f, -0.01f, 0.53f });
		mesh.vertex({ -0.15f, -0.05f, 0.49f });
		mesh.vertex({ 0.20f, -0.03f, 0.48f });
		mesh.vertex({ 0.53f, -0.03f, 0.50f });
		mesh.vertex({ -0.53f, 0.36f, -0.47f });
		mesh.vertex({ -0.19f, 0.33f, -0.50f });
		mesh.vertex({ 0.18f, 0.36f, -0.54f });
		mesh.vertex({ 0.45f, 0.36f, -0.50f });
		mesh.vertex({ -0.47f, 0.28f, -0.17f });
		mesh.vertex({ -0.14f, 0.30f, -0.12f });
		mesh.vertex({ 0.21f, 0.28f, -0.21f });
		mesh.vertex({ 0.50f, 0.37f, -0.18f });
		mesh.vertex({ -0.52f, 0.32f, 0.12f });
		mesh.vertex({ -0.19f, 0.32f, 0.16f });
		mesh.vertex({ 0.14f, 0.30f, 0.14f });
		mesh.vertex({ 0.49f, 0.31f, 0.12f });
		mesh.vertex({ -0.46f, 0.34f, 0.51f });
		mesh.vertex({ -0.20f, 0.38f, 0.53f });
		mesh.vertex({ 0.13f, 0.31f, 0.52f });
		mesh.vertex({ 0.52f, 0.37f, 0.49f });
		mesh.vertex({ -0.45f, 0.70f, -0.54f });
		mesh.vertex({ -0.21f, 0.69f, -0.47f });
		mesh.vertex({ 0.18f, 0.64f, -0.48f });
		mesh.vertex({ 0.51f, 0.67f, -0.53f });
		mesh.vertex({ -0.50f, 0.65f, -0.14f });
		mesh.vertex({ -0.12f, 0.70f, -0.16f });
		mesh.vertex({ 0.16f, 0.64f, -0.21f });
		mesh.vertex({ 0.45f, 0.66f, -0.18f });
		mesh.vertex({ -0.51f, 0.70f, 0.17f });
		mesh.vertex({ -0.16f, 0.63f, 0.12f });
		mesh.vertex({ 0.15f, 0.62f, 0.17f });
		mesh.vertex({ 0.54f, 0.68f, 0.13f });
		mesh.vertex({ -0.46f, 0.69f, 0.52f });
		mesh.vertex({ -0.12f, 0.69f, 0.52f });
		mesh.vertex({ 0.15f, 0.71f, 0.54f });
		mesh.vertex({ 0.46f, 0.69f, 0.52f });
		mesh.vertex({ -0.52f, 0.99f, -0.51f });
		mesh.vertex({ -0.15f, 1.00f, -0.54f });
		mesh.vertex({ 0.12f, 1.02f, -0.52f });
		mesh.vertex({ 0.47f, 1.04f, -0.50f });
		mesh.vertex({ -0.46f, 0.99f, -0.15f });
		mesh.vertex({ -0.20f, 1.00f, -0.13f });
		mesh.vertex({ 0.17f, 1.01f, -0.15f });
		mesh.vertex({ 0.45f, 1.02f, -0.16f });
		mesh.vertex({ -0.51f, 0.94f, 0.20f });
		mesh.vertex({ -0.17f, 1.01f, 0.20f });
		mesh.vertex({ 0.19f, 1.03f, 0.15f });
		mesh.vertex({ 0.53f, 0.98f, 0.21f });
		mesh.vertex({ -0.46f, 0.95f, 0.46f });
		mesh.vertex({ -0.19f, 1.04f, 0.49f });
		mesh.vertex({ 0.18f, 0.97f, 0.50f });
		mesh.vertex({ 0.48f, 0.98f, 0.50f });

	}

	static void faces(Mesh& mesh) {

		mesh.face({ {0, 1, 5, 4} });
		mesh.face({ {1, 2, 6, 5} });
		mesh.face({ {2, 3, 7, 6} });
		mesh.face({ {4, 5, 9, 8} });
		mesh.face({ {5, 6, 10, 9} });
		mesh.face({ {6, 7, 11, 10} });
		mesh.face({ {8, 9, 13, 12} });
		mesh.face({ {9, 10, 14, 13} });
		mesh.face({ {10, 11, 15, 14} });

		mesh.face({ {0, 16, 20, 4} });
		mesh.face({ {4, 20, 24, 8} });
		mesh.face({ {8, 24, 28, 12} });
		mesh.face({ {12, 28, 29, 13} });
		mesh.face({ {13, 29, 30, 14} });
		mesh.face({ {14, 30, 31, 15} });
		mesh.face({ {31, 27, 11, 15} });
		mesh.face({ {27, 23, 7, 11} });
		mesh.face({ {23, 19, 3, 7} });
		mesh.face({ {19, 18, 2, 3} });
		mesh.face({ {18, 17, 1, 2} });
		mesh.face({ {17, 16, 0, 1} });

		mesh.face({ {16, 32, 36, 20} });
		mesh.face({ {20, 36, 40, 24} });
		mesh.face({ {24, 40, 44, 28} });
		mesh.face({ {28, 44, 45, 29} });
		mesh.face({ {29, 45, 46, 30} });
		mesh.face({ {30, 46, 47, 31} });
		mesh.face({ {47, 43, 27, 31} });
		mesh.face({ {43, 39, 23, 27} });
		mesh.face({ {39, 35, 19, 23} });
		mesh.face({ {35, 34, 18, 19} });
		mesh.face({ {34, 33, 17, 18} });
		mesh.face({ {33, 32, 16, 17} });

		mesh.face({ {32, 48, 52, 36} });
		mesh.face({ {36, 52, 56, 40} });
		mesh.face({ {40, 56, 60, 44} });
		mesh.face({ {44, 60, 61, 45} });
		mesh.face({ {45, 61, 62, 46} });
		mesh.face({ {46, 62, 63, 47} });
		mesh.face({ {63, 59, 43, 47} });
		mesh.face({ {59, 55, 39, 43} });
		mesh.face({ {55, 51, 35, 39} });
		mesh.face({ {51, 50, 34, 35} });
		mesh.face({ {50, 49, 33, 34} });
		mesh.face({ {49, 48, 32, 33} });

		mesh.face({ {48, 49, 53, 52} });
		mesh.face({ {49, 50, 54, 53} });
		mesh.face({ {50, 51, 55, 54} });
		mesh.face({ {52, 53, 57, 56} });
		mesh.face({ {53, 54, 58, 57} });
		mesh.face({ {54, 55, 59, 58} });
		mesh.face({ {56, 57, 61, 60} });
		mesh.face({ {57, 58, 62, 61} });
		mesh.face({ {58, 59, 63, 62} });

	}

};

#endif
