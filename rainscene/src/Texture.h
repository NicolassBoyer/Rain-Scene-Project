#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>

#include "learnopengl/stb_image.h"

class Texture
{
    public:
        Texture();
        ~Texture();
        Texture(const char* fileLoc);

        bool LoadTexture();
        bool LoadTextureA();

        void UseTexture();
        void ClearTexture();

        

private:
    GLuint textureID;
    int w, h, bitDepth;

    const char* fileLocation;
};

#endif