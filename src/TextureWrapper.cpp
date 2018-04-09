#include "TextureWrapper.h"

void TextureWrapper::Release()
{
    glDeleteTextures(1, &(this->_RendererID));
    this->_RendererID = 0;
}

TextureWrapper &TextureWrapper::operator=(TextureWrapper &&other)
{
    //ALWAYS check for self-assignment.
    if (this != &other)
    {
        this->Release();
        //obj_ is now 0.
        std::swap(_RendererID, other._RendererID);
    }
}

TextureWrapper::TextureWrapper(TextureWrapper &&other) : _RendererID(other._RendererID)
{
    other._RendererID = 0; //Use the "null" TextureWrapper for the old object.
}

TextureWrapper::~TextureWrapper()
{
    this->Release();
};