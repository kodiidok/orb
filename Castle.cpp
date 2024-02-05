
#include <math.h>
#include <vector>
#include <GL/glut.h>
#include "Castle.h"
#include "Constants.h"
#include "Utils.h"

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

void openedTowerWall(float centerX, float centerY, float openWidth, float openHeight) {
    float angle = 15.0; // Each interior angle of a regular hexagon
    float angleInc = 0.0f;
    float heightInc = 0.0f;
    float radius = openWidth / 2;
    float segments = 180 / angle;

    // Set polygon mode to draw wireframe
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glPushMatrix();
    glBegin(GL_QUAD_STRIP);

    glVertex3f(0.5f, -1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, 0.0f);

    for (int i = 0; i <= segments; ++i) {
        float x = centerX + radius * cos((angle * i) * M_PI / 180.0);
        float _x = centerX + 2 * radius * cos((angle * i) * M_PI / 180.0);
        float y = centerY + radius * sin((angle * i) * M_PI / 180.0);

        //// Calculate the normal
        //float normalX = 0.0f;
        //float normalY = 1.0f;
        //float normalZ = 0.0f;

        //// Set the normal
        //glNormal3f(normalX, normalY, normalZ);

        glVertex3f(x, y, 0);
        glVertex3f(_x, 2 * openHeight, 0);
    }

    glVertex3f(-0.5f, -1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 0.0f);

    glEnd();
    glPopMatrix();

    // Reset polygon mode to draw filled polygons
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

