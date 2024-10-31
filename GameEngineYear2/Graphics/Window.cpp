#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Window.h"
#include "Renderer.h"



    Graphics::Window::Window(const char* title) : m_title(title), m_window(nullptr) {}

    Graphics::Window::~Window() 
    {
        close();
    }

    bool Graphics::Window::shouldClose()
    {
        return glfwWindowShouldClose(m_window);
    }

    int Graphics::Window::getFrameRate() 
    {
        return static_cast<int>(1.0 / glfwGetTime()); // Basic FPS calculation
    }

    void Graphics::Window::setTargetFrameRate(int fps) 
    {
        // This can be handled by the render loop timing
    }

    void Graphics::Window::open()
    {
        /*GLCall(glfwInit());
        GLCall(glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4));
        GLCall(glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6));
        GLCall(glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE));

        GLCall(m_window = glfwCreateWindow(m_width, m_height, "Hello World", NULL, NULL));
        if (!m_window) {
            std::cerr << "Failed to create GLFW window" << std::endl;
            GLCall(glfwTerminate());
        }

        GLCall(glfwMakeContextCurrent(m_window));
        GLCall(glewInit());*/
    }

    void Graphics::Window::beginDrawing()
    {
    //    GLCall(glClearColor(0.0f, 0.0f, 0.0f, 1.0f)); // Set clear color (black)
    //    GLCall(glClear(GL_COLOR_BUFFER_BIT)); // Clear the color buffer
      }

    void Graphics::Window::endDrawing() 
    {
        //GLCall(glfwSwapBuffers(m_window)); // Swap the front and back buffers
        //GLCall(glfwPollEvents()); // Poll for and process events
    }

    void Graphics::Window::close() 
    {
        //if (m_window) {
        //    GLCall(glfwDestroyWindow(m_window));
        //    GLCall(glfwTerminate());
        //}
    }

