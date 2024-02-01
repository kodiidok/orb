
#include <vector>

#include <GL/glut.h>
#include "Vertices.h"
#include "Cube.h"

using namespace std;

Cube::Cube()
{
    init();
}

Cube::~Cube()
{
}

void Cube::draw() 
{
    const vector<Point3D>& v = mesh.getVertices();

    // Check if there are enough vertices to draw a cube
    if (v.size() >= 8)
    {
        glBegin(GL_QUADS);

        glNormal3f(0.0f, 0.0f, 1.0f);
        glVertex3f(v[0].x, v[0].y, v[0].z);
        glVertex3f(v[1].x, v[1].y, v[1].z);
        glVertex3f(v[2].x, v[2].y, v[2].z);
        glVertex3f(v[3].x, v[3].y, v[3].z);

        glNormal3f(1.0f, 0.0f, 0.0f);
        glVertex3f(v[1].x, v[1].y, v[1].z);
        glVertex3f(v[5].x, v[5].y, v[5].z);
        glVertex3f(v[6].x, v[6].y, v[6].z);
        glVertex3f(v[2].x, v[2].y, v[2].z);

        glNormal3f(0.0f, 0.0f, -1.0f);
        glVertex3f(v[5].x, v[5].y, v[5].z);
        glVertex3f(v[4].x, v[4].y, v[4].z);
        glVertex3f(v[7].x, v[7].y, v[7].z);
        glVertex3f(v[6].x, v[6].y, v[6].z);

        glNormal3f(-1.0f, 0.0f, 0.0f);
        glVertex3f(v[4].x, v[4].y, v[4].z);
        glVertex3f(v[0].x, v[0].y, v[0].z);
        glVertex3f(v[3].x, v[3].y, v[3].z);
        glVertex3f(v[7].x, v[7].y, v[7].z);

        glNormal3f(0.0f, 1.0f, 0.0f);
        glVertex3f(v[3].x, v[3].y, v[3].z);
        glVertex3f(v[2].x, v[2].y, v[2].z);
        glVertex3f(v[6].x, v[6].y, v[6].z);
        glVertex3f(v[7].x, v[7].y, v[7].z);

        glNormal3f(0.0f, -1.0f, 0.0f);
        glVertex3f(v[4].x, v[4].y, v[4].z);
        glVertex3f(v[5].x, v[5].y, v[5].z);
        glVertex3f(v[1].x, v[1].y, v[1].z);
        glVertex3f(v[0].x, v[0].y, v[0].z);

        glEnd();
    }
}

void Cube::init()
{
    mesh.vertex({ -0.5f, -0.5f, 0.5f });
    mesh.vertex({ 0.5f, -0.5f, 0.5f });
    mesh.vertex({ 0.5f, 0.5f, 0.5f });
    mesh.vertex({ -0.5f, 0.5f, 0.5f });

    mesh.vertex({ -0.5f, -0.5f, -0.5f });
    mesh.vertex({ 0.5f, -0.5f, -0.5f });
    mesh.vertex({ 0.5f, 0.5f, -0.5f });
    mesh.vertex({ -0.5f, 0.5f, -0.5f });
}
