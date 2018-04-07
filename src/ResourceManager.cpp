#include "ResourceManager.h"

template <>
void ResourceManager::Add<Shader>(const std::string &name, Shader &resource)
{
    this->Shaders.emplace(name, std::make_shared<Shader>(resource));
}

template <>
void ResourceManager::Add<Shader>(const std::string &name, std::shared_ptr<Shader> resource){
    this->Shaders.emplace(name, resource);
}

template <>
void ResourceManager::Add<Texture>(const std::string &name, std::shared_ptr<Texture> resource){
    this->Textures.emplace(name, resource);
}

template <>
std::shared_ptr<Shader> ResourceManager::getResource<std::shared_ptr<Shader>>(const std::string &name)
{
    return this->Shaders.find(name)->second;
}

template <>
std::shared_ptr<Texture> ResourceManager::getResource<std::shared_ptr<Texture>>(const std::string &name)
{
    return this->Textures.find(name)->second;
}