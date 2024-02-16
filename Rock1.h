
#pragma once

#ifndef ROCK1_H
#define ROCK1_H

#include "Mesh.h"

class Rock1 {
public:
	static Mesh init() {
		Mesh mesh;

		vertices(mesh);
		faces(mesh);

		return mesh;
	}

private:
	static void vertices(Mesh& mesh) {

		mesh.vertex({ -0.481f, -0.887f, -0.363f });
		mesh.vertex({ -0.742f, -0.758f, -0.369f });
		mesh.vertex({ -0.608f, -0.845f, -0.172f });
		mesh.vertex({ -0.685f, -0.815f, -0.094f });
		mesh.vertex({ -0.662f, -0.786f, 0.176f });
		mesh.vertex({ -0.906f, -0.2f, -0.382f });
		mesh.vertex({ -0.397f, -0.86f, -0.086f });
		mesh.vertex({ -0.497f, -0.832f, 0.014f });
		mesh.vertex({ -0.397f, -0.823f, 0.174f });
		mesh.vertex({ -0.631f, -0.717f, 0.528f });
		mesh.vertex({ -0.577f, -0.64f, 0.604f });
		mesh.vertex({ -0.694f, -0.46f, 0.568f });
		mesh.vertex({ -0.474f, -0.759f, 0.553f });
		mesh.vertex({ -0.528f, -0.656f, 0.629f });
		mesh.vertex({ -0.372f, -0.459f, 0.718f });
		mesh.vertex({ -0.814f, 0.089f, -0.378f });
		mesh.vertex({ -0.82f, 0.309f, -0.238f });
		mesh.vertex({ -0.764f, 0.412f, -0.365f });
		mesh.vertex({ -0.927f, 0.092f, -0.102f });
		mesh.vertex({ -0.836f, 0.279f, -0.184f });
		mesh.vertex({ -0.448f, 0.893f, -0.329f });
		mesh.vertex({ -0.836f, 0.122f, 0.566f });
		mesh.vertex({ -0.836f, 0.122f, 0.566f });
		mesh.vertex({ -0.731f, 0.197f, 0.629f });
		mesh.vertex({ -0.724f, 0.36f, 0.503f });
		mesh.vertex({ -0.558f, 0.339f, 0.714f });
		mesh.vertex({ -0.576f, 0.623f, 0.486f });
		mesh.vertex({ -0.545f, 0.518f, 0.582f });
		mesh.vertex({ 0.078f, 0.081f, 0.973f });
		mesh.vertex({ -0.387f, 0.621f, 0.528f });
		mesh.vertex({ 0.559f, -1.002f, -0.359f });
		mesh.vertex({ 0.748f, -0.757f, -0.383f });
		mesh.vertex({ 0.824f, -0.857f, -0.275f });
		mesh.vertex({ 0.85f, -0.717f, -0.359f });
		mesh.vertex({ 0.763f, -0.959f, -0.096f });
		mesh.vertex({ 0.748f, -0.929f, 0.221f });
		mesh.vertex({ 0.815f, -0.867f, -0.196f });
		mesh.vertex({ 0.936f, -0.179f, -0.388f });
		mesh.vertex({ 0.146f, 0.911f, -0.351f });
		mesh.vertex({ 0.407f, 0.92f, -0.352f });
		mesh.vertex({ 0.149f, 0.863f, -0.104f });
		mesh.vertex({ 0.158f, 0.789f, 0.178f });
		mesh.vertex({ 0.528f, 0.889f, -0.172f });
		mesh.vertex({ 0.414f, 0.823f, 0.164f });
		mesh.vertex({ 0.804f, 0.448f, -0.388f });
		mesh.vertex({ 0.907f, 0.326f, -0.389f });
		mesh.vertex({ 0.804f, 0.479f, -0.177f });
		mesh.vertex({ 0.955f, 0.275f, -0.075f });
		mesh.vertex({ 0.642f, 0.638f, -0.374f });
		mesh.vertex({ 0.565f, 0.776f, -0.272f });
		mesh.vertex({ 0.738f, 0.602f, -0.097f });
		mesh.vertex({ 0.581f, 0.859f, -0.077f });
		mesh.vertex({ 0.597f, 0.82f, 0.17f });
		mesh.vertex({ 0.814f, 0.492f, -0.001f });
		mesh.vertex({ 0.148f, 0.651f, 0.584f });
		mesh.vertex({ 0.411f, 0.667f, 0.606f });
		mesh.vertex({ 0.756f, 0.464f, 0.788f });
		mesh.vertex({ 0.883f, 0.031f, 0.794f });
		mesh.vertex({ 0.932f, 0.422f, 0.729f });
		mesh.vertex({ 0.659f, 0.223f, 0.94f });
		mesh.vertex({ 0.808f, 0.275f, 0.924f });
		mesh.vertex({ 0.879f, 0.155f, 0.873f });
		mesh.vertex({ 0.887f, 0.248f, 0.905f });
		mesh.vertex({ 0.715f, 0.693f, 0.618f });
		mesh.vertex({ 0.835f, 0.544f, 0.675f });

	}

