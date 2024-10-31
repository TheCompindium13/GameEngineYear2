#include "Shape.h"
#include "Renderer.h" // Ensure you include Renderer for GLCall

std::map<std::string, Shape*> Shape::shapes;

Shape::Shape(const std::string& id, const float* positions, const unsigned int* indices,
    size_t vertexCount, size_t indexCount, const std::string& texturePath,
    const std::string& shaderPath)
    : id(id), vb(positions, vertexCount * 4 * sizeof(float)), ib(indices, indexCount),
    texture(texturePath), shader(shaderPath) 
{

    // Enable blending
    GLCall(glEnable(GL_BLEND));
    GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

    // Initialize vertex buffer layout and array
    VertexBufferLayout layout;
    layout.Push<float>(2); // For position
    layout.Push<float>(2); // For texture coordinates
    va.AddBuffer(vb, layout);
}

Shape::~Shape() {}

void Shape::Draw(Renderer& renderer, float r) 
{
    shader.Bind();
    shader.SetUniform4f("u_Color", r, 0.3f, 0.8f, 1.0f);
    texture.Bind();
    shader.SetUniform1i("u_Texture", 0);
    renderer.Draw(va, ib, shader);
}

void Shape::AddShape(const std::string& id, Shape* shape) {
    shapes[id] = shape;
}

Shape* Shape::GetShape(const std::string& id) {
    return shapes.at(id); // Use .at() for safer access
}
