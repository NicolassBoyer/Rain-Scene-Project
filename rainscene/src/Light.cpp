#include "Light.h"

Light::Light()
{
    color = glm::vec3(1.0f, 1.0f, 1.0f);
    ai = 1.0f;
    id = 0.0f;
}

Light::Light(GLfloat red, GLfloat green, GLfloat blue, GLfloat aIntensity, GLfloat dIntensity)
{
    color = glm::vec3(red, green, blue);
    ai = aIntensity;

    id = dIntensity;
}

Light::~Light() {

}