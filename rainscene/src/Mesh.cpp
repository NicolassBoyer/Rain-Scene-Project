#include "Mesh.h"

Mesh::Mesh()
{
    VAO = 0;
    VBO = 0;
    IBO = 0;
    indexCount = 0;
}

void Mesh::CreateMesh(GLfloat *vertices, unsigned int *indices, unsigned int numOfVertices, unsigned int numOfIndices)
{
    //fprintf(stderr, "Index Count:\n");
    indexCount = numOfIndices;

    //fprintf(stderr, "Vertex Arrays:\n");

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    //fprintf(stderr, "Buffers:\n");
    glGenBuffers(1, &IBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices[0]) * numOfIndices, indices, GL_STATIC_DRAW);

    //fprintf(stderr, "Buffers 2:\n");
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * numOfVertices, vertices, GL_STATIC_DRAW);

    //fprintf(stderr, "Pointers:\n");
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertices[0]) * 8, 0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(vertices[0]) * 8, (void*)(sizeof(vertices[0]) * 3));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(vertices[0]) * 8, (void*)(sizeof(vertices[0]) * 5));
    glEnableVertexAttribArray(2);

    //fprintf(stderr, "Bind Buffers:\n");
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    glBindVertexArray(0);
}

// void Mesh::CreateMesh(tinyobj::real_t *vertices, unsigned int *indices, size_t numOfVertices, size_t numOfIndices)
// {
//     //fprintf(stderr, "Index Count:\n");
//     indexCount = numOfIndices;

//     //fprintf(stderr, "Vertex Arrays:\n");

//     glGenVertexArrays(1, &VAO);
//     glGetError();
//     glBindVertexArray(VAO);
//     glGetError();

//     //fprintf(stderr, "Buffers:\n");
//     glGenBuffers(1, &IBO);
//     glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
//     glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices[0]) * numOfIndices, indices, GL_STATIC_DRAW);

//     //fprintf(stderr, "Buffers 2:\n");
//     glGenBuffers(1, &VBO);
//     glBindBuffer(GL_ARRAY_BUFFER, VBO);
//     glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * numOfVertices, vertices, GL_STATIC_DRAW);

//     //fprintf(stderr, "Pointers:\n");
//     glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertices[0]) * 8, 0);
//     glEnableVertexAttribArray(0);
//     // glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(texCoords[0]) * 8, 0);
//     // glEnableVertexAttribArray(1);
//     // glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(normals[0]) * 8, 0);
//     // glEnableVertexAttribArray(2);

//     //fprintf(stderr, "Bind Buffers:\n");
//     glBindBuffer(GL_ARRAY_BUFFER, 0);
//     glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

//     glBindVertexArray(0);
// }

void Mesh::RenderMesh() 
{
    //fprintf(stderr, "Rendering mesh:\n");
    glBindVertexArray(VAO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
    glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Mesh::ClearMesh()
{
    if (IBO != 0)
    {
        glDeleteBuffers(1, &IBO);
        IBO = 0;
    }

    if (VBO != 0)
    {
        glDeleteBuffers(1, &VBO);
        VBO = 0;
    }

    if (VAO != 0)
    {
        glDeleteBuffers(1, &VAO);
        VAO = 0;
    }

    indexCount = 0;
}

Mesh::~Mesh() 
{
    ClearMesh();
}