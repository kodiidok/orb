
#pragma once

#ifndef HEXAGON_OPEN_WALL_H
#define HEXAGON_OPEN_WALL_H

#include "Mesh.h"

class HexagonOpenWall {
public:
	static Mesh init() {
		Mesh mesh;

		vertices(mesh);
		faces(mesh);

		return mesh;
	}

private:
	static void vertices(Mesh& mesh) {

		mesh.vertex({ 0.400f, 1.000f, 3.000f });
		mesh.vertex({ 0.370f, 1.153f, 3.000f });
		mesh.vertex({ 0.283f, 1.283f, 3.000f });
		mesh.vertex({ 0.153f, 1.370f, 3.000f });
		mesh.vertex({ 0.000f, 1.400f, 3.000f });
		mesh.vertex({ -0.153f, 1.370f, 3.000f });
		mesh.vertex({ -0.283f, 1.283f, 3.000f });
		mesh.vertex({ -0.370f, 1.153f, 3.000f });
		mesh.vertex({ -0.400f, 1.000f, 3.000f });
		mesh.vertex({ 0.600f, 1.000f, 3.000f });
		mesh.vertex({ 0.600f, 1.400f, 3.000f });
		mesh.vertex({ 0.600f, 1.800f, 3.000f });
		mesh.vertex({ 0.300f, 1.800f, 3.000f });
		mesh.vertex({ 0.000f, 1.800f, 3.000f });
		mesh.vertex({ -0.300f, 1.800f, 3.000f });
		mesh.vertex({ -0.600f, 1.800f, 3.000f });
		mesh.vertex({ -0.600f, 1.400f, 3.000f });
		mesh.vertex({ -0.600f, 1.000f, 3.000f });
		mesh.vertex({ 2.798f, 1.000f, 1.154f });
		mesh.vertex({ 2.783f, 1.153f, 1.180f });
		mesh.vertex({ 2.739f, 1.283f, 1.255f });
		mesh.vertex({ 2.675f, 1.370f, 1.367f });
		mesh.vertex({ 2.598f, 1.400f, 1.500f });
		mesh.vertex({ 2.522f, 1.370f, 1.633f });
		mesh.vertex({ 2.457f, 1.283f, 1.745f });
		mesh.vertex({ 2.413f, 1.153f, 1.820f });
		mesh.vertex({ 2.398f, 1.000f, 1.846f });
		mesh.vertex({ 2.898f, 1.000f, 0.980f });
		mesh.vertex({ 2.898f, 1.400f, 0.980f });
		mesh.vertex({ 2.898f, 1.800f, 0.980f });
		mesh.vertex({ 2.748f, 1.800f, 1.240f });
		mesh.vertex({ 2.598f, 1.800f, 1.500f });
		mesh.vertex({ 2.448f, 1.800f, 1.760f });
		mesh.vertex({ 2.298f, 1.800f, 2.020f });
		mesh.vertex({ 2.298f, 1.400f, 2.020f });
		mesh.vertex({ 2.298f, 1.000f, 2.020f });
		mesh.vertex({ 2.398f, 1.000f, -1.846f });
		mesh.vertex({ 2.413f, 1.153f, -1.820f });
		mesh.vertex({ 2.457f, 1.283f, -1.745f });
		mesh.vertex({ 2.522f, 1.370f, -1.633f });
		mesh.vertex({ 2.598f, 1.400f, -1.500f });
		mesh.vertex({ 2.675f, 1.370f, -1.367f });
		mesh.vertex({ 2.739f, 1.283f, -1.255f });
		mesh.vertex({ 2.783f, 1.153f, -1.180f });
		mesh.vertex({ 2.798f, 1.000f, -1.154f });
		mesh.vertex({ 2.298f, 1.000f, -2.020f });
		mesh.vertex({ 2.298f, 1.400f, -2.020f });
		mesh.vertex({ 2.298f, 1.800f, -2.020f });
		mesh.vertex({ 2.448f, 1.800f, -1.760f });
		mesh.vertex({ 2.598f, 1.800f, -1.500f });
		mesh.vertex({ 2.748f, 1.800f, -1.240f });
		mesh.vertex({ 2.898f, 1.800f, -0.980f });
		mesh.vertex({ 2.898f, 1.400f, -0.980f });
		mesh.vertex({ 2.898f, 1.000f, -0.980f });
		mesh.vertex({ -0.400f, 1.000f, -3.000f });
		mesh.vertex({ -0.370f, 1.153f, -3.000f });
		mesh.vertex({ -0.283f, 1.283f, -3.000f });
		mesh.vertex({ -0.153f, 1.370f, -3.000f });
		mesh.vertex({ 0.000f, 1.400f, -3.000f });
		mesh.vertex({ 0.153f, 1.370f, -3.000f });
		mesh.vertex({ 0.283f, 1.283f, -3.000f });
		mesh.vertex({ 0.370f, 1.153f, -3.000f });
		mesh.vertex({ 0.400f, 1.000f, -3.000f });
		mesh.vertex({ -0.600f, 1.000f, -3.000f });
		mesh.vertex({ -0.600f, 1.400f, -3.000f });
		mesh.vertex({ -0.600f, 1.800f, -3.000f });
		mesh.vertex({ -0.300f, 1.800f, -3.000f });
		mesh.vertex({ 0.000f, 1.800f, -3.000f });
		mesh.vertex({ 0.300f, 1.800f, -3.000f });
		mesh.vertex({ 0.600f, 1.800f, -3.000f });
		mesh.vertex({ 0.600f, 1.400f, -3.000f });
		mesh.vertex({ 0.600f, 1.000f, -3.000f });
		mesh.vertex({ -2.798f, 1.000f, -1.154f });
		mesh.vertex({ -2.783f, 1.153f, -1.180f });
		mesh.vertex({ -2.739f, 1.283f, -1.255f });
		mesh.vertex({ -2.675f, 1.370f, -1.367f });
		mesh.vertex({ -2.598f, 1.400f, -1.500f });
		mesh.vertex({ -2.522f, 1.370f, -1.633f });
		mesh.vertex({ -2.457f, 1.283f, -1.745f });
		mesh.vertex({ -2.413f, 1.153f, -1.820f });
		mesh.vertex({ -2.398f, 1.000f, -1.846f });
		mesh.vertex({ -2.898f, 1.000f, -0.980f });
		mesh.vertex({ -2.898f, 1.400f, -0.980f });
		mesh.vertex({ -2.898f, 1.800f, -0.980f });
		mesh.vertex({ -2.748f, 1.800f, -1.240f });
		mesh.vertex({ -2.598f, 1.800f, -1.500f });
		mesh.vertex({ -2.448f, 1.800f, -1.760f });
		mesh.vertex({ -2.298f, 1.800f, -2.020f });
		mesh.vertex({ -2.298f, 1.400f, -2.020f });
		mesh.vertex({ -2.298f, 1.000f, -2.020f });
		mesh.vertex({ -2.398f, 1.000f, 1.846f });
		mesh.vertex({ -2.413f, 1.153f, 1.820f });
		mesh.vertex({ -2.457f, 1.283f, 1.745f });
		mesh.vertex({ -2.522f, 1.370f, 1.633f });
		mesh.vertex({ -2.598f, 1.400f, 1.500f });
		mesh.vertex({ -2.675f, 1.370f, 1.367f });
		mesh.vertex({ -2.739f, 1.283f, 1.255f });
		mesh.vertex({ -2.783f, 1.153f, 1.180f });
		mesh.vertex({ -2.798f, 1.000f, 1.154f });
		mesh.vertex({ -2.298f, 1.000f, 2.020f });
		mesh.vertex({ -2.298f, 1.400f, 2.020f });
		mesh.vertex({ -2.298f, 1.800f, 2.020f });
		mesh.vertex({ -2.448f, 1.800f, 1.760f });
		mesh.vertex({ -2.598f, 1.800f, 1.500f });
		mesh.vertex({ -2.748f, 1.800f, 1.240f });
		mesh.vertex({ -2.898f, 1.800f, 0.980f });
		mesh.vertex({ -2.898f, 1.400f, 0.980f });
		mesh.vertex({ -2.898f, 1.000f, 0.980f });

		mesh.vertex({ 0.400f, 1.000f, 2.000f });
		mesh.vertex({ 0.370f, 1.153f, 2.000f });
		mesh.vertex({ 0.283f, 1.283f, 2.000f });
		mesh.vertex({ 0.153f, 1.370f, 2.000f });
		mesh.vertex({ 0.000f, 1.400f, 2.000f });
		mesh.vertex({ -0.153f, 1.370f, 2.000f });
		mesh.vertex({ -0.283f, 1.283f, 2.000f });
		mesh.vertex({ -0.370f, 1.153f, 2.000f });
		mesh.vertex({ -0.400f, 1.000f, 2.000f });
		mesh.vertex({ 0.400f, 1.000f, 2.000f });
		mesh.vertex({ 0.400f, 1.400f, 2.000f });
		mesh.vertex({ 0.400f, 1.800f, 2.000f });
		mesh.vertex({ 0.200f, 1.800f, 2.000f });
		mesh.vertex({ 0.000f, 1.800f, 2.000f });
		mesh.vertex({ -0.200f, 1.800f, 2.000f });
		mesh.vertex({ -0.400f, 1.800f, 2.000f });
		mesh.vertex({ -0.400f, 1.400f, 2.000f });
		mesh.vertex({ -0.400f, 1.000f, 2.000f });
		mesh.vertex({ 1.932f, 1.000f, 0.654f });
		mesh.vertex({ 1.917f, 1.153f, 0.680f });
		mesh.vertex({ 1.873f, 1.283f, 0.755f });
		mesh.vertex({ 1.809f, 1.370f, 0.867f });
		mesh.vertex({ 1.732f, 1.400f, 1.000f });
		mesh.vertex({ 1.656f, 1.370f, 1.133f });
		mesh.vertex({ 1.591f, 1.283f, 1.245f });
		mesh.vertex({ 1.547f, 1.153f, 1.320f });
		mesh.vertex({ 1.532f, 1.000f, 1.346f });
		mesh.vertex({ 1.932f, 1.000f, 0.654f });
		mesh.vertex({ 1.932f, 1.400f, 0.654f });
		mesh.vertex({ 1.932f, 1.800f, 0.654f });
		mesh.vertex({ 1.832f, 1.800f, 0.827f });
		mesh.vertex({ 1.732f, 1.800f, 1.000f });
		mesh.vertex({ 1.632f, 1.800f, 1.173f });
		mesh.vertex({ 1.532f, 1.800f, 1.346f });
		mesh.vertex({ 1.532f, 1.400f, 1.346f });
		mesh.vertex({ 1.532f, 1.000f, 1.346f });
		mesh.vertex({ 1.532f, 1.000f, -1.346f });
		mesh.vertex({ 1.547f, 1.153f, -1.320f });
		mesh.vertex({ 1.591f, 1.283f, -1.245f });
		mesh.vertex({ 1.656f, 1.370f, -1.133f });
		mesh.vertex({ 1.732f, 1.400f, -1.000f });
		mesh.vertex({ 1.809f, 1.370f, -0.867f });
		mesh.vertex({ 1.873f, 1.283f, -0.755f });
		mesh.vertex({ 1.917f, 1.153f, -0.680f });
		mesh.vertex({ 1.932f, 1.000f, -0.654f });
		mesh.vertex({ 1.532f, 1.000f, -1.346f });
		mesh.vertex({ 1.532f, 1.400f, -1.346f });
		mesh.vertex({ 1.532f, 1.800f, -1.346f });
		mesh.vertex({ 1.632f, 1.800f, -1.173f });
		mesh.vertex({ 1.732f, 1.800f, -1.000f });
		mesh.vertex({ 1.832f, 1.800f, -0.827f });
		mesh.vertex({ 1.932f, 1.800f, -0.654f });
		mesh.vertex({ 1.932f, 1.400f, -0.654f });
		mesh.vertex({ 1.932f, 1.000f, -0.654f });
		mesh.vertex({ -0.400f, 1.000f, -2.000f });
		mesh.vertex({ -0.370f, 1.153f, -2.000f });
		mesh.vertex({ -0.283f, 1.283f, -2.000f });
		mesh.vertex({ -0.153f, 1.370f, -2.000f });
		mesh.vertex({ 0.000f, 1.400f, -2.000f });
		mesh.vertex({ 0.153f, 1.370f, -2.000f });
		mesh.vertex({ 0.283f, 1.283f, -2.000f });
		mesh.vertex({ 0.370f, 1.153f, -2.000f });
		mesh.vertex({ 0.400f, 1.000f, -2.000f });
		mesh.vertex({ -0.400f, 1.000f, -2.000f });
		mesh.vertex({ -0.400f, 1.400f, -2.000f });
		mesh.vertex({ -0.400f, 1.800f, -2.000f });
		mesh.vertex({ -0.200f, 1.800f, -2.000f });
		mesh.vertex({ 0.000f, 1.800f, -2.000f });
		mesh.vertex({ 0.200f, 1.800f, -2.000f });
		mesh.vertex({ 0.400f, 1.800f, -2.000f });
		mesh.vertex({ 0.400f, 1.400f, -2.000f });
		mesh.vertex({ 0.400f, 1.000f, -2.000f });
		mesh.vertex({ -1.932f, 1.000f, -0.654f });
		mesh.vertex({ -1.917f, 1.153f, -0.680f });
		mesh.vertex({ -1.873f, 1.283f, -0.755f });
		mesh.vertex({ -1.809f, 1.370f, -0.867f });
		mesh.vertex({ -1.732f, 1.400f, -1.000f });
		mesh.vertex({ -1.656f, 1.370f, -1.133f });
		mesh.vertex({ -1.591f, 1.283f, -1.245f });
		mesh.vertex({ -1.547f, 1.153f, -1.320f });
		mesh.vertex({ -1.532f, 1.000f, -1.346f });
		mesh.vertex({ -1.932f, 1.000f, -0.654f });
		mesh.vertex({ -1.932f, 1.400f, -0.654f });
		mesh.vertex({ -1.932f, 1.800f, -0.654f });
		mesh.vertex({ -1.832f, 1.800f, -0.827f });
		mesh.vertex({ -1.732f, 1.800f, -1.000f });
		mesh.vertex({ -1.632f, 1.800f, -1.173f });
		mesh.vertex({ -1.532f, 1.800f, -1.346f });
		mesh.vertex({ -1.532f, 1.400f, -1.346f });
		mesh.vertex({ -1.532f, 1.000f, -1.346f });
		mesh.vertex({ -1.532f, 1.000f, 1.346f });
		mesh.vertex({ -1.547f, 1.153f, 1.320f });
		mesh.vertex({ -1.591f, 1.283f, 1.245f });
		mesh.vertex({ -1.656f, 1.370f, 1.133f });
		mesh.vertex({ -1.732f, 1.400f, 1.000f });
		mesh.vertex({ -1.809f, 1.370f, 0.867f });
		mesh.vertex({ -1.873f, 1.283f, 0.755f });
		mesh.vertex({ -1.917f, 1.153f, 0.680f });
		mesh.vertex({ -1.932f, 1.000f, 0.654f });
		mesh.vertex({ -1.532f, 1.000f, 1.346f });
		mesh.vertex({ -1.532f, 1.400f, 1.346f });
		mesh.vertex({ -1.532f, 1.800f, 1.346f });
		mesh.vertex({ -1.632f, 1.800f, 1.173f });
		mesh.vertex({ -1.732f, 1.800f, 1.000f });
		mesh.vertex({ -1.832f, 1.800f, 0.827f });
		mesh.vertex({ -1.932f, 1.800f, 0.654f });
		mesh.vertex({ -1.932f, 1.400f, 0.654f });
		mesh.vertex({ -1.932f, 1.000f, 0.654f });

	}

