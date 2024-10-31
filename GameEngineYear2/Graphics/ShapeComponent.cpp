#include "ShapeComponent.h"

void Graphics::ShapeComponent::initializeShape(const std::string& id, const float* positions, const unsigned int* indices, size_t vertexCount, size_t indexCount, const std::string& texturePath, const std::string& shaderPath)
{

    m_shape = new Shape(id, positions, indices, vertexCount, indexCount, texturePath, shaderPath);
    Shape::AddShape(id, m_shape);
}
void Graphics::ShapeComponent::draw(Renderer& renderer) {
    GameMath::Vector2 position = getOwner()->getTransform()->getGlobalPosition();
    GameMath::Vector2 scale = getOwner()->getTransform()->getGlobalScale();

    std::string shapeID = (m_shapeType == ShapeType::CIRCLE) ? "Circle" : "Box"; // Use appropriate IDs
    Shape* shape = GetShape(shapeID);

    if (m_shape) 
    {
        // Set color in the shader
        m_shape->getShader().Bind();
        m_shape->getShader().SetUniform4f("u_Color",
            ((m_color >> 24) & 0xFF) / 255.0f,  // Red
            ((m_color >> 16) & 0xFF) / 255.0f,  // Green
            ((m_color >> 8) & 0xFF) / 255.0f,   // Blue
            (m_color & 0xFF) / 255.0f            // Alpha
        );

        // Adjust position based on scale
        
        m_shape->Draw(renderer, ((m_color >> 24) & 0xFF) / 255.0f); // Use the red channel for the drawing
        
    }
    else 
    {
        std::cerr << "Shape not found!" << std::endl;
    }
}

void Graphics::ShapeComponent::AddShape(const std::string& id, Shape* shape) {
    shapes[id] = shape;
}

Graphics::Shape* Graphics::ShapeComponent::GetShape(const std::string& id) {
    auto it = shapes.find(id);
    if (it != shapes.end()) {
        return it->second;
    }
    std::cerr << "Shape with ID " << id << " not found!" << std::endl;
    return nullptr;
}