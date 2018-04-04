#include "ResourceMenager.h"

template <>
void ResourceMenager::Add<Shader>(const std::string &name, Shader &resource)
{
    this->Shaders.emplace(name, std::make_shared<Shader>(resource));
}

template <>
void ResourceMenager::Add<Shader>(const std::string &name, std::shared_ptr<Shader> resource){
    this->Shaders.emplace(name, resource);
}


template <>
void ResourceMenager::Add<Texture>(const std::string &name, Texture &resource)
{

    this->Textures.emplace(name, std::make_shared<Texture>(resource));
}

template <>
void ResourceMenager::Add<Texture>(const std::string &name, std::shared_ptr<Texture> resource){
    this->Textures.emplace(name, resource);
}

template <>
std::shared_ptr<Shader> ResourceMenager::getResource<std::shared_ptr<Shader>>(const std::string &name)
{
    return this->Shaders.find(name)->second;
}

template <>
std::shared_ptr<Texture> ResourceMenager::getResource<std::shared_ptr<Texture>>(const std::string &name)
{
    return this->Textures.find(name)->second;
}