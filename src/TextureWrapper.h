#include <GL/glew.h>
#include <GL/GL.h>
#include <iostream>
class TextureWrapper
{
  private:
    void Release();

  public:
    unsigned int _RendererID = 0;
    TextureWrapper(){};
    TextureWrapper(const TextureWrapper &) = delete;
    TextureWrapper &operator=(const TextureWrapper &) = delete;
    TextureWrapper &operator=(TextureWrapper &&other);
    TextureWrapper(TextureWrapper &&other);
    ~TextureWrapper();   
};