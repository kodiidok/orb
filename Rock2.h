
#pragma once

#ifndef ROCK2_H
#define ROCK2_H

#include "Mesh.h"

class Rock2 {
public:
	static Mesh init() {
		Mesh mesh;

		vertices(mesh);
		faces(mesh);

		return mesh;
	}

private:
	static void vertices(Mesh& mesh) {

		mesh.vertex({ -0.713f, -0.445f, -0.32f });
		mesh.vertex({ -0.61f, -0.398f, 0.083f });
		mesh.vertex({ -0.779f, -0.194f, -0.348f });
		mesh.vertex({ -0.159f, -0.489f, -0.338f });
		mesh.vertex({ -0.737f, 0.097f, 0.189f });
		mesh.vertex({ -0.586f, -0.332f, 0.262f });
		mesh.vertex({ -0.68f, -0.012f, 0.282f });
		mesh.vertex({ -0.408f, -0.369f, 0.315f });
		mesh.vertex({ -0.175f, -0.413f, 0.393f });
		mesh.vertex({ -0.371f, -0.018f, 0.387f });
		mesh.vertex({ -0.936f, 0.409f, -0.335f });
		mesh.vertex({ -0.838f, 0.321f, 0.004f });
		mesh.vertex({ -0.711f, 0.537f, -0.078f });
		mesh.vertex({ -0.75f, 0.696f, -0.329f });
		mesh.vertex({ -0.59f, 0.586f, 0.021f });
		mesh.vertex({ -0.193f, 0.558f, 0.17f });
		mesh.vertex({ -0.387f, 0.592f, 0.036f });
		mesh.vertex({ -0.42f, 0.215f, 0.393f });
		mesh.vertex({ -0.415f, 0.461f, 0.421f });
		mesh.vertex({ 0.539f, -0.537f, -0.31f });
		mesh.vertex({ 0.698f, -0.383f, -0.314f });
		mesh.vertex({ 0.635f, -0.533f, -0.146f });
		mesh.vertex({ 0.61f, -0.515f, 0.08f });
		mesh.vertex({ 0.683f, -0.386f, -0.161f });
		mesh.vertex({ 0.691f, -0.265f, 0.069f });
		mesh.vertex({ 0.031f, -0.45f, 0.395f });
		mesh.vertex({ 0.298f, -0.478f, 0.556f });
		mesh.vertex({ 0.589f, -0.473f, 0.315f });
		mesh.vertex({ 0.567f, -0.418f, 0.661f });
		mesh.vertex({ 0.646f, -0.318f, 0.304f });
		mesh.vertex({ 0.676f, -0.056f, 0.733f });
		mesh.vertex({ 0.842f, 0.721f, -0.328f });
		mesh.vertex({ 0.08f, 0.533f, 0.32f });
		mesh.vertex({ 0.056f, 0.447f, 0.571f });
		mesh.vertex({ 0.313f, 0.579f, 0.233f });
		mesh.vertex({ 0.61f, 0.533f, 0.45f });
		mesh.vertex({ 0.503f, 0.494f, 0.538f });
		mesh.vertex({ 0.737f, 0.198f, 0.554f });
		mesh.vertex({ 0.777f, 0.365f, 0.437f });
		mesh.vertex({ 0.513f, 0.187f, 0.701f });
		mesh.vertex({ 0.44f, 0.343f, 0.661f });
		mesh.vertex({ 0.802f, 0.607f, 0.269f });

	}

	static void faces(Mesh& mesh) {

		mesh.face({ {7, 9, 6, 5} });
		mesh.face({ {7, 5, 1} });
		mesh.face({ {11, 14, 12, 10} });
		mesh.face({ {12, 13, 10} });
		mesh.face({ {6, 4, 11, 10, 2, 0, 1, 5} });
		mesh.face({ {36, 40, 39, 37, 38} });
		mesh.face({ {17, 18, 4} });
		mesh.face({ {24, 22, 21, 23} });
		mesh.face({ {19, 20, 23, 21} });
		mesh.face({ {27, 28, 26, 25, 8, 7, 1, 0, 3, 19, 21, 22} });
		mesh.face({ {28, 27, 29, 30} });
		mesh.face({ {33, 40, 34, 32} });
		mesh.face({ {9, 7, 8, 25, 26, 28, 30, 39, 40, 33, 18, 17} });
		mesh.face({ {36, 38, 41, 35} });
		mesh.face({ {40, 36, 35, 34} });
		mesh.face({ {34, 35, 41, 31, 13, 12, 14, 16, 15, 32} });
		mesh.face({ {30, 37, 39} });
		mesh.face({ {9, 17, 4, 6} });
		mesh.face({ {11, 4, 18, 14} });
		mesh.face({ {18, 15, 16} });
		mesh.face({ {18, 16, 14} });
		mesh.face({ {24, 29, 27, 22} });
		mesh.face({ {37, 30, 29, 24, 23, 20, 31, 41, 38} });
		mesh.face({ {33, 32, 15, 18} });
		mesh.face({ {19, 3, 0, 2, 10, 13, 31, 20} });


	}

};

#endif
