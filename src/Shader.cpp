#include "Shader.h"

Shader::Shader(const std::string &FilePath)
    : _FilePath(FilePath), _RendererID(0)
{
    ShaderProgramSource source = ParseShader(FilePath);
    _RendererID = CreateShader(source.VertexSource, source.FragmentSource);   
}
Shader::~Shader()
{
    glDeleteProgram(_RendererID);
}

unsigned int Shader::CreateShader(const std::string &vertexShader, const std::string &fragmentShader)
{
    unsigned int program = glCreateProgram();

    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);

    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}

unsigned int Shader::CompileShader(unsigned int type, const std::string &source)
{
    unsigned int id = glCreateShader(type);
    const char *src = source.c_str();
    
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);
    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE)
    {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char *message = (char *)(alloca(length * sizeof(char)));
        glGetShaderInfoLog(id, length, &length, message);
        std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex " : "fragment ") << " shader!" << std::endl;
        std::cout << message << std::endl;
        glDeleteShader(id);
        return 0;
    }

    return id;
}

ShaderProgramSource Shader::ParseShader(const std::string &filepath)
{
    std::ifstream stream(filepath);
    
    std::string line;
    enum class ShaderType
    {
        NONE = -1,
        VERTEX = 0,
        FRAGMENT = 1
    };

    std::stringstream ss[2];
    ShaderType type = ShaderType::NONE;    
    while (getline(stream, line))
    {
        
        if (line.find("#shader") != std::string::npos)
        {
            if (line.find("vertex") != std::string::npos)
                //set vertex
                type = ShaderType::VERTEX;
            else if (line.find("fragment") != std::string::npos)
                //set fragment
                type = ShaderType::FRAGMENT;
        }
        else
        {
            ss[(int)type] << line << '\n';
           
            //std::cout<<line<<std::endl;
            
        }
    }

    return {ss[0].str(), ss[1].str()};
}

void Shader::Bind() const
{
    glUseProgram(_RendererID);
}
void Shader::Unbind() const
{
    glUseProgram(0);
}

//Set Uniforms
void Shader::SetUniform4f(const std::string &name, float v0, float v1, float v2, float v3)
{
    this->Bind();
    GetUniformLocation(name);
    glUniform4f(_location, v0, v1, v2, v3); //and set the varible
}

void Shader::SetUniform1i(const std::string &name, int value)
{
    this->Bind();
    GetUniformLocation(name);
    glUniform1i(_location, value); //and set the varible
}



unsigned int Shader::GetUniformLocation(const std::string &name)
{
    if (_UniformLocationCache.find(name) != _UniformLocationCache.end())
    {
         this->_location = _UniformLocationCache[name];
    }

    this->_location = glGetUniformLocation(this->_RendererID, name.c_str()); //I have to no location of my Uniform
   /*
    if (_location == -1)
        std::cout << "Warning uniform " << name << " doesn't exist OR never used" << std::endl;*/
}
