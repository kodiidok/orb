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
	vector<float> emit;
};

void addMaterial(const Material& material);
void addEmissiveMaterial(const Material& material);

extern const Material WHITE_MATTE;
extern const Material DARK_GRAY_MATTE;
extern const Material GOLD_EMISSIVE;

#endif // !MATERIALS_HATERIALS_H
