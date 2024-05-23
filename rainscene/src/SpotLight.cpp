#include "SpotLight.h"

SpotLight::SpotLight() : PointLight(){
    dir = glm::vec3(0.0f, -1.0f, 0.0f);
    edge = 0.0f;
    procEdge = cosf(glm::radians(edge));
}

SpotLight::SpotLight(GLfloat red, GLfloat green, GLfloat blue, 
        GLfloat aIntensity, GLfloat dIntensity,
        GLfloat xPos, GLfloat yPos, GLfloat zPos,
        GLfloat xDir, GLfloat yDir, GLfloat zDir,
        GLfloat con, GLfloat lin, GLfloat exp,
        GLfloat edg) : PointLight(red, green, blue, aIntensity, dIntensity, xPos, yPos, zPos, con, lin, exp)
{
    dir = glm::vec3(xDir, yDir, zDir);

    edge = edg;
    procEdge = cosf(glm::radians(edge));
}

SpotLight::~SpotLight() {
    
}

void SpotLight::UseLight(GLuint ambientIntensityLocation, GLuint ambientColorLocation,
                GLuint diffuseIntensityLocation, GLuint positionLocation, GLuint directionLocation,
                GLuint constantLocation, GLuint linearLocation, GLuint exponentLocation,
                GLuint edgeLocation){

    glUniform3f(ambientColorLocation, color.x, color.y, color.z);
    glUniform1f(ambientIntensityLocation, ai);
    glUniform1f(diffuseIntensityLocation, id);

    glUniform3f(positionLocation, position.x, position.y, position.z);
    glUniform1f(constantLocation, constant);
    glUniform1f(linearLocation, linear);
    glUniform1f(exponentLocation, exponent);

    glUniform3f(directionLocation, dir.x, dir.y, dir.z);
    glUniform1f(edgeLocation, procEdge);
}

void SpotLight::SetFlash(glm::vec3 pos, glm::vec3 dir){
    position = pos;
    dir = dir;
}