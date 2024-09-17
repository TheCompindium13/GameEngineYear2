#include "Window.h"
#include "raylib.h"
Graphics::Window::Window(int width, int height, const char* title) : m_width(width), m_height(height), m_title(title)
{

}

bool Graphics::Window::shouldClose()
{
	return RAYLIB_H::WindowShouldClose();
}

int Graphics::Window::getFrameRate()
{
	return RAYLIB_H::GetFPS();
}

void Graphics::Window::setTargetFrameRate(int fps)
{
	RAYLIB_H::SetTargetFPS(fps);
}

void Graphics::Window::open()
{

	RAYLIB_H::InitWindow(m_width, m_height, m_title);
	RAYLIB_H::SetWindowMonitor(2);
}

void Graphics::Window::beginDrawing()
{
	RAYLIB_H::BeginDrawing();
	RAYLIB_H::ClearBackground(RAYLIB_H::PINK);
}

void Graphics::Window::endDrawing()
{
	RAYLIB_H::EndDrawing();
}

void Graphics::Window::close()
{
	RAYLIB_H::CloseWindow();
}
