
#include <iostream>
#include <math.h>
#include <vector>
#include <GL/glut.h>
#include "Castle.h"
#include "Constants.h"
#include "Utils.h"
#include "Vertices.h"

using namespace std;

vector<float> randomRotations;  // Store random rotations for each block

void initRandomRotations(int numBlocks) {
    randomRotations.clear();
    for (int i = 0; i < numBlocks; ++i) {
        randomRotations.push_back(generateRandomAngle());
    }
}

void hexagon(float centerX, float centerZ, float sideLength) {
    float angle = 60.0; // Each interior angle of a regular hexagon
    glBegin(GL_POLYGON);
    for (int i = 0; i < 6; ++i) {
        float x = centerX + sideLength * cos((angle * i) * M_PI / 180.0);
        float z = centerZ + sideLength * sin((angle * i) * M_PI / 180.0);

        // Calculate the normal
        float normalX = 0.0f;
        float normalY = 1.0f;
        float normalZ = 0.0f;

        // Set the normal
        glNormal3f(normalX, normalY, normalZ);

        glVertex3f(x, 0, z);
    }
    glEnd();
}

void hexagonBlock(float centerX, float centerZ, float sideLength, float height, float innerRadius) {

    float angle = 60.0; // Each interior angle of a regular hexagon

    for (int j = 0; j < 4; ++j) {
        glBegin(GL_QUAD_STRIP);

        for (int i = 0; i < 7; ++i) {
            float x = centerX + sideLength * cos((angle * i) * M_PI / 180.0);
            float z = centerZ + sideLength * sin((angle * i) * M_PI / 180.0);

            // Calculate the normal
            float normalX = cos((angle * i) * M_PI / 180.0);
            float normalY = 1.0f;
            float normalZ = sin((angle * i) * M_PI / 180.0);

            // Set the normal
            glNormal3f(normalX, normalY, normalZ);

            // Set the vertices
            if (j == 0) {
                glVertex3f(x, -(height / 2), z);
                glVertex3f(x, (height / 2), z);
            }
            else if (j == 1) {
                glVertex3f(x * innerRadius, -(height / 2), z * innerRadius);
                glVertex3f(x * innerRadius, (height / 2), z * innerRadius);
            }
            else if (j == 2) {
                glVertex3f(x, (height / 2), z);
                glVertex3f(x * innerRadius, (height / 2), z * innerRadius);
            }
            else if (j == 3) {
                glVertex3f(x, -(height / 2), z);
                glVertex3f(x * innerRadius, -(height / 2), z * innerRadius);
            }
        }

        glEnd();
    }
}

void arch(float centerX, float centerY, float width, float height) {
    float angle = 15.0; // Each interior angle of a regular hexagon
    float angleInc = 0.0f;
    float heightInc = 0.0f;
    float blockSize = 0.25f;

    int nBlocks = static_cast<int>(2 * height / blockSize);

    // Check if randomRotations is empty, if so, initialize it
    if (randomRotations.empty()) {
        initRandomRotations(nBlocks);
    }

    glPushMatrix();
    glTranslatef(0.0f, height, 0.0f);
    for (int i = 0; i <= 180 / angle; ++i) {
        glPushMatrix();
        glRotatef(angleInc, 0.0f, 0.0f, 1.0f);
        glTranslatef(width / 2, 0.0f, 0.0f);
        glutSolidCube(blockSize);
        glPopMatrix();

        angleInc += angle;
    }
    glPopMatrix();

    for (int i = 0; i < nBlocks / 2; i++) {
        glPushMatrix();
        glTranslatef(width / 2, heightInc, 0.0f);
        glRotatef(randomRotations[i], 0.0f, 1.0f, 0.0f);
        glutSolidCube(blockSize);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-(width / 2), heightInc, 0.0f);
        glRotatef(randomRotations[i] * 0.5, 0.0f, 1.0f, 0.0f);
        glutSolidCube(blockSize);
        glPopMatrix();

        heightInc += blockSize;
    }
}

void closedTowerBlock() {
    
}

void singleDoorTowerBlock() {

}

void twoDoorTowerBlock(){

}

void openTowerBlock(){

}

void openedTowerWall(float radius, float centerX, float centerY, float openWidth, float openHeight, float thickness) {
    float angle = 60.0f; // Each interior angle of a regular hexagon
    float inc = 0.0f;
    for (int i = 0; i < 6; ++i) {
        glPushMatrix();
        glRotatef(inc, 0.0f, 1.0f, 0.0f);
        glTranslatef(0.0f, 0.0f, radius);
        openedTowerWallPanel(centerX, centerX, openWidth, openHeight, thickness);
        glPopMatrix();
        inc += angle;
    }
}

