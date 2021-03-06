#pragma once
#include <iostream>
#include <vector>
#include <GL/glew.h>

struct VertexBufferElement
{
    unsigned int type;
    unsigned int count;    
    unsigned char normalized;   
    unsigned int offset; 

    static unsigned int GetSizeOfType(unsigned int type)
    {
        switch (type)
        {
        case GL_FLOAT:
            return 4;
        case GL_UNSIGNED_INT:
            return 4;
        case GL_UNSIGNED_BYTE:
            return 1;
        }
        return 0;
    }
};

class VertexBufferLayout
{
  private:
    std::vector<VertexBufferElement> _Elements;
    unsigned int _Stride;      
    unsigned int _offset;  

  public:
    VertexBufferLayout()
        : _Stride(0), _offset(0)
    {
    }

    ~VertexBufferLayout(){
        
    }

    inline toString(){
        std::vector<VertexBufferElement>::iterator it=this->_Elements.begin();
        std::cout<<"Elements :"<<std::endl;
        while(it!=this->_Elements.end()){
            std::cout<<it->normalized<<std::endl;
            std::cout<<it->offset<<std::endl;
            std::cout<<it->type<<std::endl;
        }  
    }

    template <typename T>
    void Push(unsigned int count);
    inline const std::vector<VertexBufferElement> GetElements() const & { return _Elements; }
    inline unsigned int GetStrid() const { return this->_Stride; }   
   
};
