
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <GL/glut.h>
#include "Constants.h"
#include "Utils.h"
#include "Vertices.h"
#include "Castle.h"

using namespace std;

vector<float> randomRotations;  // Store random rotations for each block

void initRandomRotations(int numBlocks) {
    randomRotations.clear();
    for (int i = 0; i < numBlocks; ++i) {
        randomRotations.push_back(generateRandomAngle());
    }
}

void hexagon(float centerX, float centerZ, float sideLength, int flipNorm = 1) {
    float angle = 60.0; // Each interior angle of a regular hexagon
    glBegin(GL_POLYGON);
    for (int i = 0; i < 6; ++i) {
        float x = centerX + sideLength * cos((angle * i) * M_PI / 180.0);
        float z = centerZ + sideLength * sin((angle * i) * M_PI / 180.0);

        float theta = angle * i * M_PI / 180.0f;

        // Calculate the face normal for the current side
        float normalX = flipNorm * cos(theta);
        float normalY = 1.0f;
        float normalZ = flipNorm * sin(theta);

        // Normalize the face normal
        float length = sqrt(normalX * normalX + normalY * normalY + normalZ * normalZ);
        normalX /= length;
        normalZ /= length;

        glNormal3f(normalX, normalY, normalZ);

        glVertex3f(x, 0, z);
    }
    glEnd();
}

vector<Point3D> hexagonStrip(float centerX, float centerZ, float radius, float height, int flipNorm = 1) {

    vector<Point3D> v;

    float angle = 60.0f; // Each interior angle of a regular hexagon

    glBegin(GL_QUAD_STRIP);

    for (int i = 0; i <= 6; i++) {
        float theta = angle * (i + 1) * M_PI / 180.0f;

        // Calculate the face normal for the current side
        float normalX = flipNorm * cos(theta);
        float normalZ = flipNorm * sin(theta);

        // Normalize the face normal
        float length = sqrt(normalX * normalX + normalZ * normalZ);
        normalX /= length;
        normalZ /= length;

        glNormal3f(normalX, 0.0f, normalZ);

        Point3D p1 = { centerX + radius * cos(theta), -height / 2, centerZ + radius * sin(theta) };
        Point3D p2 = { centerX + radius * cos(theta), height / 2, centerZ + radius * sin(theta) };

        glVertex3f(p1.x, p1.y, p1.z);
        glVertex3f(p2.x, p2.y, p2.z);

        v.push_back(p1);
        v.push_back(p2);

    }

    glEnd();

    return v;
}

void hexagonBlock(float centerX, float centerZ, float radius, float height, float innerRadius) {

    vector<Point3D> strip1 = hexagonStrip(centerX, centerZ, radius, height, 1.0f);
    vector<Point3D> strip2 = hexagonStrip(centerX, centerZ, innerRadius, height, -1.0f);

    glPushMatrix();
    glBegin(GL_QUAD_STRIP);

    for (int i = 0; i < strip1.size(); i += 2) {
        glNormal3f(0.0f, -1.0f, 0.0f);

        glVertex3f(strip1[i].x, strip1[i].y, strip1[i].z);
        glVertex3f(strip2[i].x, strip2[i].y, strip2[i].z);
    }

    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_QUAD_STRIP);

    for (int i = 1; i < strip1.size(); i += 2) {
        glNormal3f(0.0f, 1.0f, 0.0f);

        glVertex3f(strip1[i].x, strip1[i].y, strip1[i].z);
        glVertex3f(strip2[i].x, strip2[i].y, strip2[i].z);
    }

    glEnd();
    glPopMatrix();
}

