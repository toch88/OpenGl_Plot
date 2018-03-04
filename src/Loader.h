#pragma once
#include "RawModel.h"
#include <memory>
#include <array>

class Loader
{
  public:
    Loader();
    ~Loader();

  public:
    std::shared_ptr<RawModel> loadToVAO(const void *position, const void *color);

    template <typename _Tp, std::size_t _Nm>
    std::shared_ptr<RawModel> loadToVAO(std::array<_Tp, _Nm> & position, const void *)
    {
        VertexArray *vao = new VertexArray();
        vao->Bind();
        VertexBuffer *vbo = new VertexBuffer(position._M_elems, sizeof(_Tp) * position.size());
        VertexBufferLayout layout;
        layout.Push<_Tp>(2);
        vao->AddBuffer(vbo, layout);
        std::shared_ptr<RawModel> rawModel(new RawModel());
        rawModel->addVAO(vao);
        return rawModel;
    }

  private:
    VertexArray createVAO(const void *position, const void *color);
};

template <typename V, typename... T>
constexpr auto array_of(T &&... t)
    -> std::array<V, sizeof...(T)>
{
    return {{std::forward<T>(t)...}};
}
