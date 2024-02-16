
#pragma once

#ifndef ROCK3_H
#define ROCK3_H

#include "Mesh.h"

class Rock3 {
public:
	static Mesh init() {
		Mesh mesh;

		vertices(mesh);
		faces(mesh);

		return mesh;
	}

private:
	static void vertices(Mesh& mesh) {

		mesh.vertex({ -0.532f, -0.892f, -0.29f });
		mesh.vertex({ -0.774f, -0.471f, -0.302f });
		mesh.vertex({ -0.865f, -0.219f, -0.274f });
		mesh.vertex({ -0.282f, -0.939f, -0.297f });
		mesh.vertex({ -0.194f, -0.875f, -0.012f });
		mesh.vertex({ -0.113f, -0.798f, -0.294f });
		mesh.vertex({ -0.604f, -0.676f, 0.11f });
		mesh.vertex({ -0.679f, -0.434f, 0.17f });
		mesh.vertex({ -0.835f, -0.046f, 0.133f });
		mesh.vertex({ -0.366f, -0.95f, 0.088f });
		mesh.vertex({ -0.118f, -0.672f, 0.192f });
		mesh.vertex({ -0.391f, -0.409f, 0.252f });
		mesh.vertex({ -0.444f, -0.094f, 0.283f });
		mesh.vertex({ -0.083f, -0.408f, 0.256f });
		mesh.vertex({ -0.609f, 0.123f, -0.293f });
		mesh.vertex({ -0.491f, 0.342f, -0.309f });
		mesh.vertex({ -0.361f, 0.49f, -0.302f });
		mesh.vertex({ -0.069f, 0.772f, -0.276f });
		mesh.vertex({ -0.672f, 0.143f, 0.202f });
		mesh.vertex({ -0.43f, 0.329f, 0.303f });
		mesh.vertex({ -0.028f, 0.144f, 0.219f });
		mesh.vertex({ -0.178f, 0.575f, 0.252f });
		mesh.vertex({ -0.008f, 0.774f, 0.231f });
		mesh.vertex({ 0.231f, -0.717f, -0.297f });
		mesh.vertex({ 0.271f, -0.505f, -0.261f });
		mesh.vertex({ 0.437f, -0.32f, -0.271f });
		mesh.vertex({ 0.934f, -0.002f, -0.258f });
		mesh.vertex({ 0.22f, -0.44f, 0.174f });
		mesh.vertex({ 0.229f, -0.146f, 0.283f });
		mesh.vertex({ 0.456f, -0.349f, 0.155f });
		mesh.vertex({ 0.579f, -0.235f, 0.227f });
		mesh.vertex({ 0.635f, 0.575f, -0.254f });
		mesh.vertex({ 0.278f, 1.015f, -0.261f });
		mesh.vertex({ 0.177f, 1.08f, -0.018f });
		mesh.vertex({ 0.493f, 0.755f, -0.256f });
		mesh.vertex({ 0.893f, 0.216f, -0.255f });
		mesh.vertex({ 0.206f, 0.176f, 0.225f });
		mesh.vertex({ 0.303f, 0.628f, 0.196f });
		mesh.vertex({ 0.623f, 0.134f, 0.287f });
		mesh.vertex({ 0.576f, 0.539f, 0.179f });
		mesh.vertex({ 0.184f, 0.99f, 0.149f });
		mesh.vertex({ 0.447f, 0.727f, 0.092f });
		mesh.vertex({ 0.95f, 0.07f, 0.12f });

	}

	static void faces(Mesh& mesh) {

		mesh.face({ {9, 6, 0, 3} });
		mesh.face({ {0, 1, 2, 14, 15, 16, 17, 32, 34, 31, 35, 26, 25, 24, 23, 5, 3} });
		mesh.face({ {19, 21, 16, 15} });
		mesh.face({ {4, 10, 9} });
		mesh.face({ {13, 12, 11} });
		mesh.face({ {11, 12, 8, 7} });
		mesh.face({ {10, 13, 11, 9} });
		mesh.face({ {9, 11, 7, 6} });
		mesh.face({ {20, 21, 19} });
		mesh.face({ {29, 30, 28, 27} });
		mesh.face({ {38, 39, 37, 36} });
		mesh.face({ {42, 39, 38} });
		mesh.face({ {39, 41, 40, 37} });
		mesh.face({ {27, 28, 13} });
		mesh.face({ {17, 33, 32} });
		mesh.face({ {36, 37, 21, 20} });
		mesh.face({ {40, 41, 34, 32, 33} });
		mesh.face({ {37, 40, 22, 21} });
		mesh.face({ {13, 20, 19, 12} });
		mesh.face({ {12, 19, 18, 8} });
		mesh.face({ {30, 38, 36, 28} });
		mesh.face({ {42, 38, 30} });
		mesh.face({ {1, 7, 8, 2} });
		mesh.face({ {5, 10, 4} });
		mesh.face({ {0, 6, 7, 1} });
		mesh.face({ {17, 22, 40, 33} });
		mesh.face({ {16, 21, 22, 17} });
		mesh.face({ {18, 19, 15, 14} });
		mesh.face({ {25, 30, 29} });
		mesh.face({ {24, 25, 29, 27} });
		mesh.face({ {42, 26, 35} });
		mesh.face({ {24, 27, 13, 23} });
		mesh.face({ {39, 42, 35, 31} });
		mesh.face({ {25, 26, 42, 30} });
		mesh.face({ {34, 41, 39, 31} });
		mesh.face({ {2, 8, 18, 14} });
		mesh.face({ {5, 23, 13, 10} });
		mesh.face({ {28, 36, 20, 13} });
		mesh.face({ {4, 9, 3, 5} });

	}

};

#endif
