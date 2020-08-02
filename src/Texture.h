#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>

#include <iostream>

class Texture
{
public:
    Texture(const char* path);
    ~Texture();

    void Bind(unsigned int slot = 0);
    void Unbind();


private:
    unsigned int textureID_;
    const char* filePath_;
    unsigned char *data;
    int width_, height_, nrChannels_;

};

#endif