	static void faces(Mesh& mesh) {

		//// outer 
		//mesh.face({ {0, 9, 10, 1} });
		//mesh.face({ {1, 10, 11, 2} });
		//mesh.face({ {2, 11, 12, 3} });
		//mesh.face({ {3, 12, 13, 4} });
		//mesh.face({ {4, 13, 14, 5} });
		//mesh.face({ {5, 14, 15, 6} });
		//mesh.face({ {6, 15, 16, 7} });
		//mesh.face({ {7, 16, 17, 8} });

		//mesh.face({ {18, 27, 28, 19} });
		//mesh.face({ {19, 28, 29, 20} });
		//mesh.face({ {20, 29, 30, 21} });
		//mesh.face({ {21, 30, 31, 22} });
		//mesh.face({ {22, 31, 32, 23} });
		//mesh.face({ {23, 32, 33, 24} });
		//mesh.face({ {24, 33, 34, 25} });
		//mesh.face({ {25, 34, 35, 26} });

		//mesh.face({ {36, 45, 46, 37} });
		//mesh.face({ {37, 46, 47, 38} });
		//mesh.face({ {38, 47, 48, 39} });
		//mesh.face({ {39, 48, 49, 40} });
		//mesh.face({ {40, 49, 50, 41} });
		//mesh.face({ {41, 50, 51, 42} });
		//mesh.face({ {42, 51, 52, 43} });
		//mesh.face({ {43, 52, 53, 44} });

		//mesh.face({ {54, 63, 64, 55} });
		//mesh.face({ {55, 64, 65, 56} });
		//mesh.face({ {56, 65, 66, 57} });
		//mesh.face({ {57, 66, 67, 58} });
		//mesh.face({ {58, 67, 68, 59} });
		//mesh.face({ {59, 68, 69, 60} });
		//mesh.face({ {60, 69, 70, 61} });
		//mesh.face({ {61, 70, 71, 62} });

		//mesh.face({ {72, 81, 82, 73} });
		//mesh.face({ {73, 82, 83, 74} });
		//mesh.face({ {74, 83, 84, 75} });
		//mesh.face({ {75, 84, 85, 76} });
		//mesh.face({ {76, 85, 86, 77} });
		//mesh.face({ {77, 86, 87, 78} });
		//mesh.face({ {78, 87, 88, 79} });
		//mesh.face({ {79, 88, 89, 80} });

		//mesh.face({ {90, 99, 100, 91} });
		//mesh.face({ {91, 100, 101, 92} });
		//mesh.face({ {92, 101, 102, 93} });
		//mesh.face({ {93, 102, 103, 94} });
		//mesh.face({ {94, 103, 104, 95} });
		//mesh.face({ {95, 104, 105, 96} });
		//mesh.face({ {96, 105, 106, 97} });
		//mesh.face({ {97, 106, 107, 98} });

		//// outer 2

		//mesh.face({ {9, 35, 34, 10} });
		//mesh.face({ {10, 34, 33, 11} });

		//mesh.face({ {27, 53, 52, 28} });
		//mesh.face({ {28, 52, 51, 29} });

		//mesh.face({ {45, 71, 70, 46} });
		//mesh.face({ {46, 70, 69, 47} });

		//mesh.face({ {63, 89, 88, 64} });
		//mesh.face({ {64, 88, 87, 65} });

		//mesh.face({ {81, 107, 106, 82} });
		//mesh.face({ {82, 106, 105, 83} });

		//mesh.face({ {99, 17, 16, 100} });
		//mesh.face({ {100, 16, 15, 101} });

		//// inner

		//mesh.face({ {108, 117, 118, 109} });
		//mesh.face({ {109, 118, 119, 110} });
		//mesh.face({ {110, 119, 120, 111} });
		//mesh.face({ {111, 120, 121, 112} });
		//mesh.face({ {112, 121, 122, 113} });
		//mesh.face({ {113, 122, 123, 114} });
		//mesh.face({ {114, 123, 124, 115} });
		//mesh.face({ {115, 124, 125, 116} });

		//mesh.face({ {126, 135, 136, 127} });
		//mesh.face({ {127, 136, 137, 128} });
		//mesh.face({ {128, 137, 138, 129} });
		//mesh.face({ {129, 138, 139, 130} });
		//mesh.face({ {130, 139, 140, 131} });
		//mesh.face({ {131, 140, 141, 132} });
		//mesh.face({ {132, 141, 142, 133} });
		//mesh.face({ {133, 142, 143, 134} });

		//mesh.face({ {144, 153, 154, 145} });
		//mesh.face({ {145, 154, 155, 146} });
		//mesh.face({ {146, 155, 156, 147} });
		//mesh.face({ {147, 156, 157, 148} });
		//mesh.face({ {148, 157, 158, 149} });
		//mesh.face({ {149, 158, 159, 150} });
		//mesh.face({ {150, 159, 160, 151} });
		//mesh.face({ {151, 160, 161, 152} });

		//mesh.face({ {162, 171, 172, 163} });
		//mesh.face({ {163, 172, 173, 164} });
		//mesh.face({ {164, 173, 174, 165} });
		//mesh.face({ {165, 174, 175, 166} });
		//mesh.face({ {166, 175, 176, 167} });
		//mesh.face({ {167, 176, 177, 168} });
		//mesh.face({ {168, 177, 178, 169} });
		//mesh.face({ {169, 178, 179, 170} });

		//mesh.face({ {180, 189, 190, 181} });
		//mesh.face({ {181, 190, 191, 182} });
		//mesh.face({ {182, 191, 192, 183} });
		//mesh.face({ {183, 192, 193, 184} });
		//mesh.face({ {184, 193, 194, 185} });
		//mesh.face({ {185, 194, 195, 186} });
		//mesh.face({ {186, 195, 196, 187} });
		//mesh.face({ {187, 196, 197, 188} });

		//mesh.face({ {198, 207, 208, 199} });
		//mesh.face({ {199, 208, 209, 200} });
		//mesh.face({ {200, 209, 210, 201} });
		//mesh.face({ {201, 210, 211, 202} });
		//mesh.face({ {202, 211, 212, 203} });
		//mesh.face({ {203, 212, 213, 204} });
		//mesh.face({ {204, 213, 214, 205} });
		//mesh.face({ {205, 214, 215, 206} });

		//// inner 2

		//mesh.face({ {117, 143, 142, 118} });
		//mesh.face({ {118, 142, 141, 119} });

		//mesh.face({ {135, 161, 160, 136} });
		//mesh.face({ {136, 160, 159, 137} });

		//mesh.face({ {153, 179, 178, 154} });
		//mesh.face({ {154, 178, 177, 155} });

		//mesh.face({ {171, 197, 196, 172} });
		//mesh.face({ {172, 196, 195, 173} });

		//mesh.face({ {189, 215, 214, 190} });
		//mesh.face({ {190, 214, 213, 191} });

		//mesh.face({ {207, 125, 124, 208} });
		//mesh.face({ {208, 124, 123, 209} });

		// bridge

		//mesh.face({ {0, 108, 109, 1} });
		//mesh.face({ {1, 109, 110, 2} });
		//mesh.face({ {2, 110, 111, 3} });
		//mesh.face({ {3, 111, 112, 4} });
		//mesh.face({ {4, 112, 113, 5} });
		//mesh.face({ {5, 113, 114, 6} });
		//mesh.face({ {6, 114, 115, 7} });
		//mesh.face({ {7, 115, 116, 8} });

		//mesh.face({ {18, 126, 127, 19} });
		//mesh.face({ {19, 127, 128, 20} });
		//mesh.face({ {20, 128, 129, 21} });
		//mesh.face({ {21, 129, 130, 22} });
		//mesh.face({ {22, 130, 131, 23} });
		//mesh.face({ {23, 131, 132, 24} });
		//mesh.face({ {24, 132, 133, 25} });
		//mesh.face({ {25, 133, 134, 26} });

		//mesh.face({ {36, 144, 145, 37} });
		//mesh.face({ {37, 145, 146, 38} });
		//mesh.face({ {38, 146, 147, 39} });
		//mesh.face({ {39, 147, 148, 40} });
		//mesh.face({ {40, 148, 149, 41} });
		//mesh.face({ {41, 149, 150, 42} });
		//mesh.face({ {42, 150, 151, 43} });
		//mesh.face({ {43, 151, 152, 44} });

		//mesh.face({ {54, 162, 163, 55} });
		//mesh.face({ {55, 163, 164, 56} });
		//mesh.face({ {56, 164, 165, 57} });
		//mesh.face({ {57, 165, 166, 58} });
		//mesh.face({ {58, 166, 167, 59} });
		//mesh.face({ {59, 167, 168, 60} });
		//mesh.face({ {60, 168, 169, 61} });
		//mesh.face({ {61, 169, 170, 62} });

		//mesh.face({ {72, 180, 181, 73} });
		//mesh.face({ {73, 181, 182, 74} });
		//mesh.face({ {74, 182, 183, 75} });
		//mesh.face({ {75, 183, 184, 76} });
		//mesh.face({ {76, 184, 185, 77} });
		//mesh.face({ {77, 185, 186, 78} });
		//mesh.face({ {78, 186, 187, 79} });
		//mesh.face({ {79, 187, 188, 80} });

		//mesh.face({ {90, 198, 199, 91} });
		//mesh.face({ {91, 199, 200, 92} });
		//mesh.face({ {92, 200, 201, 93} });
		//mesh.face({ {93, 201, 202, 94} });
		//mesh.face({ {94, 202, 203, 95} });
		//mesh.face({ {95, 203, 204, 96} });
		//mesh.face({ {96, 204, 205, 97} });
		//mesh.face({ {97, 205, 206, 98} });


	}

};

#endif
