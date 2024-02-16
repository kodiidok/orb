
#pragma once

#ifndef WALL_LEDGE_H
#define WALL_LEDGE_H

#include "Mesh.h"

class WallLedge {
public:
	static Mesh init() {
		Mesh mesh;

		vertices(mesh);
		faces(mesh);

		return mesh;
	}

private:
	static void vertices(Mesh& mesh) {

		mesh.vertex({ 0.089f, -0.732f, 0.09f });
		mesh.vertex({ 0.885f, -0.921f, 0.149f });
		mesh.vertex({ 0.885f, -0.732f, 0.09f });
		mesh.vertex({ 0.089f, -0.732f, -0.119f });
		mesh.vertex({ 0.089f, -0.921f, 0.149f });
		mesh.vertex({ 0.089f, -0.921f, -0.119f });
		mesh.vertex({ 0.885f, -0.921f, -0.119f });
		mesh.vertex({ 0.885f, -0.732f, -0.119f });
		mesh.vertex({ -0.089f, -0.921f, 0.149f });
		mesh.vertex({ -0.885f, -0.732f, -0.119f });
		mesh.vertex({ -0.885f, -0.921f, -0.119f });
		mesh.vertex({ -0.885f, -0.921f, 0.149f });
		mesh.vertex({ -0.089f, -0.921f, -0.119f });
		mesh.vertex({ -0.089f, -0.732f, -0.119f });
		mesh.vertex({ -0.885f, -0.732f, 0.09f });
		mesh.vertex({ -0.089f, -0.732f, 0.09f });
		mesh.vertex({ 0.089f, 0.732f, 0.09f });
		mesh.vertex({ 0.885f, 0.732f, 0.09f });
		mesh.vertex({ 0.089f, 0.732f, -0.119f });
		mesh.vertex({ 0.089f, 0.921f, 0.149f });
		mesh.vertex({ 0.089f, 0.921f, -0.119f });
		mesh.vertex({ 0.885f, 0.921f, 0.149f });
		mesh.vertex({ 0.885f, 0.921f, -0.119f });
		mesh.vertex({ 0.885f, 0.732f, -0.119f });
		mesh.vertex({ -0.885f, 0.732f, 0.09f });
		mesh.vertex({ -0.089f, 0.921f, 0.149f });
		mesh.vertex({ -0.885f, 0.921f, 0.149f });
		mesh.vertex({ -0.885f, 0.921f, -0.119f });
		mesh.vertex({ -0.089f, 0.921f, -0.119f });
		mesh.vertex({ -0.089f, 0.732f, 0.09f });
		mesh.vertex({ -0.089f, 0.732f, -0.119f });
		mesh.vertex({ -0.885f, 0.732f, -0.119f });


	}

	static void faces(Mesh& mesh) {

		mesh.face({ {1, 4, 5, 6} });
		mesh.face({ {29, 30, 28, 25} });
		mesh.face({ {8, 11, 10, 12} });
		mesh.face({ {15, 8, 12, 13} });
		mesh.face({ {13, 9, 14, 15} });
		mesh.face({ {24, 31, 30, 29} });
		mesh.face({ {4, 0, 3, 5} });
		mesh.face({ {25, 28, 27, 26} });
		mesh.face({ {11, 14, 9, 10} });
		mesh.face({ {8, 15, 14, 11} });
		mesh.face({ {24, 29, 25, 26} });
		mesh.face({ {26, 27, 31, 24} });
		mesh.face({ {16, 18, 23, 17} });
		mesh.face({ {19, 20, 18, 16} });
		mesh.face({ {0, 2, 7, 3} });
		mesh.face({ {2, 1, 6, 7} });
		mesh.face({ {21, 19, 16, 17} });
		mesh.face({ {17, 23, 22, 21} });
		mesh.face({ {0, 4, 1, 2} });
		mesh.face({ {20, 19, 21, 22} });



	}

};

#endif
