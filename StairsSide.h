
#pragma once

#ifndef STAIRS_SIDE_H
#define STAIRS_SIDE_H

#include "Mesh.h"

class StairsSide {
public:
	static Mesh init() {
		Mesh mesh;

		vertices(mesh);
		faces(mesh);

		return mesh;
	}

private:
	static void vertices(Mesh& mesh) {

		mesh.vertex({ -0.196f, -0.303f, 0.069f });
		mesh.vertex({ -0.199f, -0.305f, 0.058f });
		mesh.vertex({ 0.096f, -0.304f, 0.068f });
		mesh.vertex({ 0.098f, -0.303f, 0.06f });
		mesh.vertex({ 0.099f, -0.297f, 0.064f });
		mesh.vertex({ 0.1f, -0.299f, 0.057f });
		mesh.vertex({ -0.196f, 0.304f, 0.069f });
		mesh.vertex({ -0.199f, 0.305f, 0.058f });
		mesh.vertex({ 0.096f, 0.304f, 0.068f });
		mesh.vertex({ 0.097f, 0.304f, 0.059f });
		mesh.vertex({ 0.099f, 0.297f, 0.064f });
		mesh.vertex({ 0.099f, 0.296f, 0.058f });
		mesh.vertex({ -0.199f, -0.305f, -0.063f });
		mesh.vertex({ -0.196f, -0.303f, -0.075f });
		mesh.vertex({ 0.101f, -0.304f, -0.047f });
		mesh.vertex({ 0.096f, -0.304f, -0.074f });
		mesh.vertex({ 0.102f, -0.298f, -0.048f });
		mesh.vertex({ 0.099f, -0.297f, -0.069f });
		mesh.vertex({ -0.199f, 0.305f, -0.063f });
		mesh.vertex({ -0.196f, 0.304f, -0.075f });
		mesh.vertex({ 0.1f, 0.304f, -0.047f });
		mesh.vertex({ 0.096f, 0.304f, -0.074f });
		mesh.vertex({ 0.102f, 0.299f, -0.048f });
		mesh.vertex({ 0.099f, 0.297f, -0.069f });

	}

	static void faces(Mesh& mesh) {

		mesh.face({ {3, 2, 0, 1} });
		mesh.face({ {2, 3, 5, 4} });
		mesh.face({ {6, 7, 1, 0} });
		mesh.face({ {10, 11, 9, 8} });
		mesh.face({ {5, 11, 10, 4} });
		mesh.face({ {6, 0, 2, 4, 10, 8} });
		mesh.face({ {15, 14, 12, 13} });
		mesh.face({ {14, 15, 17, 16} });
		mesh.face({ {18, 19, 13, 12} });
		mesh.face({ {9, 7, 6, 8} });
		mesh.face({ {21, 19, 18, 20} });
		mesh.face({ {21, 15, 13, 19} });
		mesh.face({ {17, 15, 21, 23} });
		mesh.face({ {22, 23, 21, 20} });
		mesh.face({ {17, 23, 22, 16} });
		mesh.face({ {14, 3, 1, 12} });
		mesh.face({ {3, 14, 16, 5} });
		mesh.face({ {7, 18, 12, 1} });
		mesh.face({ {20, 18, 7, 9} });
		mesh.face({ {11, 22, 20, 9} });
		mesh.face({ {22, 11, 5, 16} });


	}

};

#endif
