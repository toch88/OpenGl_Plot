#pragma once
#include <unordered_map>
#include <memory>
#include "Texture.h"
#include "Shader.h"

class ResourceMenager
{

  private:
    std::unordered_map<int, Shader> Shaders;
    std::unordered_map<int, Texture> Textures;

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
    void Add(T &resource);

    template <typename T>
    T getResource(const int &ID);
};



