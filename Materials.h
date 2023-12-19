#ifndef MATERIALS_H
#define MATERIALS_H

#include <GL/glut.h>

namespace Materials {

    inline void defaultWhiteMaterial() {
        GLfloat material_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
        GLfloat material_specular[] = { 1.0, 1.0, 1.0, 1.0 };
        GLfloat material_shininess = 50.0;
        GLfloat material_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
        GLfloat material_emission[] = { 0.0, 0.0, 0.0, 1.0 };

        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_diffuse);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_specular);
        glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, material_shininess);
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_ambient);
        glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, material_emission);
    }

}

#endif
