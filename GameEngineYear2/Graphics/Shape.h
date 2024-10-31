#pragma once
#include <map>
#include <string>
#include "Renderer.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Texture.h"
#include "Shader.h"
#include "VertexBufferLayout.h"
#include "Engine/Component.h"
namespace Graphics
{

    class Shape : public GameEngine::Component
    {
    private:
        std::string id;
        Graphics::VertexArray va;
        Graphics::VertexBuffer vb;
        Graphics::IndexBuffer ib;
        Graphics::Texture texture;
        Graphics::Shader shader;

        static std::map<std::string, Shape*> shapes;

    public:
        Shape(const std::string& id, const float* positions, const unsigned int* indices,
            size_t vertexCount, size_t indexCount, const std::string& texturePath,
            const std::string& shaderPath);

        ~Shape();

        void Draw(Renderer& renderer, float r);

        static void AddShape(const std::string& id, Shape* shape);
        static Shape* GetShape(const std::string& id);
        Shader& getShader() { return shader; } // Getter method
    };
}

