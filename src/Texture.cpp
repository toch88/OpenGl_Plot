#include "Texture.h"
#include "vendor/stb_image/stb_image.h"

Texture::Texture(const std::string &path)
    : _FilePath(path), _LocalBuffer(nullptr), _width(0), _height(0), _BPP(0)
{
    stbi_set_flip_vertically_on_load(1);
    this->_LocalBuffer = stbi_load(path.c_str(), &(this->_width), &(this->_height), &(this->_BPP), 4);

    glGenTextures(1, &(this->_RendererID));
    
    glBindTexture(GL_TEXTURE_2D, this->_RendererID);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, this->_width, this->_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, this->_LocalBuffer);
    glGenerateMipmap(GL_TEXTURE_2D);  //Generate mipmaps now!!!
   
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
 
    this->Bind();

    if (this->_LocalBuffer)
        free(this->_LocalBuffer);
}

Texture::~Texture()
{
    glDeleteTextures(1, &(this->_RendererID));
}

void Texture::Bind(unsigned int slot) const
{
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, this->_RendererID);
}

void Texture::Unbind() const
{
    glBindTexture(GL_TEXTURE, 0);
}