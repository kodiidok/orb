

#include "Props.h"

#include <string>
#include <GL/glut.h>
#include "Utils.h"

void createProp(Mesh& mesh, const std::string& textureFilename = "", float rot = 0.0f) {
    if (!textureFilename.empty()) {
        GLuint textureID = Textures::loadTexture(textureFilename);
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, textureID);

        // Set texture parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    }

    float textureScale = 0.07f;

    // Set up the model transformation
    glPushMatrix();
    glRotatef(rot, 1.0f, 0.0f, 0.0f);
    glTranslatef(0.0, 0.0, 0.0);  // Adjust translation as needed

    // Render the rock1 using the mesh data
    const auto& vertices = mesh.getVertices();
    const auto& faces = mesh.getFaces();

    // Draw labels for each vertex
    //for (size_t i = 0; i < vertices.size(); ++i) {
    //    const auto& vertex = vertices[i];
    //    drawLabel(std::to_string(i), vertex.x, vertex.y, vertex.z);
    //}

    // Set wireframe drawing mode
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    for (const auto& face : faces) {
        glBegin(GL_POLYGON);
        
        // Calculate normal vector for the face using your methods
        Point3D p0 = vertices[face.vertices[0]];
        Point3D p1 = vertices[face.vertices[1]];
        Point3D p2 = vertices[face.vertices[2]];

        Normal normal = getNormal(p0, p1, p2);

        // Use normal vector as face normal
        glNormal3f(normal.x, normal.y, normal.z);

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

void stairs(float rot, int dir) {

    glPushMatrix();
    //glScalef(s.x, s.y, s.z);

    for (int i = 0; i < 5; i++) {
        glPushMatrix();
        glTranslatef(0.0f, i * -0.5f, i * 0.5f);
        glRotatef(rot * dir, 0.0f, 1.0f, 0.0f);
        
        stairsMiddle("");
        glPushMatrix();
        glTranslatef(0.85f, 0.0f, 0.0f);
        stairsSide("");
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-0.85f, 0.0f, 0.0f);
        glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
        stairsSide("");
        glPopMatrix();

        glPopMatrix();
    }

    glPopMatrix();

}

void stairsSide(const std::string& textureFilename = "") {
    StairsSide stairsSide;
    Mesh mesh = stairsSide.init();

    createProp(mesh, textureFilename, -90.0f);
}

void stairsMiddle(const std::string& textureFilename = "") {
    StairsMiddle stairsMiddle;
    Mesh mesh = stairsMiddle.init();

    createProp(mesh, textureFilename, -90.0f);
}


void wallLedge(const std::string& textureFilename = "") {
    WallLedge wallLedge;
    Mesh mesh = wallLedge.init();

    createProp(mesh, textureFilename, -90.0f);
}

void cloud1(const std::string& textureFilename = "") {
    Cloud1 cloud1;
    Mesh mesh = cloud1.init();

    createProp(mesh, textureFilename, 0.0f);
}

void cloud2(const std::string& textureFilename = "") {
    Cloud2 cloud2;
    Mesh mesh = cloud2.init();

    createProp(mesh, textureFilename, 0.0f);
}

void cloud3(const std::string& textureFilename = "") {
    Cloud3 cloud3;
    Mesh mesh = cloud3.init();

    createProp(mesh, textureFilename, 0.0f);
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

void hexagonBlock(const std::string& textureFilename = "") {
    HexagonBlock hexagonBlock;
    Mesh mesh = hexagonBlock.init();

    createProp(mesh, textureFilename, 0.0f);
}

void hollowHexagon(const std::string& textureFilename = "") {
    HollowHexagon hollowHexagon;
    Mesh mesh = hollowHexagon.init();

    createProp(mesh, textureFilename, 0.0f);
}

void hollowHexagon2(const std::string& textureFilename = "") {
    HollowHexagon2 hollowHexagon2;
    Mesh mesh = hollowHexagon2.init();

    createProp(mesh, textureFilename, 0.0f);
}

void hexagonOpenWall(const std::string& textureFilename = "")
{
    HexagonOpenWall hexagonOpenWall;
    Mesh mesh = hexagonOpenWall.init();

    createProp(mesh, textureFilename, 0.0f);
}

void hexagonWalkPath(const std::string& textureFilename = "")
{
    HexagonWalkPath hexagonWalkPath;
    Mesh mesh = hexagonWalkPath.init();

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