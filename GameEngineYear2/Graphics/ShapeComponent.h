#pragma once

#include "Engine/Component.h"
#include "Engine/Entity.h"
#include "Engine/TransformComponent.h"
#include "Shape.h" // Include your Shape header
#include "Renderer.h"
#include <map>
#include <string>
#include <iostream>

namespace Graphics 
{

    enum class ShapeType 
    {
        CIRCLE,
        BOX
    };

    class ShapeComponent : public GameEngine::Component 
{
    public:
        ShapeComponent() : m_shapeType(ShapeType::CIRCLE), m_color(0xFFFFFFFF) {}
        ~ShapeComponent() {}
        void initializeShape(const std::string& id, const float* positions, const unsigned int* indices,
            size_t vertexCount, size_t indexCount, const std::string& texturePath,
            const std::string& shaderPath);
        void setColor(unsigned int color) { m_color = color; }
        unsigned int getColor() const { return m_color; }

        void setShapeType(ShapeType type) { m_shapeType = type; }
        ShapeType getShapeType() const { return m_shapeType; }

        void draw(Renderer& renderer);

        static void AddShape(const std::string& id, Shape* shape);
        static Shape* GetShape(const std::string& id);

    private:
        ShapeType m_shapeType;
        unsigned int m_color;
        Shape* m_shape = nullptr;
        static std::map<std::string, Shape*> shapes; // Static map to hold shapes
    };

}