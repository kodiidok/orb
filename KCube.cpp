
#include "KCube.h"

KCube::KCube() {}

KCube::~KCube() {}

void KCube::create(Mesh& mesh, float size) {
    float halfSize = size / 2.0f;

    // Define the vertices of the cube
    mesh.vertex(-halfSize, -halfSize, -halfSize); // Vertex 0
    mesh.vertex(halfSize, -halfSize, -halfSize);  // Vertex 1
    mesh.vertex(halfSize, halfSize, -halfSize);   // Vertex 2
    mesh.vertex(-halfSize, halfSize, -halfSize);  // Vertex 3
    mesh.vertex(-halfSize, -halfSize, halfSize);  // Vertex 4
    mesh.vertex(halfSize, -halfSize, halfSize);   // Vertex 5
    mesh.vertex(halfSize, halfSize, halfSize);    // Vertex 6
    mesh.vertex(-halfSize, halfSize, halfSize);   // Vertex 7

    // Define the faces of the cube using vertex indices
    mesh.face(0, 1, 2, 3); // front face
    mesh.face(5, 4, 7, 6); // back face
    mesh.face(4, 7, 3, 0); // left face
    mesh.face(1, 5, 6, 2); // right face
    mesh.face(0, 1, 5, 4); // bottom face
    mesh.face(3, 7, 6, 2); // top face
}