void openedTowerWallPanel(float centerX, float centerY, float openWidth, float openHeight, float thickness) {
    float angle = 15.0; // Each interior angle of a regular hexagon
    float radius = openWidth / 2;
    float segments = 180 / angle;

    vector<Point3D> outerV;
    vector<Point3D> innerV;

    outerV.clear();
    innerV.clear();

    for (int j = 0; j < 2; ++j) {

        float offset = (j == 0) ? thickness / 2 : -thickness / 2;

        if (j == 0) {
            outerV.push_back({ 0.5f, -1.0f, offset });
            outerV.push_back({ 1.0f, -1.0f, offset });


            for (int i = 0; i <= segments; ++i) {
                float x = centerX + radius * cos((angle * i) * M_PI / 180.0);
                float _x = centerX + 2 * radius * cos((angle * i) * M_PI / 180.0);
                float y = centerY + radius * sin((angle * i) * M_PI / 180.0);

                outerV.push_back({ x, y, offset });
                outerV.push_back({ _x, 2 * openHeight, offset });
            }

            outerV.push_back({ -0.5f, -1.0f, offset });
            outerV.push_back({ -1.0f, -1.0f, offset });
        }
        else {
            innerV.push_back({ 0.5f, -1.0f, offset });
            innerV.push_back({ 1.0f, -1.0f, offset });


            for (int i = 0; i <= segments; ++i) {
                float x = centerX + radius * cos((angle * i) * M_PI / 180.0);
                float _x = centerX + 2 * radius * cos((angle * i) * M_PI / 180.0);
                float y = centerY + radius * sin((angle * i) * M_PI / 180.0);

                innerV.push_back({ x, y, offset });
                innerV.push_back({ _x, 2 * openHeight, offset });
            }

            innerV.push_back({ -0.5f, -1.0f, offset });
            innerV.push_back({ -1.0f, -1.0f, offset });
        }
    }

    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i < outerV.size(); i++) {
        glVertex3f(outerV[i].x, outerV[i].y, outerV[i].z);
    }
    glEnd();

    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i < innerV.size(); i++) {
        glVertex3f(innerV[i].x, innerV[i].y, innerV[i].z);
    }
    glEnd();

    int last = outerV.size() - 1;

    glBegin(GL_QUAD_STRIP);

    glVertex3f(outerV[2].x, outerV[2].y, outerV[2].z);
    glVertex3f(innerV[2].x, innerV[2].y, innerV[2].z);

    glVertex3f(outerV[0].x, outerV[0].y, outerV[0].z);
    glVertex3f(innerV[0].x, innerV[0].y, innerV[0].z);

    glVertex3f(outerV[1].x, outerV[1].y, outerV[1].z);
    glVertex3f(innerV[1].x, innerV[1].y, innerV[1].z);

    glVertex3f(outerV[3].x, outerV[3].y, outerV[3].z);
    glVertex3f(innerV[3].x, innerV[3].y, innerV[3].z);

    glVertex3f(outerV[last - 2].x, outerV[last - 2].y, outerV[last - 2].z);
    glVertex3f(innerV[last - 2].x, innerV[last - 2].y, innerV[last - 2].z);

    glVertex3f(outerV[last].x, outerV[last].y, outerV[last].z);
    glVertex3f(innerV[last].x, innerV[last].y, innerV[last].z);

    glVertex3f(outerV[last - 1].x, outerV[last - 1].y, outerV[last - 1].z);
    glVertex3f(innerV[last - 1].x, innerV[last - 1].y, innerV[last - 1].z);

    glVertex3f(outerV[last - 3].x, outerV[last - 3].y, outerV[last - 3].z);
    glVertex3f(innerV[last - 3].x, innerV[last - 3].y, innerV[last - 3].z);

    glEnd();

    glBegin(GL_QUAD_STRIP);
    for (int i = 2; i < last - 1; i++) {
        if (i % 2 != 0) {
            continue;
        }
        glVertex3f(outerV[i].x, outerV[i].y, outerV[i].z);
        glVertex3f(innerV[i].x, innerV[i].y, innerV[i].z);
    }
    glEnd();

}

void tower1(float radius, float centerX, float centerY, float openWidth, float openHeight, float thickness) {
    openedTowerWall(radius, centerX, centerY, openWidth, openHeight, thickness);
    glPushMatrix();
    glTranslatef(0.0f, 3.0f, 0.0f);
    openedTowerWall(radius, centerX, centerY, openWidth, openHeight, thickness);
    glPopMatrix();
}