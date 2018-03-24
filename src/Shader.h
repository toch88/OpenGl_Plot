#pragma once

#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>

struct ShaderProgramSource
{
    std::string VertexSource;
    std::string FragmentSource;
};
class Shader
{
  private:
    std::string _FilePath;
    unsigned int _RendererID;
    int _location;
    //caching for unforms
    std::unordered_map<std::string, unsigned int> _UniformLocationCache;

  public:
    Shader(const std::string &FilePath);
    ~Shader();

    void Bind() const;
    void Unbind() const;


    //Set Uniforms
    void SetUniform1i(const std::string &name, int value);
    void SetUniform4f(const std::string &name, float v0, float v1, float f2, float f3);

  private:
    
    unsigned int CompileShader(unsigned int type, const std::string &source);
    ShaderProgramSource ParseShader(const std::string &filepath);
    unsigned int GetUniformLocation(const std::string &name);
    unsigned int CreateShader(const std::string &vertexShader, const std::string &fragmentShader);
};