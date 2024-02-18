#include "Materials.h"

#include <vector>
#include <GL/glut.h>

using namespace std;

void addMaterial(const Material& material) {
	glMaterialfv(GL_FRONT, GL_AMBIENT, material.amb.data());
	glMaterialfv(GL_FRONT, GL_DIFFUSE, material.diff.data());
	glMaterialfv(GL_FRONT, GL_SPECULAR, material.spec.data());
	glMaterialfv(GL_FRONT, GL_SHININESS, material.shin.data());
}

void addEmissiveMaterial(const Material& material) {
	glMaterialfv(GL_FRONT, GL_AMBIENT, material.amb.data());
	glMaterialfv(GL_FRONT, GL_DIFFUSE, material.diff.data());
	glMaterialfv(GL_FRONT, GL_SPECULAR, material.spec.data());
	glMaterialfv(GL_FRONT, GL_SHININESS, material.shin.data());
	glMaterialfv(GL_FRONT, GL_EMISSION, material.emit.data());
}


// Predefined materials

const Material WHITE_MATTE = {
	{1.0f, 1.0f, 1.0f, 1.0f},  // Ambient (white)
	{1.0f, 1.0f, 1.0f, 1.0f},  // Diffuse (white)
	{0.0f, 0.0f, 0.0f, 1.0f},  // Specular (black for matte)
	{0.0f}                      // Shininess (0 for matte)
};

const Material DARK_GRAY_MATTE = {
	{0.3f, 0.3f, 0.3f, 1.0f},  // Ambient (white)
	{1.0f, 1.0f, 1.0f, 1.0f},  // Diffuse (white)
	{0.0f, 0.0f, 0.0f, 1.0f},  // Specular (black for matte)
	{0.0f}                      // Shininess (0 for matte)
};

const Material GOLD_EMISSIVE = {
	{ 0.24725f, 0.1995f, 0.0745f, 1.0f },   // Ambient color (golden)
	{ 0.75164f, 0.60648f, 0.22648f, 1.0f },  // Diffuse color (golden)
	{ 0.628281f, 0.555802f, 0.366065f, 1.0f }, // Specular color (golden)
	{ 51.2f },  // Shininess
	{ 1.0f, 0.843137f, 0.0f, 1.0f }  // Emissive color (yellow)
};