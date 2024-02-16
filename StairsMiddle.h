
#pragma once

#ifndef STAIRS_MIDDLE_H
#define STAIRS_MIDDLE_H

#include "Mesh.h"

class StairsMiddle {
public:
	static Mesh init() {
		Mesh mesh;

		vertices(mesh);
		faces(mesh);

		return mesh;
	}

private:
	static void vertices(Mesh& mesh) {

		mesh.vertex({ -0.67f, -0.3f, 0.036f });
		mesh.vertex({ -0.622f, -0.3f, 0.036f });
		mesh.vertex({ -0.67f, 0.3f, 0.036f });
		mesh.vertex({ -0.622f, 0.3f, 0.036f });
		mesh.vertex({ -0.665f, -0.3f, -0.045f });
		mesh.vertex({ -0.622f, -0.3f, -0.027f });
		mesh.vertex({ -0.665f, 0.3f, -0.045f });
		mesh.vertex({ -0.622f, 0.3f, -0.027f });
		mesh.vertex({ 0.622f, -0.3f, 0.036f });
		mesh.vertex({ 0.67f, -0.3f, 0.036f });
		mesh.vertex({ 0.622f, 0.3f, 0.036f });
		mesh.vertex({ 0.67f, 0.3f, 0.036f });
		mesh.vertex({ 0.622f, -0.3f, -0.027f });
		mesh.vertex({ 0.665f, -0.3f, -0.045f });
		mesh.vertex({ 0.622f, 0.3f, -0.027f });
		mesh.vertex({ 0.665f, 0.3f, -0.045f });

	}

	static void faces(Mesh& mesh) {

		mesh.face({ {3, 1, 8, 10} });
		mesh.face({ {7, 14, 12, 5} });
		mesh.face({ {0, 4, 5, 1} });
		mesh.face({ {12, 8, 1, 5} });
		mesh.face({ {8, 12, 13, 9} });
		mesh.face({ {3, 7, 6, 2} });
		mesh.face({ {14, 7, 3, 10} });
		mesh.face({ {11, 15, 14, 10} });
		mesh.face({ {6, 4, 0, 2} });
		mesh.face({ {10, 8, 9, 11} });
		mesh.face({ {15, 13, 9, 11} });
		mesh.face({ {12, 14, 15, 13} });
		mesh.face({ {1, 3, 2, 0} });
		mesh.face({ {5, 4, 6, 7} });


	}

};

#endif
