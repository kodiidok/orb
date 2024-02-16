

#include "Props.h"

#include "Rock1.h"
#include "Rock2.h"
#include "Rock3.h"
#include "Rock4.h"
#include "Rock5.h"

#include "HexagonBase.h"
#include "HexagonOpenWall.h"
#include "HollowHexagonBase.h"

#include "DeformedCube.h"

#include <string>
#include <GL/glut.h>
#include "Utils.h"


void createProp(Mesh& mesh, const std::string& textureFilename = "", float rot = 0.0f) {
    if (!textureFilename.empty()) {
        GLuint textureID = Textures::loadTexture(textureFilename);
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, textureID);
    }

    // Set texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    float textureScale = 0.07f;

    // Set up the model transformation
    glPushMatrix();
    glRotatef(rot, 1.0f, 0.0f, 0.0f);
    glTranslatef(0.0, 0.0, 0.0);  // Adjust translation as needed

    // Render the rock1 using the mesh data
    const auto& vertices = mesh.getVertices();
    const auto& faces = mesh.getFaces();
    //const auto& normals = mesh.getNormals();

    // Draw labels for each vertex
    for (size_t i = 0; i < vertices.size(); ++i) {
        const auto& vertex = vertices[i];
        drawLabel(std::to_string(i), vertex.x, vertex.y, vertex.z);
    }

    // Set wireframe drawing mode
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    for (const auto& face : faces) {
        glBegin(GL_POLYGON);
        //const auto& normal = normals[face.getNormalIndex()]; // Assuming Face has a method to get normal index
        //glNormal3f(normal.x, normal.y, normal.z);

        for (const auto& vertexIndex : face.vertices) {
            const auto& vertex = vertices[vertexIndex];

            // Adjust texture coordinates based on the vertex position
            float texCoordX = vertex.x * textureScale;
            float texCoordY = vertex.y * textureScale;

            glTexCoord2f(texCoordX, texCoordY);

            glVertex3f(vertex.x, vertex.y, vertex.z);
        }

        glEnd();
    }

    // Reset drawing mode to fill
    //glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glPopMatrix();

    // Disable texture mapping if texture was bound
    if (!textureFilename.empty()) {
        glDisable(GL_TEXTURE_2D);
    }
}

void deformedCube(const std::string& textureFilename = "") {
    DeformedCube deformedCube;
    Mesh mesh = deformedCube.init();

    createProp(mesh, textureFilename, 0.0f);
}

void hexagonBase(const std::string& textureFilename = "") {
    HexagonBase hexagonBase;
    Mesh mesh = hexagonBase.init();

    createProp(mesh, textureFilename, 0.0f);
}

void hollowHexagon(const std::string& textureFilename = "") {
    HollowHexagon hollowHexagon;
    Mesh mesh = hollowHexagon.init();

    createProp(mesh, textureFilename, 0.0f);
}


void hexagonOpenWall(const std::string& textureFilename)
{
    HexagonOpenWall hexagonOpenWall;
    Mesh mesh = hexagonOpenWall.init();

    createProp(mesh, textureFilename, 0.0f);
}

void rocks() {
    glPushMatrix();
    glTranslatef(2.5f, -2.0f, 1.8f);
    glRotatef(0.0f, 0.0f, 0.0f, 0.0f);
    glScalef(1.0f, 1.0f, 1.0f);
    rock1("cliff_rocks_1_col");
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3.0f, -2.0f, 3.0f);
    glRotatef(0.0f, 0.0f, 0.0f, 0.0f);
    glScalef(1.0f, 1.0f, 1.0f);
    rock2("cliff_rocks_1_col");
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.0f, 0.0f, 1.5f);
    glRotatef(30.0f, 0.0f, 1.0f, 0.0f);
    glScalef(1.0f, 3.0f, 2.0f);
    rock4("cliff_rocks_1_col");
    glPopMatrix();
}

void rock1(const std::string& textureFilename = "") {
    Rock1 rock1;
    Mesh mesh = rock1.init();

    createProp(mesh, textureFilename, -90.0f);
}

void rock2(const std::string& textureFilename = "") {
    Rock2 rock2;
    Mesh mesh = rock2.init();

    createProp(mesh, textureFilename, -90.0f);
}

void rock3(const std::string& textureFilename = "") {
    Rock3 rock3;
    Mesh mesh = rock3.init();

    createProp(mesh, textureFilename, -90.0f);
}

void rock4(const std::string& textureFilename = "") {
    Rock4 rock4;
    Mesh mesh = rock4.init();

    createProp(mesh, textureFilename, -90.0f);
}

void rock5(const std::string& textureFilename = "") {
    Rock5 rock5;
    Mesh mesh = rock5.init();

    createProp(mesh, textureFilename, -90.0f);
}