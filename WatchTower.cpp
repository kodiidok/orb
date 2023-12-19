
#include "Mesh.h"
#include <GL/glut.h>
#include "WatchTower.h"
#include "KOctagon.h"

WatchTower::WatchTower() {}

WatchTower::~WatchTower() {}

void WatchTower::roof() {
    Mesh octagonMesh;
    KOctagon::createFlatRing(octagonMesh, 0.5, 0.25);
    
    glPushMatrix();
        glTranslatef(0.0f, 1.25f, 0.0f);
        glScalef(0.25f, 3.0f, 0.25f);
        octagonMesh.create();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.0f, 0.75f, 0.0f);
        glScalef(0.5f, 2.0f, 0.5f);
        octagonMesh.create();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.0f, 0.5f, 0.0f);
        octagonMesh.create();
    glPopMatrix();

}