

#pragma once

#ifndef HEXAGON_WALK_PATH_H
#define HEXAGON_WALK_PATH_H

#include "Mesh.h"

class HexagonWalkPath {
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
		mesh.vertex({ 0.454f, -0.021f, -0.047f });
		mesh.vertex({ 0.240f, -0.029f, 0.366f });
		mesh.vertex({ -0.235f, 0.014f, 0.439f });
		mesh.vertex({ -0.454f, 0.049f, 0.049f });
		mesh.vertex({ 0.951f, 1.061f, -0.011f });
		mesh.vertex({ 0.518f, 1.064f, 0.827f });
		mesh.vertex({ -0.527f, 1.126f, 0.831f });
		mesh.vertex({ -0.976f, 1.116f, -0.036f });
		mesh.vertex({ 0.408f, 1.091f, -0.020f });
		mesh.vertex({ 0.265f, 1.120f, 0.412f });
		mesh.vertex({ -0.265f, 1.121f, 0.424f });
		mesh.vertex({ -0.448f, 1.164f, 0.038f });

	}

	static void faces(Mesh& mesh) {

		mesh.face({ {0, 4, 5, 1} });
		mesh.face({ {1, 5, 6, 2} });
		mesh.face({ {2, 6, 7, 3} });

		mesh.face({ {8, 12, 13, 9} });
		mesh.face({ {9, 13, 14, 10} });
		mesh.face({ {10, 14, 15, 11} });

		mesh.face({ {0, 8, 9, 1} });
		mesh.face({ {1, 9, 10, 2} });
		mesh.face({ {2, 10, 11, 3} });

		mesh.face({ {4, 5, 13, 12} });
		mesh.face({ {5, 6, 14, 13} });
		mesh.face({ {6, 7, 15, 14} });

		mesh.face({ {0, 4, 12, 8} });
		mesh.face({ {7, 3, 11, 15} });

	}

};

#endif
