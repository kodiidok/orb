
#pragma once

#ifndef ROCK4_H
#define ROCK4_H

#include "Mesh.h"

class Rock4 {
public:
	static Mesh init() {
		Mesh mesh;

		vertices(mesh);
		faces(mesh);

		return mesh;
	}

private:
	static void vertices(Mesh& mesh) {

		mesh.vertex({ -0.562f, -0.296f, -0.131f });
		mesh.vertex({ -0.788f, -0.018f, -0.185f });
		mesh.vertex({ -0.305f, -0.547f, -0.127f });
		mesh.vertex({ -0.15f, -0.609f, -0.191f });
		mesh.vertex({ -0.447f, -0.184f, -0.324f });
		mesh.vertex({ -0.542f, -0.279f, 0.185f });
		mesh.vertex({ -0.72f, -0.203f, -0.078f });
		mesh.vertex({ -0.3f, -0.547f, 0.21f });
		mesh.vertex({ -0.139f, -0.85f, 0.031f });
		mesh.vertex({ -0.046f, -0.525f, 0.414f });
		mesh.vertex({ -0.479f, -0.468f, -0.049f });
		mesh.vertex({ -0.407f, -0.363f, 0.331f });
		mesh.vertex({ -0.269f, -0.498f, 0.376f });
		mesh.vertex({ -0.192f, -0.136f, 0.393f });
		mesh.vertex({ -0.693f, 0.42f, -0.309f });
		mesh.vertex({ -0.679f, 0.582f, -0.225f });
		mesh.vertex({ -0.403f, 0.372f, -0.265f });
		mesh.vertex({ -0.269f, 0.063f, -0.354f });
		mesh.vertex({ -0.135f, 0.376f, -0.439f });
		mesh.vertex({ -0.328f, 0.71f, -0.419f });
		mesh.vertex({ -0.392f, 0.701f, -0.232f });
		mesh.vertex({ -0.154f, 0.804f, -0.346f });
		mesh.vertex({ -0.087f, 0.857f, -0.192f });
		mesh.vertex({ -0.888f, 0.059f, 0.075f });
		mesh.vertex({ -0.951f, 0.412f, 0.158f });
		mesh.vertex({ -0.755f, -0.006f, 0.237f });
		mesh.vertex({ -0.657f, 0.59f, 0.025f });
		mesh.vertex({ -0.403f, 0.119f, 0.318f });
		mesh.vertex({ -0.306f, 0.437f, 0.296f });
		mesh.vertex({ -0.467f, 0.696f, 0.228f });
		mesh.vertex({ -0.136f, 0.839f, 0.044f });
		mesh.vertex({ 0.182f, -0.333f, -0.325f });
		mesh.vertex({ 0.378f, -0.402f, -0.239f });
		mesh.vertex({ 0.511f, -0.081f, -0.444f });
		mesh.vertex({ 0.683f, -0.151f, -0.256f });
		mesh.vertex({ 0.746f, -0.297f, -0.118f });
		mesh.vertex({ 0.104f, -0.891f, 0.092f });
		mesh.vertex({ 0.106f, -0.679f, 0.318f });
		mesh.vertex({ 0.316f, -0.835f, 0.127f });
		mesh.vertex({ 0.269f, -0.577f, 0.455f });
		mesh.vertex({ 0.471f, -0.507f, -0.092f });
		mesh.vertex({ 0.089f, -0.432f, 0.524f });
		mesh.vertex({ 0.036f, -0.166f, 0.459f });
		mesh.vertex({ 0.303f, -0.228f, 0.421f });
		mesh.vertex({ 0.617f, -0.604f, 0.073f });
		mesh.vertex({ 0.824f, -0.587f, 0.176f });
		mesh.vertex({ 0.504f, -0.524f, 0.412f });
		mesh.vertex({ 0.867f, -0.441f, 0.064f });
		mesh.vertex({ 0.902f, -0.433f, 0.29f });
		mesh.vertex({ 0.739f, -0.219f, 0.31f });
		mesh.vertex({ 0.439f, 0.144f, -0.548f });
		mesh.vertex({ 0.413f, 0.402f, -0.596f });
		mesh.vertex({ 0.43f, 0.385f, -0.229f });
		mesh.vertex({ 0.025f, 0.58f, -0.616f });
		mesh.vertex({ 0.109f, 0.722f, -0.295f });
		mesh.vertex({ 0.095f, 0.823f, -0.122f });
		mesh.vertex({ 0.286f, 0.665f, -0.238f });
		mesh.vertex({ 0.595f, 0.058f, -0.338f });
		mesh.vertex({ 0.386f, 0.145f, 0.241f });
		mesh.vertex({ 0.431f, 0.396f, 0.084f });
		mesh.vertex({ 0.315f, 0.3f, 0.183f });
		mesh.vertex({ -0.016f, -0.007f, 0.408f });
		mesh.vertex({ 0.017f, 0.524f, 0.165f });
		mesh.vertex({ 0.298f, 0.651f, -0.007f });
		mesh.vertex({ 0.577f, 0.096f, 0.206f });


	}