	static void faces(Mesh& mesh) {

		mesh.face({ {3, 7, 8, 4} });
		mesh.face({ {6, 7, 3, 2} });
		mesh.face({ {0, 2, 3, 1} });
		mesh.face({ {0, 6, 2} });
		mesh.face({ {9, 12, 13, 10} });
		mesh.face({ {9, 10, 11} });
		mesh.face({ {13, 14, 11, 10} });
		mesh.face({ {15, 16, 17} });
		mesh.face({ {15, 18, 19, 16} });
		mesh.face({ {21, 24, 26, 20, 17, 16, 19, 18} });
		mesh.face({ {22, 23, 25, 24, 21} });
		mesh.face({ {24, 25, 27, 26} });
		mesh.face({ {30, 31, 33, 32} });
		mesh.face({ {57, 35, 34, 36, 32, 33, 37, 45, 47, 58} });
		mesh.face({ {30, 32, 36, 34} });
		mesh.face({ {41, 43, 42, 40} });
		mesh.face({ {0, 1, 5, 15, 17, 20, 38, 39, 48, 44, 45, 37, 33, 31, 30} });
		mesh.face({ {39, 49, 48} });
		mesh.face({ {43, 52, 51, 42} });
		mesh.face({ {46, 50, 53, 47} });
		mesh.face({ {40, 42, 39, 38} });
		mesh.face({ {46, 47, 45, 44} });
		mesh.face({ {49, 51, 50, 48} });
		mesh.face({ {48, 50, 46, 44} });
		mesh.face({ {42, 51, 49, 39} });
		mesh.face({ {60, 56, 63, 55, 54, 29, 26, 27, 25, 28, 59} });
		mesh.face({ {61, 62, 60, 59} });
		mesh.face({ {64, 53, 52, 63} });
		mesh.face({ {58, 64, 63, 56} });
		mesh.face({ {58, 62, 61, 57} });
		mesh.face({ {60, 62, 58, 56} });
		mesh.face({ {35, 57, 61, 59, 28, 14, 13, 12} });
		mesh.face({ {23, 22, 11, 14} });
		mesh.face({ {5, 18, 15} });
		mesh.face({ {0, 30, 34, 35, 12, 8, 7, 6} });
		mesh.face({ {22, 21, 18, 5, 1, 3, 4, 9, 11} });
		mesh.face({ {4, 8, 12, 9} });
		mesh.face({ {63, 52, 43, 55} });
		mesh.face({ {14, 28, 25, 23} });
		mesh.face({ {29, 54, 41, 40, 38, 20, 26} });
		mesh.face({ {53, 64, 58, 47} });
		mesh.face({ {52, 53, 50, 51} });
		mesh.face({ {55, 43, 41, 54} });

	}

};

#endif
