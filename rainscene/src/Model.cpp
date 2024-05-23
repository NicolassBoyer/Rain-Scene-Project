
#define TINYOBJLOADER_IMPLEMENTATION
#include "Model.h"
//#define TINYOBJLOADER_USE_MAPBODX_EARCUT
#include <iostream>

Model::Model() {

}

Model::Model(std::vector<Texture*> textures) {
  for (size_t i = 0; i < textures.size(); i++){
    textureList.push_back(textures[i]);
  }
}

void Model::RenderModel() {
    //std::cout<<  meshList.size() << std::endl;
    for (size_t i = 0; i < meshList.size(); i++)
    {
        unsigned int matIndex = meshToTexture[i];
        if(matIndex < textureList.size() && textureList[matIndex]) {
          textureList[matIndex]->UseTexture();
        }
        meshList[i]->RenderMesh();
    }
}

void Model::LoadModel(const std::string& filePath) {
std::vector<GLfloat> vertices;
std::vector<unsigned int> indices;

tinyobj::ObjReaderConfig reader_config;
reader_config.mtl_search_path = "../obj/materials"; // Path to material files

tinyobj::ObjReader reader;

if (!reader.ParseFromFile(filePath, reader_config)) {
  if (!reader.Error().empty()) {
      std::cout << "TinyObjReader: " << reader.Error();
  }
  exit(1);
}

if (!reader.Warning().empty()) {
  std::cout << "TinyObjReader: " << reader.Warning();
}

attrib = reader.GetAttrib();
shapes = reader.GetShapes();
materials = reader.GetMaterials();

// Loop over shapes
for (size_t s = 0; s < shapes.size(); s++) {
    tinyobj::index_t idx;
    GLfloat vx;
    GLfloat vy;
    GLfloat vz;

    GLfloat nx;
    GLfloat ny;
    GLfloat nz;

    GLfloat tx;
    GLfloat ty;
    // Loop over faces(polygon)
    size_t index_offset = 0;
    for (size_t f = 0; f < shapes[s].mesh.num_face_vertices.size(); f++) {
      size_t fv = size_t(shapes[s].mesh.num_face_vertices[f]);

      // Loop over vertices in the face.
      for (size_t v = 0; v < fv; v++) {
        // access to vertex
        idx = shapes[s].mesh.indices[index_offset + v];
        vx = (GLfloat)attrib.vertices[3*size_t(idx.vertex_index)+0];
        vy = (GLfloat)attrib.vertices[3*size_t(idx.vertex_index)+1];
        vz = (GLfloat)attrib.vertices[3*size_t(idx.vertex_index)+2];

        // Check if `normal_index` is zero or positive. negative = no normal data
        if (idx.normal_index >= 0) {
          nx = (GLfloat)attrib.normals[3*size_t(idx.normal_index)+0];
          ny = (GLfloat)attrib.normals[3*size_t(idx.normal_index)+1];
          nz = (GLfloat)attrib.normals[3*size_t(idx.normal_index)+2];
        } else {
          nx = 0.0f;
          ny = 0.0f;
          nz = 0.0f;
        }

        // Check if `texcoord_index` is zero or positive. negative = no texcoord data
        if (idx.texcoord_index >= 0) {
          tx = (GLfloat)attrib.texcoords[2*size_t(idx.texcoord_index)+0];
          ty = (GLfloat)attrib.texcoords[2*size_t(idx.texcoord_index)+1];
        } else {
          tx = 0.0f;
          ty = 0.0f;
        }

        vertices.insert(vertices.end(), { vx, vy, vz });
        vertices.insert(vertices.end(), { tx, ty });
        vertices.insert(vertices.end(), {-nx, -ny, -nz});
        indices.push_back(indices.size());
      }
      index_offset += fv;

      // per-face material
      shapes[s].mesh.material_ids[f];
      meshToTexture.push_back(shapes[s].mesh.material_ids[f]);
    }
      Mesh* newMesh = new Mesh();
      newMesh->CreateMesh(&vertices[0], &indices[0], vertices.size(), indices.size());
      meshList.push_back(newMesh);
      
  }
  //LoadMaterials();
}

void Model::LoadMaterials() {
    std::cout << materials.size() << std::endl;
    textureList.resize(materials.size());

    for(size_t i = 0; i <  materials.size(); i++) {
        material_t mat = materials[i];
        textureList[i] = nullptr;

        if(mat.ambient_texname != "" || mat.specular_texname != "" || mat.diffuse_texname != "") {
        
          if (mat.ambient_texname != "") {
            std::string path = mat.ambient_texname;

            std::string texPath = std::string("../textures/") + path;

            textureList[i] = new Texture(texPath.c_str());

            if(!textureList[i]->LoadTexture()){
              printf("Failed to load texture\n");
              delete textureList[i];
              textureList[i] = nullptr;
            }
          }
          if (mat.diffuse_texname != "") {
            std::string path = mat.diffuse_texname;

            std::string texPath = std::string("../textures/") + path;

            textureList[i] = new Texture(texPath.c_str());

            if(!textureList[i]->LoadTexture()){
              printf("Failed to load texture\n");
              delete textureList[i];
              textureList[i] = nullptr;
            }
          }
          if (mat.specular_texname != "") {
            std::string path = mat.specular_texname;

            std::string texPath = std::string("../textures/") + path;

            textureList[i] = new Texture(texPath.c_str());

            if(!textureList[i]->LoadTextureA()){
              printf("Failed to load texture\n");
              delete textureList[i];
              textureList[i] = nullptr;
            }
          }
          
          if (!textureList[i])
          {
            textureList[i] = new Texture("../textures/plain.png");
            textureList[i]->LoadTextureA();
          }
      }
    }
}

void Model::ClearModel() {
    for (size_t i = 0; i = meshList.size(); i++)
    {
        if (meshList[i])
        {
            delete meshList[i];
            meshList[i] = nullptr;
        }
    }

    for (size_t i = 0; i = textureList.size(); i++)
    {
        if (meshList[i])
        {
            delete textureList[i];
            textureList[i] = nullptr;
        }
    }
}

// void Model::LoadMesh(mesh_t mesh, attrib_t attrib) {
//     // std::vector<GLfloat> vertices;
//     // std::vector<unsigned int> indices;

//     // for (auto& face_vertex : mesh.num_face_vertices) {
//     //     for (size_t i = 0; i < face_vertex; i++){
//     //         vertices.insert(vertices.end(), { mesh. })
//     //     }
//     // }
// }

Model::~Model() {

}