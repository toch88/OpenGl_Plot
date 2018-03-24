#pragma once

#include "Renderer.h"

class Texture
{
  private:
    unsigned int _RendererID;
    std::string _FilePath;
    unsigned char *_LocalBuffer;
    int _width, _height, _BPP;

  public:
    Texture(const std::string &filePath);
    ~Texture();

    void Bind(unsigned int slot = 0) const;
    void Unbind() const;

    inline int GetWidth() const { return this->_width; }
    inline int GetHeight() const { return this->_height; }
};