#pragma once

#ifndef MATERIALS_H
#define MATERIALS_H

#include <vector>
#include <GL/glut.h>

using namespace std;

struct Material
{
	vector<float> amb;
	vector<float> diff;
	vector<float> spec;
	vector<float> shin;
};

void addMaterial(const Material& material);

extern const Material WHITE_MATTE;

#endif // !MATERIALS_HATERIALS_H
