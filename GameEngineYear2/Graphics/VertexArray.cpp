#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "VertexArray.h"
#include "VertexBufferLayout.h"
#include "Renderer.h"
Graphics::VertexArray::VertexArray()
{
	GLCall(glGenVertexArrays(1, &m_RendererID));
}

Graphics::VertexArray::~VertexArray()
{
	GLCall(glDeleteVertexArrays(1, &m_RendererID));
}

void Graphics::VertexArray::AddBuffer(const Graphics::VertexBuffer& vb, const VertexBufferLayout& Layout)
{
	Bind();
	vb.Bind();
	const auto& elements = Layout.GetElements();
	unsigned int offset = 0;
	for (unsigned int i = 0; i < elements.size(); i++)
	{
		const auto& element = elements[i];
		GLCall(glEnableVertexAttribArray(i));
		GLCall(glVertexAttribPointer(i, element.count, element.type, element.normalized, Layout.GetStride(), (const void*)offset));
		offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
	}
}

void Graphics::VertexArray::Bind() const
{
	GLCall(glBindVertexArray(m_RendererID));
}

void Graphics::VertexArray::Unbind() const
{
	GLCall(glBindVertexArray(0));

}
