#pragma once
#include <unordered_map>
#include <memory>
#include "Texture.h"
#include "Shader.h"

class ResourceManager
{

private:
  std::unordered_map<std::string, std::shared_ptr<Shader>> Shaders;
  std::unordered_map<std::string, std::shared_ptr<Texture>> Textures;

  ResourceManager() {}
  ResourceManager(ResourceManager const &) {}
  void operator=(ResourceManager const &) {}

public:
  static ResourceManager &getInstance()
  {
    static ResourceManager instance;
    return instance;
  }
  ~ResourceManager(){ 
    this->Shaders.clear();
    this->Textures.clear();
  }
  template <typename T>
  void Add(const std::string &name, T &resource);

  template <typename T>
  void Add(const std::string &name, std::shared_ptr<T> resource);

  template <typename T>
  T getResource(const std::string &name);
};
