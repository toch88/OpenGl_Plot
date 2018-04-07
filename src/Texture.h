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

  void Release()
  {
    glDeleteTextures(1, &_RendererID);
    _RendererID = 0;
  }

public:
  unsigned int _RendererID=0;
  std::shared_ptr<unsigned int> bufforTest;
  unsigned int *_RendererID_ptr;
  Texture(const std::string &filePath);
  Texture() {};
  Texture(const Texture&) = delete;
  Texture &operator=(const Texture &) = delete;

  Texture(Texture &&other) : _RendererID(other._RendererID)
  {
    other._RendererID = 0; //Use the "null" texture for the old object.
  }

  Texture &operator=(Texture &&other)
  {
    //ALWAYS check for self-assignment.
    if(this != &other)
    {
      this->Release();
      //obj_ is now 0.
      std::swap(_RendererID, other._RendererID);
    }
  }

  ~Texture() { this->Release(); };
  void Bind(unsigned int slot = 0) const;
  void Unbind() const;

  inline int GetWidth() const { return this->_width; }
  inline int GetHeight() const { return this->_height; }
};
