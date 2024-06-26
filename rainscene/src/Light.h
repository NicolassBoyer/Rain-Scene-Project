#ifndef LIGHT_H
#define LIGHT_H

#include <GL/glew.h>
#include <glm/glm.hpp>

class Light
{
public: 
    Light();
    ~Light();
    Light(GLfloat red, GLfloat green, GLfloat blue, 
            GLfloat aIntensity, GLfloat dIntensity);

    

protected:
    glm::vec3 color;
    GLfloat ai;
    GLfloat id;
};

#endif