
#pragma once

#ifndef HEXAGON_BLOCK_H
#define HEXAGON_BLOCK_H

#include "Mesh.h"

class HexagonBlock {
public:
	static Mesh init() {
		Mesh mesh;

		vertices(mesh);
		faces(mesh);

		return mesh;
	}

private:
	static void vertices(Mesh& mesh) {

		mesh.vertex({ 0.902f, 0.010f, 0.009f });
		mesh.vertex({ 0.463f, -0.009f, 0.796f });
		mesh.vertex({ -0.448f, 0.010f, 0.789f });
		mesh.vertex({ -0.885f, -0.009f, -0.005f });
		mesh.vertex({ -0.442f, 0.003f, -0.770f });
		mesh.vertex({ 0.445f, 0.018f, -0.797f });
		mesh.vertex({ 0.993f, 0.199f, 0.018f });
		mesh.vertex({ 0.517f, 0.192f, 0.881f });
		mesh.vertex({ -0.520f, 0.185f, 0.856f });
		mesh.vertex({ -0.991f, 0.177f, 0.002f });
		mesh.vertex({ -0.498f, 0.183f, -0.853f });
		mesh.vertex({ 0.519f, 0.174f, -0.854f });
		mesh.vertex({ 1.007f, 0.764f, 0.005f });
		mesh.vertex({ 0.514f, 0.793f, 0.867f });
		mesh.vertex({ -0.495f, 0.775f, 0.867f });
		mesh.vertex({ -1.016f, 0.787f, 0.004f });
		mesh.vertex({ -0.509f, 0.775f, -0.857f });
		mesh.vertex({ 0.498f, 0.798f, -0.847f });
		mesh.vertex({ 0.975f, 0.957f, 0.009f });
		mesh.vertex({ 0.468f, 0.968f, 0.835f });
		mesh.vertex({ -0.481f, 0.947f, 0.834f });
		mesh.vertex({ -0.979f, 0.953f, 0.009f });
		mesh.vertex({ -0.486f, 0.979f, -0.837f });
		mesh.vertex({ 0.474f, 0.965f, -0.839f });
		mesh.vertex({ 0.919f, 1.255f, -0.011f });
		mesh.vertex({ 0.461f, 1.263f, 0.811f });
		mesh.vertex({ -0.474f, 1.254f, 0.793f });
		mesh.vertex({ -0.918f, 1.252f, 0.014f });
		mesh.vertex({ -0.481f, 1.240f, -0.808f });
		mesh.vertex({ 0.462f, 1.270f, -0.792f });
		mesh.vertex({ 0.968f, 1.455f, -0.018f });
		mesh.vertex({ 0.477f, 1.458f, 0.846f });
		mesh.vertex({ -0.499f, 1.434f, 0.855f });
		mesh.vertex({ -0.972f, 1.421f, 0.015f });
		mesh.vertex({ -0.499f, 1.446f, -0.835f });
		mesh.vertex({ 0.483f, 1.458f, -0.853f });
		mesh.vertex({ 0.945f, 1.849f, -0.013f });
		mesh.vertex({ 0.491f, 1.863f, 0.830f });
		mesh.vertex({ -0.473f, 1.855f, 0.832f });
		mesh.vertex({ -0.947f, 1.871f, 0.006f });
		mesh.vertex({ -0.462f, 1.858f, -0.836f });
		mesh.vertex({ 0.462f, 1.869f, -0.835f });
		mesh.vertex({ 0.101f, 1.961f, -0.001f });
		mesh.vertex({ 0.049f, 1.989f, 0.087f });
		mesh.vertex({ -0.048f, 1.963f, 0.086f });
		mesh.vertex({ -0.102f, 1.969f, 0.000f });
		mesh.vertex({ -0.052f, 1.968f, -0.086f });
		mesh.vertex({ 0.050f, 1.969f, -0.086f });

	}

	static void faces(Mesh& mesh) {

		mesh.face({ {0, 1, 2, 3, 4, 5} });

		mesh.face({ {0, 5, 11, 6} });
		mesh.face({ {5, 4, 10, 11} });
		mesh.face({ {4, 3, 9, 10} });
		mesh.face({ {3, 2, 8, 9} });
		mesh.face({ {1, 2, 8, 7} });
		mesh.face({ {0, 1, 7, 6} });

		mesh.face({ {6, 11, 17, 12} });
		mesh.face({ {11, 10, 16, 17} });
		mesh.face({ {10, 9, 15, 16} });
		mesh.face({ {9, 8, 14, 15} });
		mesh.face({ {7, 8, 14, 13} });
		mesh.face({ {6, 7, 13, 12} });

		mesh.face({ {12, 17, 23, 18} });
		mesh.face({ {17, 16, 22, 23} });
		mesh.face({ {16, 15, 21, 22} });
		mesh.face({ {15, 14, 20, 21} });
		mesh.face({ {13, 14, 20, 19} });
		mesh.face({ {12, 13, 19, 18} });

		mesh.face({ {18, 23, 29, 24} });
		mesh.face({ {23, 22, 28, 29} });
		mesh.face({ {22, 21, 27, 28} });
		mesh.face({ {21, 20, 26, 27} });
		mesh.face({ {19, 20, 26, 25} });
		mesh.face({ {18, 19, 25, 24} });

		mesh.face({ {24, 29, 35, 30} });
		mesh.face({ {29, 28, 34, 35} });
		mesh.face({ {28, 27, 33, 34} });
		mesh.face({ {27, 26, 32, 33} });
		mesh.face({ {25, 26, 32, 31} });
		mesh.face({ {24, 25, 31, 30} });

		mesh.face({ {30, 35, 41, 36} });
		mesh.face({ {35, 34, 40, 41} });
		mesh.face({ {34, 33, 39, 40} });
		mesh.face({ {33, 32, 38, 39} });
		mesh.face({ {31, 32, 38, 37} });
		mesh.face({ {30, 31, 37, 36} });

		mesh.face({ {36, 41, 47, 42} });
		mesh.face({ {41, 40, 46, 47} });
		mesh.face({ {40, 39, 45, 46} });
		mesh.face({ {39, 38, 44, 45} });
		mesh.face({ {37, 38, 44, 43} });
		mesh.face({ {36, 37, 43, 42} });

		mesh.face({ {42, 43, 44, 45, 46, 47} });

	}

};

#endif
