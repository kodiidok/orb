

#include "Props.h"
#include "Rock1.h"
#include "Rock2.h"
#include "Rock3.h"
#include "Rock4.h"
#include "Rock5.h"

#include <string>
#include <GL/glut.h>


void createProp(Mesh& mesh, const std::string& textureFilename = "") {
    if (!textureFilename.empty()) {
        GLuint textureID = Textures::loadTexture(textureFilename);
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, textureID);
    }

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

    // Disable texture mapping if texture was bound
    if (!textureFilename.empty()) {
        glDisable(GL_TEXTURE_2D);
    }
}

void rock1(const std::string& textureFilename = "") {
    Rock1 rock1;
    Mesh mesh = rock1.init();

    createProp(mesh, textureFilename);
}

void rock2(const std::string& textureFilename = "") {
    Rock2 rock2;
    Mesh mesh = rock2.init();

    createProp(mesh, textureFilename);
}

void rock3(const std::string& textureFilename = "") {
    Rock3 rock3;
    Mesh mesh = rock3.init();

    createProp(mesh, textureFilename);
}

void rock4(const std::string& textureFilename = "") {
    Rock4 rock4;
    Mesh mesh = rock4.init();

    createProp(mesh, textureFilename);
}

void rock5(const std::string& textureFilename = "") {
    Rock5 rock5;
    Mesh mesh = rock5.init();

    createProp(mesh, textureFilename);
}