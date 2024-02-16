

#pragma once

#ifndef HOLLOW_HEXAGON_H
#define HOLLOW_HEXAGON_H

#include "Mesh.h"

class HollowHexagon {
public:
	static Mesh init() {
		Mesh mesh;

		vertices(mesh);
		faces(mesh);

		return mesh;
	}

private:
	static void vertices(Mesh& mesh) {

		mesh.vertex({ 1.005f, -0.015f, 0.034f });
		mesh.vertex({ 0.479f, 0.001f, 0.850f });
		mesh.vertex({ -0.508f, 0.047f, 0.826f });
		mesh.vertex({ -1.006f, -0.028f, -0.015f });
		mesh.vertex({ -0.450f, -0.017f, -0.855f });
		mesh.vertex({ 0.492f, 0.023f, -0.871f });
		mesh.vertex({ 0.604f, -0.021f, -0.047f });
		mesh.vertex({ 0.315f, -0.029f, 0.496f });
		mesh.vertex({ -0.310f, 0.014f, 0.569f });
		mesh.vertex({ -0.604f, 0.049f, 0.049f });
		mesh.vertex({ -0.326f, -0.043f, -0.554f });
		mesh.vertex({ 0.334f, 0.010f, -0.478f });
		mesh.vertex({ 0.951f, 1.061f, -0.011f });
		mesh.vertex({ 0.518f, 1.064f, 0.827f });
		mesh.vertex({ -0.527f, 1.126f, 0.831f });
		mesh.vertex({ -0.976f, 1.116f, -0.036f });
		mesh.vertex({ -0.496f, 1.095f, -0.875f });
		mesh.vertex({ 0.550f, 1.059f, -0.914f });
		mesh.vertex({ 0.558f, 1.091f, -0.020f });
		mesh.vertex({ 0.340f, 1.120f, 0.542f });
		mesh.vertex({ -0.340f, 1.121f, 0.554f });
		mesh.vertex({ -0.598f, 1.164f, 0.038f });
		mesh.vertex({ -0.313f, 1.070f, -0.494f });
		mesh.vertex({ 0.263f, 1.071f, -0.497f });

	}

	static void faces(Mesh& mesh) {

		mesh.face({ {0, 1, 7, 6} });
		mesh.face({ {1, 2, 8, 7} });
		mesh.face({ {2, 3, 9, 8} });
		mesh.face({ {3, 4, 10, 9} });
		mesh.face({ {4, 5, 11, 10} });
		mesh.face({ {5, 0, 6, 11} });

		mesh.face({ {12, 13, 19, 18} });
		mesh.face({ {13, 14, 20, 19} });
		mesh.face({ {14, 15, 21, 20} });
		mesh.face({ {15, 16, 22, 21} });
		mesh.face({ {16, 17, 23, 22} });
		mesh.face({ {17, 12, 18, 23} });

		mesh.face({ {0, 5, 17, 12} });
		mesh.face({ {5, 4, 16, 17} });
		mesh.face({ {4, 3, 15, 16} });
		mesh.face({ {3, 2, 14, 15} });
		mesh.face({ {2, 1, 13, 14} });
		mesh.face({ {1, 0, 12, 13} });

		mesh.face({ {6, 11, 23, 18} });
		mesh.face({ {11, 10, 22, 23} });
		mesh.face({ {10, 9, 21, 22} });
		mesh.face({ {9, 8, 20, 21} });
		mesh.face({ {8, 7, 19, 20} });
		mesh.face({ {7, 6, 18, 19} });

	}

};

#endif
