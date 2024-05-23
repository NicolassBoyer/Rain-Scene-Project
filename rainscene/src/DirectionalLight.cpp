#include "DirectionalLight.h"

DirectionalLight::DirectionalLight() : Light()
{
    dir = glm::vec3(0.0f, -1.0f, 0.0f);
}

DirectionalLight::DirectionalLight(GLfloat red, GLfloat green, GLfloat blue, 
                                    GLfloat aIntensity, GLfloat dIntensity,
                                    GLfloat xDir, GLfloat yDir, GLfloat zDir) : Light(red, green, blue, aIntensity, dIntensity)
{
    dir = glm::vec3(xDir, yDir, zDir);
}

void DirectionalLight::UseLight(GLfloat ambientIntensityLocation, GLfloat ambientColorLocation,
GLfloat diffuseIntensityLocation, GLfloat directionLocation) {
    glUniform3f(ambientColorLocation, color.x, color.y, color.z);
    glUniform1f(ambientIntensityLocation, ai);

    glUniform3f(directionLocation, dir.x, dir.y, dir.z);
    glUniform1f(diffuseIntensityLocation, id);
}

DirectionalLight::~DirectionalLight(){
    
}