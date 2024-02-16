

#pragma once

#ifndef HEXAGON_BASE_H
#define HEXAGON_BASE_H

#include "Mesh.h"

class HexagonBase {
public:
	static Mesh init() {
		Mesh mesh;

		vertices(mesh);
		faces(mesh);

		return mesh;
	}

private:
	static void vertices(Mesh& mesh) {

		mesh.vertex({ 0.913f, -0.047f, -0.020f });
		mesh.vertex({ 0.425f, 0.024f, 0.795f });
		mesh.vertex({ -0.415f, -0.041f, 0.772f });
		mesh.vertex({ -0.942f, -0.028f, 0.000f });
		mesh.vertex({ -0.493f, -0.030f, -0.766f });
		mesh.vertex({ 0.454f, -0.028f, -0.771f });
		mesh.vertex({ 0.954f, 0.200f, -0.036f });
		mesh.vertex({ 0.496f, 0.197f, 0.895f });
		mesh.vertex({ -0.505f, 0.180f, 0.818f });
		mesh.vertex({ -1.007f, 0.167f, 0.035f });
		mesh.vertex({ -0.495f, 0.206f, -0.873f });
		mesh.vertex({ 0.468f, 0.215f, -0.834f });
		mesh.vertex({ 0.991f, 0.784f, 0.036f });
		mesh.vertex({ 0.468f, 0.753f, 0.819f });
		mesh.vertex({ -0.538f, 0.731f, 0.832f });
		mesh.vertex({ -0.999f, 0.829f, 0.019f });
		mesh.vertex({ -0.512f, 0.771f, -0.847f });
		mesh.vertex({ 0.483f, 0.737f, -0.832f });
		mesh.vertex({ 0.831f, 0.959f, -0.036f });
		mesh.vertex({ 0.411f, 0.917f, 0.695f });
		mesh.vertex({ -0.443f, 0.922f, 0.720f });
		mesh.vertex({ -0.829f, 0.914f, 0.011f });
		mesh.vertex({ -0.456f, 0.990f, -0.716f });
		mesh.vertex({ 0.400f, 0.995f, -0.718f });
		mesh.vertex({ 0.862f, 1.250f, 0.007f });
		mesh.vertex({ 0.445f, 1.233f, 0.720f });
		mesh.vertex({ -0.408f, 1.305f, 0.680f });
		mesh.vertex({ -0.866f, 1.242f, 0.027f });
		mesh.vertex({ -0.387f, 1.224f, -0.684f });
		mesh.vertex({ 0.417f, 1.307f, -0.683f });
		mesh.vertex({ 0.887f, 1.433f, -0.004f });
		mesh.vertex({ 0.436f, 1.441f, 0.770f });
		mesh.vertex({ -0.491f, 1.432f, 0.737f });
		mesh.vertex({ -0.936f, 1.416f, 0.042f });
		mesh.vertex({ -0.452f, 1.445f, -0.742f });
		mesh.vertex({ 0.486f, 1.447f, -0.804f });
		mesh.vertex({ 0.955f, 1.823f, 0.020f });
		mesh.vertex({ 0.456f, 1.904f, 0.794f });
		mesh.vertex({ -0.450f, 1.827f, 0.867f });
		mesh.vertex({ -0.915f, 1.821f, 0.014f });
		mesh.vertex({ -0.502f, 1.861f, -0.789f });
		mesh.vertex({ 0.442f, 1.832f, -0.863f });
		mesh.vertex({ 0.861f, 1.971f, -0.035f });
		mesh.vertex({ 0.473f, 1.981f, 0.739f });
		mesh.vertex({ -0.491f, 2.004f, 0.748f });
		mesh.vertex({ -0.879f, 1.993f, 0.000f });
		mesh.vertex({ -0.418f, 1.990f, -0.773f });
		mesh.vertex({ 0.441f, 1.955f, -0.812f });

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