	static void faces(Mesh& mesh) {

		mesh.face({ {0, 1, 4, 10} });
		mesh.face({ {31, 32, 3, 2, 10, 4, 17} });
		mesh.face({ {0, 5, 25, 6} });
		mesh.face({ {1, 14, 16, 18, 17} });
		mesh.face({ {7, 37, 9, 12} });
		mesh.face({ {2, 8, 7} });
		mesh.face({ {12, 13, 5, 11} });
		mesh.face({ {0, 10, 11, 5} });
		mesh.face({ {2, 7, 11, 10} });
		mesh.face({ {7, 12, 11} });
		mesh.face({ {12, 9, 61, 13} });
		mesh.face({ {8, 36, 37, 7} });
		mesh.face({ {19, 53, 18, 16} });
		mesh.face({ {20, 21, 19} });
		mesh.face({ {16, 20, 19} });
		mesh.face({ {17, 18, 53, 51, 50} });
		mesh.face({ {14, 15, 20, 16} });
		mesh.face({ {61, 28, 27} });
		mesh.face({ {24, 29, 26} });
		mesh.face({ {24, 23, 25, 27, 28, 29} });
		mesh.face({ {30, 22, 21, 20} });
		mesh.face({ {62, 28, 61, 58, 60} });
		mesh.face({ {34, 35, 32, 31, 33} });
		mesh.face({ {38, 37, 36} });
		mesh.face({ {39, 43, 42, 41} });
		mesh.face({ {32, 35, 47, 40} });
		mesh.face({ {35, 49, 48, 47} });
		mesh.face({ {57, 64, 49, 34} });
		mesh.face({ {48, 49, 46} });
		mesh.face({ {38, 40, 47, 45, 44} });
		mesh.face({ {43, 39, 46, 49} });
		mesh.face({ {47, 48, 45} });
		mesh.face({ {45, 48, 46, 44} });
		mesh.face({ {39, 41, 9} });
		mesh.face({ {37, 38, 39, 9} });
		mesh.face({ {61, 42, 43, 58} });
		mesh.face({ {38, 44, 46, 39} });
		mesh.face({ {35, 34, 49} });
		mesh.face({ {50, 51, 52, 57} });
		mesh.face({ {54, 55, 56} });
		mesh.face({ {51, 56, 52} });
		mesh.face({ {28, 62, 30, 29} });
		mesh.face({ {59, 63, 62, 60} });
		mesh.face({ {63, 55, 62} });
		mesh.face({ {17, 50, 33, 31} });
		mesh.face({ {25, 23, 1, 6} });
		mesh.face({ {41, 42, 61, 9} });
		mesh.face({ {21, 54, 53, 19} });
		mesh.face({ {21, 22, 55, 54} });
		mesh.face({ {62, 55, 30} });
		mesh.face({ {1, 17, 4} });
		mesh.face({ {57, 34, 33} });
		mesh.face({ {33, 50, 57} });
		mesh.face({ {13, 61, 27, 5} });
		mesh.face({ {5, 27, 25} });
		mesh.face({ {64, 59, 60, 58} });
		mesh.face({ {49, 64, 58, 43} });
		mesh.face({ {0, 6, 1} });
		mesh.face({ {2, 3, 8} });
		mesh.face({ {1, 23, 24, 14} });
		mesh.face({ {26, 15, 14} });
		mesh.face({ {20, 29, 30} });
		mesh.face({ {14, 24, 26} });
		mesh.face({ {26, 29, 20, 15} });
		mesh.face({ {3, 32, 40, 38, 36, 8} });
		mesh.face({ {56, 55, 63} });
		mesh.face({ {52, 59, 64, 57} });
		mesh.face({ {56, 63, 59, 52} });
		mesh.face({ {30, 55, 22} });
		mesh.face({ {51, 53, 54, 56} });

	}

};

#endif
