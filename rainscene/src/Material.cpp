#include "Material.h"

Material::Material() {
    specularis = 0.0f;
    shininess = 0.0f;
}

Material::Material(GLfloat sIntensity, GLfloat shine){
    specularis = sIntensity;
    shininess = shine;
}

void Material::UseMaterial(GLuint specularIntensityLocation, GLuint shininessLocation){
    glUniform1f(specularIntensityLocation, specularis);
    glUniform1f(shininessLocation, shininess);
}

Material::~Material(){

}