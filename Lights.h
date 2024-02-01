#pragma once

#ifndef LIGHTS_H
#define LIGHTS_H

#include <vector>
#include <GL/glut.h>

using namespace std;

void ambientLight(GLenum light, vector<GLfloat>& amb);
void pointLight(GLenum light, vector<GLfloat>& pos, vector<GLfloat>& diff);
void spotLight(GLenum light, vector<GLfloat>& pos, vector<GLfloat>& diff, vector<GLfloat>& dir, GLfloat cutoff);

#endif // !LIGHTS_H
