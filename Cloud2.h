

#pragma once

#ifndef CLOUD2_H
#define CLOUD2_H

#include "Mesh.h"

class Cloud2 {
public:
	static Mesh init() {
		Mesh mesh;

		vertices(mesh);
		faces(mesh);

		return mesh;
	}

private:
	static void vertices(Mesh& mesh) {

		mesh.vertex({ -11.677f, -1.528f, -1.514f });
		mesh.vertex({ -12.607f, -0.799f, -0.547f });
		mesh.vertex({ -10.248f, -1.687f, -1.675f });
		mesh.vertex({ -11.472f, -1.054f, -2.925f });
		mesh.vertex({ -10.943f, 0.046f, -2.175f });
		mesh.vertex({ -8.413f, -0.505f, -2.218f });
		mesh.vertex({ -7.489f, -1.012f, -0.885f });
		mesh.vertex({ -10.85f, -1.521f, -0.127f });
		mesh.vertex({ -11.285f, -0.111f, 0.668f });
		mesh.vertex({ -9.821f, -1.005f, 1.488f });
		mesh.vertex({ -10.433f, 0.836f, -0.157f });
		mesh.vertex({ -10.015f, 0.179f, 2.801f });
		mesh.vertex({ -8.976f, -1.34f, -0.402f });
		mesh.vertex({ -7.487f, -1.255f, 1.55f });
		mesh.vertex({ -8.616f, -0.818f, 2.406f });
		mesh.vertex({ -8.808f, 0.208f, 3.391f });
		mesh.vertex({ -9.383f, 1.535f, -1.486f });
		mesh.vertex({ -8.32f, 1.215f, -2.909f });
		mesh.vertex({ -7.032f, 1.185f, -3.974f });
		mesh.vertex({ -8.771f, 2.364f, -0.497f });
		mesh.vertex({ -7.498f, 2.363f, -0.841f });
		mesh.vertex({ -10.235f, 1.87f, 0.971f });
		mesh.vertex({ -9.672f, 1.87f, 2.42f });
		mesh.vertex({ -8.72f, 2.495f, 1.557f });
		mesh.vertex({ -8.177f, 1.474f, 3.296f });
		mesh.vertex({ -7.391f, 2.351f, 2.379f });
		mesh.vertex({ -6.489f, -0.505f, -3.499f });
		mesh.vertex({ -5.779f, 0.369f, -4.616f });
		mesh.vertex({ -4.948f, -0.457f, -3.707f });
		mesh.vertex({ -6.3f, -0.682f, -2.069f });
		mesh.vertex({ -5.095f, -0.958f, -0.869f });
		mesh.vertex({ -3.844f, 0.584f, -4.213f });
		mesh.vertex({ -2.64f, -0.525f, -3.289f });
		mesh.vertex({ -4.07f, -1.135f, -1.944f });
		mesh.vertex({ -2.923f, -1.477f, -1.366f });
		mesh.vertex({ -0.639f, -1.698f, -0.617f });
		mesh.vertex({ -1.36f, 0.622f, -3.595f });
		mesh.vertex({ -0.774f, -0.356f, -2.78f });
		mesh.vertex({ -1.649f, -1.322f, -1.979f });
		mesh.vertex({ 0.542f, -0.344f, -2.005f });
		mesh.vertex({ -5.887f, -1.03f, 0.565f });
		mesh.vertex({ -5.841f, -0.764f, 2.004f });
		mesh.vertex({ -6.305f, 0.478f, 3.756f });
		mesh.vertex({ -5.07f, -0.112f, 3.115f });
		mesh.vertex({ -2.749f, -1.726f, 1.361f });
		mesh.vertex({ -4.101f, -1.426f, 0.308f });
		mesh.vertex({ -3.948f, 0.623f, 3.873f });
		mesh.vertex({ -2.726f, -1.06f, 2.812f });
		mesh.vertex({ -0.643f, -1.695f, 1.249f });
		mesh.vertex({ -1.337f, -0.918f, 3.262f });
		mesh.vertex({ -1.876f, 0.547f, 4.041f });
		mesh.vertex({ -0.034f, -0.895f, 2.67f });
		mesh.vertex({ -0.281f, 0.617f, 3.272f });
		mesh.vertex({ 1.285f, -0.898f, 0.307f });
		mesh.vertex({ 0.744f, -0.796f, 1.57f });
		mesh.vertex({ 1.701f, 0.668f, 0.305f });
		mesh.vertex({ 1.181f, 0.668f, 1.57f });
		mesh.vertex({ -4.829f, 1.794f, -3.634f });
		mesh.vertex({ -6.363f, 2.013f, -1.994f });
		mesh.vertex({ -5.184f, 2.23f, -0.908f });
		mesh.vertex({ -3.293f, 2.1f, -2.668f });
		mesh.vertex({ -3.919f, 2.697f, -0.881f });
		mesh.vertex({ -0.68f, 1.598f, -2.826f });
		mesh.vertex({ -1.699f, 2.504f, -2.262f });
		mesh.vertex({ -1.515f, 3.116f, -0.947f });
		mesh.vertex({ 0.583f, 1.643f, -1.991f });
		mesh.vertex({ 0.24f, 2.524f, -0.8f });
		mesh.vertex({ -6.245f, 2.534f, 0.479f });
		mesh.vertex({ -5.076f, 2.157f, 1.427f });
		mesh.vertex({ -6.262f, 1.815f, 3.004f });
		mesh.vertex({ -5.108f, 1.206f, 3.489f });
		mesh.vertex({ -2.88f, 3.185f, 0.385f });
		mesh.vertex({ -3.684f, 1.903f, 3.197f });
		mesh.vertex({ -1.522f, 3.112f, 1.58f });
		mesh.vertex({ -0.455f, 3.083f, 0.319f });
		mesh.vertex({ -1.773f, 2.535f, 2.794f });
		mesh.vertex({ 0.284f, 2.116f, 2.149f });



	}

