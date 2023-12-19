#include <iostream>
#include "Mesh.h"
#include "GL/glut.h"
#include <math.h>
#include "Materials.h"

Mesh::Mesh() {}

Mesh::~Mesh() {}

void Mesh::vertex(float x, float y, float z) {
    vertices.push_back(x);
    vertices.push_back(y);
    vertices.push_back(z);

    std::cout << "Vertex: (" << x << ", " << y << ", " << z << ")\n";
}

void Mesh::face(int v1, int v2, int v3, int v4) {
    faces.push_back(v1);
    faces.push_back(v2);
    faces.push_back(v3);
    faces.push_back(v4);

    std::cout << "Face: " << v1 << ", " << v2 << ", " << v3 << ", " << v4 << "\n";
}

void Mesh::calculateNormals() {
    normals.clear();

    for (size_t i = 0; i < vertices.size(); i += 3) {
        normals.push_back(0.0f);
        normals.push_back(0.0f);
        normals.push_back(0.0f);
    }

    for (size_t i = 0; i < faces.size(); i += 4) { // Increment by 4 for quads
        int v1 = faces[i] * 3;
        int v2 = faces[i + 1] * 3;
        int v3 = faces[i + 2] * 3;
        int v4 = faces[i + 3] * 3;

        // Calculate face normal
        float ux = vertices[v2] - vertices[v1];
        float uy = vertices[v2 + 1] - vertices[v1 + 1];
        float uz = vertices[v2 + 2] - vertices[v1 + 2];

        float vx = vertices[v3] - vertices[v1];
        float vy = vertices[v3 + 1] - vertices[v1 + 1];
        float vz = vertices[v3 + 2] - vertices[v1 + 2];

        float nx = uy * vz - uz * vy;
        float ny = uz * vx - ux * vz;
        float nz = ux * vy - uy * vx;

        // Accumulate face normals to vertex normals
        normals[v1] += nx;
        normals[v1 + 1] += ny;
        normals[v1 + 2] += nz;

        normals[v2] += nx;
        normals[v2 + 1] += ny;
        normals[v2 + 2] += nz;

        normals[v3] += nx;
        normals[v3 + 1] += ny;
        normals[v3 + 2] += nz;

        normals[v4] += nx;
        normals[v4 + 1] += ny;
        normals[v4 + 2] += nz;
    }

    // Normalize the vertex normals
    for (size_t i = 0; i < normals.size(); i += 3) {
        float length = sqrt(normals[i] * normals[i] + normals[i + 1] * normals[i + 1] + normals[i + 2] * normals[i + 2]);
        if (length > 0.0f) {
            normals[i] /= length;
            normals[i + 1] /= length;
            normals[i + 2] /= length;
        }
    }

    std::cout << "Normals:\n";
    for (size_t i = 0; i < normals.size(); i += 3) {
        std::cout << "Normal: (" << normals[i] << ", " << normals[i + 1] << ", " << normals[i + 2] << ")\n";
    }
}

void Mesh::create() {
    glEnable(GL_COLOR_MATERIAL);
    Materials::defaultWhiteMaterial();

    calculateNormals();

    for (size_t i = 0; i < faces.size(); i += 4) {  // Increment by 4 for quads
        int v1 = faces[i] * 3;
        int v2 = faces[i + 1] * 3;
        int v3 = faces[i + 2] * 3;
        int v4 = faces[i + 3] * 3;

        glBegin(GL_QUADS);
            glNormal3f(normals[v1], normals[v1 + 1], normals[v1 + 2]);
            glVertex3f(vertices[v1], vertices[v1 + 1], vertices[v1 + 2]);

            glNormal3f(normals[v2], normals[v2 + 1], normals[v2 + 2]);
            glVertex3f(vertices[v2], vertices[v2 + 1], vertices[v2 + 2]);

            glNormal3f(normals[v3], normals[v3 + 1], normals[v3 + 2]);
            glVertex3f(vertices[v3], vertices[v3 + 1], vertices[v3 + 2]);

            glNormal3f(normals[v4], normals[v4 + 1], normals[v4 + 2]);
            glVertex3f(vertices[v4], vertices[v4 + 1], vertices[v4 + 2]);
        glEnd();

        //glBegin(GL_LINES);
        //    // Draw a line representing the normal at the centroid of the face
        //    float cx = (vertices[v1] + vertices[v2] + vertices[v3] + vertices[v4]) / 4.0f;
        //    float cy = (vertices[v1 + 1] + vertices[v2 + 1] + vertices[v3 + 1] + vertices[v4 + 1]) / 4.0f;
        //    float cz = (vertices[v1 + 2] + vertices[v2 + 2] + vertices[v3 + 2] + vertices[v4 + 2]) / 4.0f;

        //    float normalScale = 0.1f; // Adjust the length of the normal lines

        //    glVertex3f(cx, cy, cz);
        //    glVertex3f(cx + normals[v1] * normalScale, cy + normals[v1 + 1] * normalScale, cz + normals[v1 + 2] * normalScale);
        //glEnd();
    }
    glDisable(GL_COLOR_MATERIAL);
}
