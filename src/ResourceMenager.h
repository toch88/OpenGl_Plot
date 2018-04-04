#pragma once
#include <unordered_map>
#include <memory>
#include "Texture.h"
#include "Shader.h"

class ResourceMenager
{

private:
  std::unordered_map<std::string, std::shared_ptr<Shader>> Shaders;
  std::unordered_map<std::string, std::shared_ptr<Texture>> Textures;

  ResourceMenager() {}
  ResourceMenager(ResourceMenager const &) {}
  void operator=(ResourceMenager const &) {}

public:
  static ResourceMenager &getInstance()
  {
    static ResourceMenager instance;
    return instance;
  }
  ~ResourceMenager() {}
  template <typename T>
  void Add(const std::string &name, T &resource);
  
  template <typename T>
  void Add(const std::string &name, std::shared_ptr<T> resource);

  template <typename T>
  T getResource(const std::string &name);
};
