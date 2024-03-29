
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

void hexagon(float centerX, float centerZ, float sideLength) {

    glBegin(GL_POLYGON);
    for (int i = 0; i < 6; ++i) {
        float x = centerX + sideLength * cos(i * M_PI / 3);
        float z = centerZ + sideLength * sin(i * M_PI / 3);

        glVertex3f(x, 0, z);
    }
    glEnd();
}

vector<Point3D> hexagonStrip(float centerX, float centerZ, float radius, float height) {

    vector<Point3D> v;

    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= 6; ++i) {
        float x = centerX + radius * cos(i * M_PI / 3);
        float z = centerZ + radius * sin(i * M_PI / 3);

        glVertex3f(x, -height / 2, z);
        glVertex3f(x, height / 2, z);

        v.push_back({ x, -height / 2, z });
        v.push_back({ x, height / 2, z });
    }
    glEnd();

    return v;
}

vector<Point3D> partialHexagonStrip(int n, float centerX, float centerZ, float radius, float height) {

    vector<Point3D> v;

    float angle = 60.0f; // Each interior angle of a regular hexagon

    glBegin(GL_QUAD_STRIP);

    for (int i = 0; i <= n; i++) {
        float theta = angle * (i + 1) * M_PI / 180.0f;

        // Calculate the face normal for the current side
        float normalX = cos(theta);
        float normalZ = sin(theta);

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

    vector<Point3D> strip1 = hexagonStrip(centerX, centerZ, radius, height);
    vector<Point3D> strip2 = hexagonStrip(centerX, centerZ, innerRadius, height);

    glPushMatrix();
    glBegin(GL_QUAD_STRIP);

    for (int i = 0; i < strip1.size(); i += 2) {
        glVertex3f(strip1[i].x, strip1[i].y, strip1[i].z);
        glVertex3f(strip2[i].x, strip2[i].y, strip2[i].z);
    }

    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_QUAD_STRIP);

    for (int i = 1; i < strip1.size(); i += 2) {
        glVertex3f(strip1[i].x, strip1[i].y, strip1[i].z);
        glVertex3f(strip2[i].x, strip2[i].y, strip2[i].z);
    }

    glEnd();
    glPopMatrix();
}

void partialHexagonBlock(int n, float centerX, float centerZ, float radius, float height, float innerRadius) {

    vector<Point3D> strip1 = partialHexagonStrip(n, centerX, centerZ, radius, height);
    vector<Point3D> strip2 = partialHexagonStrip(n, centerX, centerZ, innerRadius, height);

    glBegin(GL_QUAD_STRIP);

    for (int i = 0; i < strip1.size(); i += 2) {
        glVertex3f(strip1[i].x, strip1[i].y, strip1[i].z);
        glVertex3f(strip2[i].x, strip2[i].y, strip2[i].z);
    }

    glEnd();

    glBegin(GL_QUAD_STRIP);

    for (int i = 1; i < strip1.size(); i += 2) {
        glVertex3f(strip1[i].x, strip1[i].y, strip1[i].z);
        glVertex3f(strip2[i].x, strip2[i].y, strip2[i].z);
    }

    glEnd();

    glBegin(GL_QUADS);

    glVertex3f(strip1[0].x, strip1[0].y, strip1[0].z);
    glVertex3f(strip2[0].x, strip2[0].y, strip2[0].z);
    glVertex3f(strip2[1].x, strip2[1].y, strip2[1].z);
    glVertex3f(strip1[1].x, strip1[1].y, strip1[1].z);

    glVertex3f(strip1[strip1.size() - 1].x, strip1[strip1.size() - 1].y, strip1[strip1.size() - 1].z);
    glVertex3f(strip2[strip1.size() - 1].x, strip2[strip1.size() - 1].y, strip2[strip1.size() - 1].z);
    glVertex3f(strip2[strip1.size() - 2].x, strip2[strip1.size() - 2].y, strip2[strip1.size() - 2].z);
    glVertex3f(strip1[strip1.size() - 2].x, strip1[strip1.size() - 2].y, strip1[strip1.size() - 2].z);

    glEnd();

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

    for (int i = 0; i < 6; ++i) {
        glPushMatrix();

        // Calculate the position in a circle
        float angle = i * (M_PI / 3);  // 60 degrees in radians
        float x = d * cos(angle);
        float z = d * sin(angle);

        // Translate to the calculated position
        glTranslatef(x, 0.0f, z);

        // Calculate the rotation angle to face the origin
        float rotationAngle = atan2(-x, -z) * (180.0f / M_PI);

        // Rotate around the Y-axis to face the origin
        glRotatef(rotationAngle, 0.0f, 1.0f, 0.0f);

        vector<Point3D> archSeam = openArch(h, cx, cy, -cz, radius, segments, thickness);
        arches.push_back(archSeam);

        glPopMatrix();
    }

    return arches;
}

