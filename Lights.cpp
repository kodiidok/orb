
#include <vector>
#include <GL/glut.h>

#include "Lights.h"

using namespace std;

void ambientLight(
	GLenum light,
	vector<GLfloat>& amb
) {
	glEnable(light);
	glLightfv(GL_LIGHT1, GL_AMBIENT, amb.data());
}

void pointLight(
	GLenum light,
	vector<GLfloat>& pos,
	vector<GLfloat>& diff
) {
	glEnable(light);
	glLightfv(light, GL_POSITION, pos.data());
	glLightfv(light, GL_DIFFUSE, diff.data());
}
void spotLight(
	GLenum light,
	vector<GLfloat>& pos,
	vector<GLfloat>& diff,
	vector<GLfloat>& dir,
	GLfloat cutoff
) {
	glEnable(light);
	glLightfv(light, GL_POSITION, pos.data());
	glLightfv(light, GL_DIFFUSE, diff.data());
	glLightfv(light, GL_SPOT_DIRECTION, dir.data());
	glLightf(light, GL_SPOT_CUTOFF, cutoff);
}