void arch(float centerX, float centerY, float width, float height) {
    float angle = 30.0;
    float angleInc = 0.0f;
    float heightInc = 0.0f;
    float blockSize = 0.2f;

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

vector<Point3D> circle(float centerx, float centery, float z, float radius, int segments) {
    vector<Point3D> v;

    for (int i = 0; i < segments; ++i) {
        float theta = 2.0f * M_PI * float(i) / float(segments);  // Angle for each segment
        float x = centerx + radius * cos(theta);
        float y = centery + radius * sin(theta);
        Point3D p = { x, y, z };
        v.push_back(p);
    }

    return v;
}

vector<Point3D> drawCircle(GLenum mode, float centerx, float centery, float z, float radius, int segments) {
    vector<Point3D> circ_coord = circle(centerx, centery, z, radius, segments);
    glBegin(mode);
    for (size_t i = 0; i < circ_coord.size(); ++i) {
        const Point3D& c = circ_coord[i];
        float x = c.x;
        float y = c.y;
        float z = c.z;
        std::cout << "v" << i << ":\t" << x << ", " << y << ", " << z << '\n';
        glVertex3f(x, y, z);
    }
    glEnd();
    return circ_coord;
}

vector<Point3D> semiCircle(float centerx, float centery, float z, float radius, int segments) {
    vector<Point3D> v;

    for (int i = 0; i < 1 + (segments / 2); ++i) {
        float theta = 2.0f * M_PI * float(i) / float(segments);  // Angle for each segment
        float x = centerx + radius * cos(theta);
        float y = centery + radius * sin(theta);
        Point3D p = { x, y, z };
        v.push_back(p);
    }

    return v;
}

vector<Point3D> drawSemiCircle(GLenum mode, float centerx, float centery, float z, float radius, int segments) {
    vector<Point3D> semicirc_coord = semiCircle(centerx, centery, z, radius, segments);
    glBegin(mode);
    for (size_t i = 0; i < semicirc_coord.size(); ++i) {
        const Point3D& c = semicirc_coord[i];
        float x = c.x;
        float y = c.y;
        float z = c.z;
        std::cout << "v" << i << ":\t" << x << ", " << y << ", " << z << '\n';
        glVertex3f(x, y, z);
    }
    glEnd();
    return semicirc_coord;
}

vector<Point3D> openArch(float h, float cx, float cy, float cz, float radius, int segments, float thickness) {

    vector<Point3D> sc1 = semiCircle(cx, cy, cz, radius, segments);
    vector<Point3D> sc2 = semiCircle(cx, cy, cz + thickness, radius, segments);

    // Add an element to the beginning
    sc1.insert(sc1.begin(), { sc1[0].x, -h, cz });
    sc2.insert(sc2.begin(), { sc2[0].x, -h, cz + thickness });

    // Add an element to the end
    sc1.push_back({ sc1[sc1.size() - 1].x, -h, cz });
    sc2.push_back({ sc2[sc2.size() - 1].x, -h, cz + thickness });

    vector<Point3D> result;

    glBegin(GL_QUAD_STRIP);
    for (size_t i = 0; i < sc1.size(); i++) {
        const Point3D& c1 = sc1[i];
        float x1 = c1.x;
        float y1 = c1.y;
        float z1 = c1.z;

        const Point3D& c2 = sc2[i];
        float x2 = c2.x;
        float y2 = c2.y;
        float z2 = c2.z;

        if (i < 1) {
            glNormal3f(1.0f, 0.0f, 0.0f);
        }
        else if (i < sc1.size() - 1) {
            float angle = 2.0f * M_PI * float(i) / float(segments);

            // Calculate the normal vector for the first face
            float new_x = 0.0f;
            float new_y = 0.0f;
            float new_z = -1.0f;

            // Rotate the normal vector around the y-axis by 60 degrees
            float radians = angle * (i - 1) * (3.14159f / 180.0f);
            float rotated_x = cos(radians) * new_x - sin(radians) * new_z;
            float rotated_y = new_y;
            float rotated_z = sin(radians) * new_x + cos(radians) * new_z;

            // Normalize the rotated normal vector
            float length = sqrt(rotated_x * rotated_x + rotated_y * rotated_y + rotated_z * rotated_z);
            rotated_x /= length;
            rotated_y /= length;
            rotated_z /= length;

            // Set the normal vector for lighting calculations
            glNormal3f(rotated_x, rotated_y, rotated_z);
        }
        else {
            glNormal3f(1.0f, 0.0f, 0.0f);
        }

        glVertex3f(x1, y1, z1);
        glVertex3f(x2, y2, z2);
        result.push_back({ x1, y1, z1 });
        result.push_back({ x2, y2, z2 });
    }
    glEnd();

    return result;
}

vector<vector<Point3D>> hexagonOpenArch(float h, float cx, float cy, float cz, float radius, int segments, float thickness, float d) {

    vector<vector<Point3D>> arches;
    float angle = 60.0; // Each interior angle of a regular hexagon

    for (int i = 0; i < 6; ++i) {

        glPushMatrix();
        glRotatef(angle * i, 0.0f, 1.0f, 0.0f);
        glTranslatef(0.0f, 0.0f, d);
        glRotatef(180.0f, 0.0f, 1.0f, 0.0f);

        vector<Point3D> archSeam = openArch(h, cx, cy, -cz, radius, segments, thickness);
        arches.push_back(archSeam);
        glPopMatrix();

    }

    return arches;
}

vector<Point3D> wallPanelOpenArch(float w, float h, float cx, float cy, float cz, float radius, int segments) {
    vector<Point3D> sc = semiCircle(cx, cy, cz, radius, segments);

    // Add an element to the beginning
    sc.insert(sc.begin(), { sc[0].x, -h, cz });

    // Add an element to the end
    sc.push_back({ sc[sc.size() - 1].x, -h, cz });

    vector<Point3D> result;

    size_t changer = sc.size() / 4;

    float offsetx = (radius + w) / changer;
    float offsetyu = -h;
    float offsetyd = 0.0f;

    glBegin(GL_QUAD_STRIP);
    for (size_t i = 0; i < sc.size(); i++) {
        const Point3D& c = sc[i];
        float x = c.x;
        float y = c.y;
        float z = c.z;

        glVertex3f(x, y, z);
        result.push_back({ x, y, z });

        if (i <= changer + 1) {
            glVertex3f(radius + w, cy + offsetyu, z);
            result.push_back({ radius + w, cy + offsetyu, z });
            if (i == 0) {
                offsetyu += 2 * (h / changer);
            }
            else {
                offsetyu += h / changer;
            }
        }
        else if (i < 3 * changer + 1) {
            glVertex3f(radius + w - offsetx, h, z);
            result.push_back({ radius + w - offsetx, h, z });
            offsetx += (w + radius) / changer;
        }
        else {
            glVertex3f(-(radius + w), h - offsetyd, z);
            result.push_back({ -(radius + w), h - offsetyd, z });
            if (i == sc.size() - 2) {
                offsetyd += 2 * (h / changer);
            }
            else {
                offsetyd += h / changer;
            }
        }
    }
    glEnd();

    return result;
}

vector<vector<Point3D>> hexagonWallPanelAllOpenArch(float w, float h, float cx, float cy, float cz, float radius, int segments, int flipNorm) {

    vector<vector<Point3D>> sides;
    float angle = 60.0; // Each interior angle of a regular hexagon
    float d = (radius + w) * tan(60.f * M_PI / 180.0f);

    for (int i = 0; i < 6; ++i) {

        glPushMatrix();
        glRotatef(angle * i, 0.0f, 1.0f, 0.0f);
        glTranslatef(0.0f, 0.0f, d);
        glRotatef(180.0f, 0.0f, 1.0f, 0.0f);

        // Calculate the normal vector for the first face
        float new_x = 0.0f;
        float new_y = 0.0f;
        float new_z = -1.0f;

        // Rotate the normal vector around the y-axis by 60 degrees
        float radians = angle * i * (3.14159f / 180.0f);
        float rotated_x = cos(radians) * new_x - sin(radians) * new_z;
        float rotated_y = new_y;
        float rotated_z = sin(radians) * new_x + cos(radians) * new_z;

        // Normalize the rotated normal vector
        float length = sqrt(rotated_x * rotated_x + rotated_y * rotated_y + rotated_z * rotated_z);
        rotated_x /= length;
        rotated_y /= length;
        rotated_z /= length;

        // Set the normal vector for lighting calculations
        glNormal3f(flipNorm * rotated_x, flipNorm * rotated_y, flipNorm * rotated_z);

        vector<Point3D> side = wallPanelOpenArch(w, h, cx, cy, -cz, radius, segments);
        sides.push_back(side);
        glPopMatrix();

    }

    return sides;
}

void hexagonWallRingAllOpenArch(float w, float h, float cx, float cy, float cz, float radius, int segments, float thickness) {

    float offset = thickness / tan(60.f * M_PI / 180.0f);
    float d = (radius + w) * tan(60.f * M_PI / 180.0f);

    vector<vector<Point3D>> ring1 = hexagonWallPanelAllOpenArch(w, h, cx, cy, cz, radius, segments, 1.0f);
    vector<vector<Point3D>> ring2 = hexagonWallPanelAllOpenArch(w + offset, h, cx, cy, cz, radius, segments, -1.0f);

    hexagonOpenArch(h, cx, cy, cz, radius, segments, -thickness, d);

}

void hexagonFloor(float cx, float cz, float sideLength) {
    hexagon(cx, cz, sideLength);
}

void tower3(float scale = 1.0f) {
    glPushMatrix();
    glScalef(scale * 1.0f, scale * 1.0f, scale * 1.0f);

    glPushMatrix();
    glTranslatef(0.0f, 4.0f, 0.0f);
    glScalef(0.75f, 1.0f, 0.75f);
    hexagonWallRingAllOpenArch(0.7f, 1.0f, 0.0f, 0.0f, 0.0f, 0.3f, 16, 0.25f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 3.0f, 0.0f);
    hexagonBlock(0.0f, 0.0f, 2.5f, 0.25f, 0.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -1.0f, 0.0f);
    hexagonBlock(0.0f, 0.0f, 2.5f, 0.25f, 0.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 2.0f, 0.0f);
    hexagonWallRingAllOpenArch(0.7f, 1.0f, 0.0f, 0.0f, 0.0f, 0.3f, 16, 0.25f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 1.0f, 0.0f);
    hexagonBlock(0.0f, 0.0f, 2.5f, 0.25f, 1.8f);
    glPopMatrix();

    hexagonWallRingAllOpenArch(0.7f, 1.0f, 0.0f, 0.0f, 0.0f, 0.3f, 16, 0.25f);

    glPushMatrix();
    glTranslatef(0.0f, -1.0f, 0.0f);
    hexagonBlock(0.0f, 0.0f, 2.5f, 0.25f, 0.0f);
    glPopMatrix();
    
    glPopMatrix();
}