void wallDecoTop(Scale s) {
    glPushMatrix();
    glScalef(s.x * 1.0f, s.y * 1.0f, s.z * 1.0f);

    glTranslatef(-0.5f, 0.0f, 0.0f);
    for (int i = 0; i < 5; i++) {
        glPushMatrix();

        if (i == 0 || i == 4) {
            glTranslatef(0.0f, -0.9f, 0.0f);
            glScalef(1.0f, 10.0f, 1.0f);
        }

        glTranslatef(i * 0.25f, 0.0f, 0.0f);
        glutSolidCube(0.2f);
        glPopMatrix();
    }

    glPopMatrix();
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

vector<vector<Point3D>> hexagonWallPanelAllOpenArch(float w, float h, float cx, float cy, float cz, float radius, int segments) {

    vector<vector<Point3D>> sides;
    
    float d = (radius + w) * tan(60.f * M_PI / 180.0f);

    for (int i = 0; i < 6; ++i) {
        glPushMatrix();

        // Calculate the position in a circle
        float angle = i * (M_PI / 3);  // 60 degrees in radians
        float x = d * cos(angle);
        float z = d * sin(angle);

        // Translate to the calculated position
        glTranslatef(x, 0.0f, z);

        // Calculate the rotation angle to face the origin
        float rotationAngle = atan2(-x, -z) * (180.0f / M_PI);

        // Rotate around the Y-axis to face the origin
        glRotatef(rotationAngle, 0.0f, 1.0f, 0.0f);

        wallPanelOpenArch(w, h, cx, cy,cz, radius, segments);

        glPopMatrix();
    }

    return sides;
}

void hexagonWallRingAllOpenArch(float w, float h, float cx, float cy, float cz, float radius, int segments, float thickness) {

    float offset = thickness / tan(60.f * M_PI / 180.0f);
    float d = (radius + w) * tan(60.f * M_PI / 180.0f);

    vector<vector<Point3D>> ring1 = hexagonWallPanelAllOpenArch(w, h, cx, cy, cz, radius, segments);
    vector<vector<Point3D>> ring2 = hexagonWallPanelAllOpenArch(w + offset, h, cx, cy, cz, radius, segments);

    hexagonOpenArch(h, cx, cy, cz, radius, segments, -thickness, d);

}

vector<vector<Point3D>> hexagonWallDecoTop(float length, Scale s) {

    vector<vector<Point3D>> sides;

    float d = (length) * tan(60.f * M_PI / 180.0f);

    for (int i = 0; i < 6; ++i) {
        glPushMatrix();

        // Calculate the position in a circle
        float angle = i * (M_PI / 3);  // 60 degrees in radians
        float x = d * cos(angle);
        float z = d * sin(angle);

        // Translate to the calculated position
        glTranslatef(x, 0.0f, z);

        // Calculate the rotation angle to face the origin
        float rotationAngle = atan2(-x, -z) * (180.0f / M_PI);

        // Rotate around the Y-axis to face the origin
        glRotatef(rotationAngle, 0.0f, 1.0f, 0.0f);

        wallDecoTop(s);

        glPopMatrix();
    }

    return sides;
}

void hexagonFloor(float cx, float cz, float sideLength) {
    hexagon(cx, cz, sideLength);
}

void towerBlock(Scale s) {
    glPushMatrix();
    glScalef(s.x * 1.0f, s.y * 1.0f, s.z * 1.0f);

    glPushMatrix();
    glTranslatef(0.0f, 1.0f, 0.0f);
    glRotatef(-210.0f, 0.0f, 1.0f, 0.0f);
    hexagonBlock(0.0f, 0.0f, 2.5f, 0.25f, 0.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 0.8f, 0.0f);
    hexagonWallDecoTop(1.15f, { 1.5f, 1.0f, 1.0f });
    glPopMatrix();

    hexagonWallRingAllOpenArch(0.7f, 1.0f, 0.0f, 0.0f, 0.0f, 0.3f, 16, 0.25f);

    glPushMatrix();
    glTranslatef(0.0f, -1.0f, 0.0f);
    glRotatef(-210.0f, 0.0f, 1.0f, 0.0f);
    hexagonBlock(0.0f, 0.0f, 2.5f, 0.25f, 2.0f);
    glPopMatrix();

    glPopMatrix();
}

void tower3(Scale s) {
    
    glPushMatrix();
    glScalef(s.x, s.y, s.z);

    glPushMatrix();
    glTranslatef(0.0f, 5.0f, 0.0f);
    towerBlock({ 1.0f, 1.0f, 1.0f });
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 3.0f, 0.0f);
    towerBlock({ 1.0f, 1.0f, 1.0f });
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 1.0f, 0.0f);
    towerBlock({ 1.0f, 1.0f, 1.0f });
    glPopMatrix();

    glPopMatrix();

}

void railing(float scale) {
    glPushMatrix();
    glScalef(scale * 1.0f, scale * 1.0f, scale * 1.0f);

    glPushMatrix();
    glScalef(1.0f, 0.5f, 0.3f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    glScalef(0.25f, 0.6f, 0.4f);
    glTranslatef(-1.5f, 0.0f, 0.0f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    glScalef(0.25f, 0.6f, 0.4f);
    glTranslatef(1.5f, 0.0f, 0.0f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.375f, 0.3f, 0.0f);
    glScalef(0.1f, 0.1f, 0.1f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.375f, 0.3f, 0.0f);
    glScalef(0.1f, 0.1f, 0.1f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPopMatrix();
}

void stairs(Scale s) {

    glPushMatrix();
    glScalef(s.x, s.y, s.z);

    for (int i = 0; i < 5; i ++) {
        glPushMatrix();
        glTranslatef(0.0f, i * -0.5f, i * 1.0f);
        glutSolidCube(1.0f);
        glPopMatrix();
    }

    glPopMatrix();
}
