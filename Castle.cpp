
#include <math.h>
#include <GL/glut.h>
#include "Castle.h"
#include "Constants.h"

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




