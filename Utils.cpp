
#include <random>
#include <GL/glut.h>
#include "Utils.h"
#include "Vertices.h"

using namespace std;

// Use a constant seed value (e.g., 42)
const unsigned int seedValue = 42;

mt19937 gen(seedValue); // Standard mersenne_twister_engine seeded with rd()

float generateRandomAngle() {
    uniform_real_distribution<float> distribution(0.0f, 360.0f);
    return distribution(gen);
}

void calculateNormal(const Point3D& p1, const Point3D& p2, const Point3D& p3, float& normalX, float& normalY, float& normalZ) {
    float ux = p2.x - p1.x;
    float uy = p2.y - p1.y;
    float uz = p2.z - p1.z;

    float vx = p3.x - p1.x;
    float vy = p3.y - p1.y;
    float vz = p3.z - p1.z;

    normalX = uy * vz - uz * vy;
    normalY = uz * vx - ux * vz;
    normalZ = ux * vy - uy * vx;

    // Normalize the normal
    float length = sqrt(normalX * normalX + normalY * normalY + normalZ * normalZ);
    if (length != 0) {
        normalX /= length;
        normalY /= length;
        normalZ /= length;
    }
}

void drawLabel(string text, float x, float y, float z) {
    glColor3f(0.5f, 0.5f, 0.5f);

    // Set the raster position to a visible location
    glRasterPos3f(x, y, z);

    // Render each character in the string
    for (char character : text) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, character);
    }
}