#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GL/GL.h>
#include <memory>

class Texture
{
  private:    
    std::string _FilePath;
    unsigned char *_LocalBuffer;
    int _width, _height, _BPP;

  public:    
    unsigned int _RendererID;
    std::shared_ptr<unsigned int> bufforTest;
    unsigned int *_RendererID_ptr;
    Texture(const std::string &filePath);
    ~Texture();

    void Bind(unsigned int slot = 0) const;
    void Unbind() const;

    inline int GetWidth() const { return this->_width; }
    inline int GetHeight() const { return this->_height; }
};