	static void faces(Mesh& mesh) {

		mesh.face({ {3, 1, 4} });
		mesh.face({ {0, 1, 3} });
		mesh.face({ {3, 2, 0} });
		mesh.face({ {3, 4, 2} });
		mesh.face({ {2, 5, 6} });
		mesh.face({ {2, 4, 5} });
		mesh.face({ {26, 5, 17} });
		mesh.face({ {1, 8, 4} });
		mesh.face({ {7, 9, 8} });
		mesh.face({ {7, 12, 9} });
		mesh.face({ {12, 6, 13, 9} });
		mesh.face({ {14, 15, 11, 9} });
		mesh.face({ {9, 13, 14} });
		mesh.face({ {7, 8, 1} });
		mesh.face({ {16, 20, 17} });
		mesh.face({ {16, 19, 20} });
		mesh.face({ {21, 22, 19} });
		mesh.face({ {23, 20, 19} });
		mesh.face({ {24, 25, 22} });
		mesh.face({ {22, 23, 19} });
		mesh.face({ {22, 25, 23} });
		mesh.face({ {26, 27, 28} });
		mesh.face({ {29, 28, 30} });
		mesh.face({ {31, 32, 28} });
		mesh.face({ {33, 34, 30} });
		mesh.face({ {28, 33, 30} });
		mesh.face({ {26, 28, 29} });
		mesh.face({ {28, 32, 34, 33} });
		mesh.face({ {32, 36, 37} });
		mesh.face({ {38, 37, 35} });
		mesh.face({ {37, 39, 35} });
		mesh.face({ {36, 39, 37} });
		mesh.face({ {32, 37, 38} });
		mesh.face({ {32, 38, 34} });
		mesh.face({ {40, 30, 41} });
		mesh.face({ {43, 47, 46} });
		mesh.face({ {30, 45, 41} });
		mesh.face({ {45, 44, 47, 43} });
		mesh.face({ {41, 45, 43} });
		mesh.face({ {35, 48, 44} });
		mesh.face({ {49, 52, 50} });
		mesh.face({ {51, 52, 49} });
		mesh.face({ {55, 56, 54, 53} });
		mesh.face({ {35, 53, 54, 48} });
		mesh.face({ {44, 48, 51, 49} });
		mesh.face({ {56, 52, 51, 54} });
		mesh.face({ {48, 54, 51} });
		mesh.face({ {45, 35, 44} });
		mesh.face({ {47, 49, 50} });
		mesh.face({ {50, 46, 47} });
		mesh.face({ {44, 49, 47} });
		mesh.face({ {18, 57, 27} });
		mesh.face({ {58, 20, 59} });
		mesh.face({ {57, 60, 31} });
		mesh.face({ {57, 31, 27} });
		mesh.face({ {59, 61, 60} });
		mesh.face({ {57, 58, 59} });
		mesh.face({ {58, 57, 18} });
		mesh.face({ {59, 60, 57} });
		mesh.face({ {64, 65, 63} });
		mesh.face({ {63, 65, 62} });
		mesh.face({ {64, 66, 65} });
		mesh.face({ {63, 62, 36} });
		mesh.face({ {61, 64, 63, 60} });
		mesh.face({ {60, 63, 36} });
		mesh.face({ {67, 68, 59} });
		mesh.face({ {68, 67, 69} });
		mesh.face({ {68, 71, 61} });
		mesh.face({ {68, 61, 59} });
		mesh.face({ {69, 70, 68} });
		mesh.face({ {72, 71, 68} });
		mesh.face({ {70, 72, 68} });
		mesh.face({ {73, 76, 74, 64} });
		mesh.face({ {50, 52, 76, 75} });
		mesh.face({ {66, 76, 55} });
		mesh.face({ {76, 66, 74} });
		mesh.face({ {75, 76, 73} });
		mesh.face({ {71, 73, 64} });
		mesh.face({ {72, 50, 75} });
		mesh.face({ {72, 75, 73, 71} });
		mesh.face({ {5, 29, 6} });
		mesh.face({ {26, 29, 5} });
		mesh.face({ {6, 40, 13} });
		mesh.face({ {15, 43, 42} });
		mesh.face({ {41, 43, 15, 14} });
		mesh.face({ {13, 40, 41, 14} });
		mesh.face({ {20, 58, 17} });
		mesh.face({ {17, 58, 18} });
		mesh.face({ {23, 67, 20} });
		mesh.face({ {69, 25, 24} });
		mesh.face({ {25, 69, 67, 23} });
		mesh.face({ {26, 17, 18} });
		mesh.face({ {4, 10, 16} });
		mesh.face({ {5, 4, 17} });
		mesh.face({ {4, 16, 17} });
		mesh.face({ {31, 60, 32} });
		mesh.face({ {28, 27, 31} });
		mesh.face({ {65, 55, 39} });
		mesh.face({ {62, 39, 36} });
		mesh.face({ {39, 62, 65} });
		mesh.face({ {32, 60, 36} });
		mesh.face({ {9, 21, 10, 8} });
		mesh.face({ {15, 24, 22} });
		mesh.face({ {9, 11, 22, 21} });
		mesh.face({ {15, 22, 11} });
		mesh.face({ {43, 70, 69, 42} });
		mesh.face({ {46, 72, 70} });
		mesh.face({ {46, 70, 43} });
		mesh.face({ {55, 76, 56} });
		mesh.face({ {76, 52, 56} });
		mesh.face({ {50, 72, 46} });
		mesh.face({ {0, 2, 7} });
		mesh.face({ {8, 10, 4} });
		mesh.face({ {2, 12, 7} });
		mesh.face({ {2, 6, 12} });
		mesh.face({ {1, 0, 7} });
		mesh.face({ {10, 21, 19, 16} });
		mesh.face({ {29, 30, 40} });
		mesh.face({ {34, 45, 30} });
		mesh.face({ {55, 53, 39} });
		mesh.face({ {35, 39, 53} });
		mesh.face({ {34, 38, 35, 45} });
		mesh.face({ {67, 59, 20} });
		mesh.face({ {66, 55, 65} });
		mesh.face({ {74, 66, 64} });
		mesh.face({ {71, 64, 61} });
		mesh.face({ {6, 29, 40} });
		mesh.face({ {26, 18, 27} });
		mesh.face({ {42, 69, 24, 15} });


	}

};

#endif
