#include "ResourceMenager.h"

template <>
void ResourceMenager::Add<Shader>(Shader &resource)
{
    this->Shaders.emplace(resource._RendererID, resource);
}

template <>
void ResourceMenager::Add<Texture>(Texture &resource)
{

    this->Textures.emplace(resource._RendererID, resource);
}

template <>
Shader ResourceMenager::getResource<Shader>(const int &ID)
{
    return this->Shaders.find(ID)->second;
}

template <>
Texture ResourceMenager::getResource<Texture>(const int &ID)
{
    return this->Textures.find(ID)->second;
}