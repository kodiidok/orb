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