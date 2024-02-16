
#pragma once

#ifndef ROCK5_H
#define ROCK5_H

#include "Mesh.h"

class Rock5 {
public:
	static Mesh init() {
		Mesh mesh;

		vertices(mesh);
		faces(mesh);

		return mesh;
	}

private:
	static void vertices(Mesh& mesh) {

		mesh.vertex({ -0.626f, -0.656f, -0.316f });
		mesh.vertex({ -0.339f, -1.074f, -0.287f });
		mesh.vertex({ 0.153f, -1.043f, -0.565f });
		mesh.vertex({ 0.055f, -1.081f, -0.243f });
		mesh.vertex({ -0.047f, -0.642f, -0.539f });
		mesh.vertex({ -0.492f, -0.778f, -0.108f });
		mesh.vertex({ -0.824f, -0.222f, 0.475f });
		mesh.vertex({ 0.095f, -0.836f, 0.462f });
		mesh.vertex({ -0.212f, -0.808f, 0.094f });
		mesh.vertex({ -0.482f, -0.437f, 0.596f });
		mesh.vertex({ -0.17f, -0.466f, 0.801f });
		mesh.vertex({ -0.793f, -0.019f, -0.231f });
		mesh.vertex({ -0.803f, 0.317f, -0.297f });
		mesh.vertex({ -0.632f, 0.94f, -0.314f });
		mesh.vertex({ 0.01f, 0.713f, -0.461f });
		mesh.vertex({ -0.394f, 0.755f, -0.567f });
		mesh.vertex({ -0.656f, 0.037f, 0.247f });
		mesh.vertex({ -0.664f, 0.365f, 0.273f });
		mesh.vertex({ -0.843f, 0.363f, 0.515f });
		mesh.vertex({ -0.903f, 0.828f, -0.053f });
		mesh.vertex({ -0.706f, 0.68f, 0.327f });
		mesh.vertex({ -0.572f, 0.886f, 0.426f });
		mesh.vertex({ -0.834f, 0.802f, 0.527f });
		mesh.vertex({ -0.382f, 0.027f, 0.693f });
		mesh.vertex({ -0.382f, 0.362f, 0.673f });
		mesh.vertex({ -0.033f, 0.361f, 0.507f });
		mesh.vertex({ -0.382f, 0.835f, -0.005f });
		mesh.vertex({ -0.068f, 0.805f, 0.08f });
		mesh.vertex({ -0.143f, 0.883f, -0.2f });
		mesh.vertex({ -0.462f, 0.879f, 0.672f });
		mesh.vertex({ -0.138f, 0.697f, 0.476f });
		mesh.vertex({ 0.349f, -0.883f, -0.299f });
		mesh.vertex({ 0.477f, -0.828f, -0.762f });
		mesh.vertex({ 0.287f, -0.642f, -0.656f });
		mesh.vertex({ 0.254f, -0.325f, -0.583f });
		mesh.vertex({ 0.709f, -0.627f, -0.29f });
		mesh.vertex({ 0.75f, -0.348f, -0.396f });
		mesh.vertex({ 0.267f, -0.852f, 0.241f });
		mesh.vertex({ 0.668f, -0.878f, -0.129f });
		mesh.vertex({ 0.674f, -0.679f, 0.253f });
		mesh.vertex({ 0.741f, -0.308f, -0.07f });
		mesh.vertex({ 0.287f, -0.308f, 0.564f });
		mesh.vertex({ 0.712f, -0.323f, 0.468f });
		mesh.vertex({ 0.287f, 0.027f, -0.508f });
		mesh.vertex({ 0.254f, 0.328f, -0.572f });
		mesh.vertex({ 0.796f, -0.001f, -0.343f });
		mesh.vertex({ 0.781f, 0.462f, -0.436f });
		mesh.vertex({ 0.595f, 0.663f, -0.57f });
		mesh.vertex({ 0.41f, 0.159f, 0.415f });
		mesh.vertex({ 0.777f, -0.05f, -0.07f });
		mesh.vertex({ 0.37f, 0.766f, -0.082f });
		mesh.vertex({ 0.575f, 0.635f, 0.141f });
		mesh.vertex({ 0.799f, 0.161f, 0.098f });
		mesh.vertex({ 0.849f, 0.381f, -0.07f });

	}

	static void faces(Mesh& mesh) {

		mesh.face({ {2, 3, 4} });
		mesh.face({ {0, 4, 3, 1} });
		mesh.face({ {37, 7, 3, 31} });
		mesh.face({ {7, 10, 9} });
		mesh.face({ {3, 7, 8} });
		mesh.face({ {3, 8, 5, 1} });
		mesh.face({ {8, 7, 9} });
		mesh.face({ {1, 5, 0} });
		mesh.face({ {12, 19, 13, 15} });
		mesh.face({ {11, 16, 17, 12} });
		mesh.face({ {26, 27, 28} });
		mesh.face({ {26, 21, 27} });
		mesh.face({ {30, 21, 29} });
		mesh.face({ {23, 24, 18, 6} });
		mesh.face({ {20, 26, 19} });
		mesh.face({ {26, 13, 19} });
		mesh.face({ {20, 21, 26} });
		mesh.face({ {29, 21, 20, 22} });
		mesh.face({ {12, 17, 20, 19} });
		mesh.face({ {25, 30, 29, 24} });
		mesh.face({ {16, 6, 18, 17} });
		mesh.face({ {21, 30, 27} });
		mesh.face({ {17, 18, 22, 20} });
		mesh.face({ {24, 29, 22, 18} });
		mesh.face({ {34, 36, 35, 32} });
		mesh.face({ {33, 34, 32} });
		mesh.face({ {32, 35, 31} });
		mesh.face({ {40, 42, 39, 38} });
		mesh.face({ {39, 42, 41, 7} });
		mesh.face({ {38, 39, 37, 31} });
		mesh.face({ {37, 39, 7} });
		mesh.face({ {43, 34, 33, 4, 0, 11, 12, 15, 14, 44} });
		mesh.face({ {43, 44, 46, 45} });
		mesh.face({ {41, 48, 25, 10} });
		mesh.face({ {46, 53, 52, 49, 45} });
		mesh.face({ {14, 47, 46, 44} });
		mesh.face({ {50, 51, 53} });
		mesh.face({ {51, 50, 28, 27, 30, 25, 48} });
		mesh.face({ {10, 25, 24, 23, 9} });
		mesh.face({ {2, 32, 31, 3} });
		mesh.face({ {2, 4, 33, 32} });
		mesh.face({ {7, 41, 10} });
		mesh.face({ {52, 53, 51, 48, 42} });
		mesh.face({ {34, 43, 45, 36} });
		mesh.face({ {8, 9, 6, 5} });
		mesh.face({ {5, 6, 16} });
		mesh.face({ {9, 23, 6} });
		mesh.face({ {49, 52, 42, 40} });
		mesh.face({ {42, 48, 41} });
		mesh.face({ {26, 28, 14, 15} });
		mesh.face({ {13, 26, 15} });
		mesh.face({ {36, 40, 38, 35} });
		mesh.face({ {35, 38, 31} });
		mesh.face({ {50, 47, 14} });
		mesh.face({ {47, 50, 53, 46} });
		mesh.face({ {45, 49, 40, 36} });
		mesh.face({ {28, 50, 14} });
		mesh.face({ {0, 5, 16, 11} });


	}

};

#endif
