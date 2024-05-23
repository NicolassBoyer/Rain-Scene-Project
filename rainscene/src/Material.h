#ifndef MATERIAL_H
#define MATERIAL_H

#include <GL/glew.h>

class Material
{
public:
    Material();
    ~Material();
    Material(GLfloat sIntensity, GLfloat shine);

    void UseMaterial(GLuint specularIntensityLocation, GLuint shininessLocation);

    

private:
    GLfloat specularis;
    GLfloat shininess;
};

#endif