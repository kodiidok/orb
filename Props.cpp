

#include "Props.h"
#include "Rock1.h"

#include <GL/glut.h>

void rock1() {
    Rock1 rock1;
    Mesh mesh = rock1.init();

    // Set up the model transformation
    glPushMatrix();
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    glTranslatef(0.0, 0.0, 0.0);  // Adjust translation as needed

    // Render the rock1 using the mesh data
    const auto& vertices = mesh.getVertices();
    const auto& faces = mesh.getFaces();
    //const auto& normals = mesh.getNormals();

    for (const auto& face : faces) {
        glBegin(GL_POLYGON);
        //const auto& normal = normals[face.getNormalIndex()]; // Assuming Face has a method to get normal index
        //glNormal3f(normal.x, normal.y, normal.z);

        for (const auto& vertexIndex : face.vertices) {
            const auto& vertex = vertices[vertexIndex];
            glVertex3f(vertex.x, vertex.y, vertex.z);
        }

        glEnd();
    }

    glPopMatrix();
}