#pragma once

#ifndef CUBE_H
#define CUBE_H

#include "Mesh.h"

class Cube
{
public:
	Cube();
	~Cube();
	void draw();

private:
	Mesh mesh;
	void init();
};

#endif

