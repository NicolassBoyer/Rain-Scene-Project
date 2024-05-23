#ifndef MODEL
#define MODEL

#include "Mesh.h"
#include "Texture.h"
#include "tinyobjloader/tiny_obj_loader.h"

#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <string>
#include <vector>
#include <iostream>

using namespace tinyobj;

struct Vertex {
    std::vector<GLfloat> pos;
    std::vector<GLfloat> texCoord;
    std::vector<GLfloat> normals;
    std::vector<GLfloat> color;
};

class Model
{
    public:
        Model();
        Model(std::vector<Texture*> textures);
        void LoadModel(const std::string& filePath);
        void RenderModel();
        void ClearModel();

        ~Model();

    private:

    void LoadShape(std::vector<shape_t> shapes);
    void LoadMesh(mesh_t mesh);
    void LoadMaterials();

    std::vector<Mesh*> meshList;
    std::vector<Texture*> textureList;
    std::vector<unsigned int> meshToTexture;

    tinyobj::attrib_t attrib;
    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;
    std::string warn, err;

    
};

#endif