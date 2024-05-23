#ifndef MESH_H
#define MESH_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

class Mesh
{
public:
    Mesh();
    ~Mesh();
    void CreateMesh(GLfloat *vertices, unsigned int *indices, unsigned int numOfVertices, unsigned int numOfIndices);
    //void CreateMesh(tinyobj::real_t *vertices, unsigned int *indices, size_t numOfVertices, size_t numOfIndices);
    void RenderMesh();
    void ClearMesh();

private:
    GLuint VAO, VBO, IBO;
    GLsizei indexCount;
    
};

#endif