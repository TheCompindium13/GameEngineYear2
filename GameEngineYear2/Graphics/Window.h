#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
namespace Graphics
{
    class Window {
    public:
        Window(const char* title);
        ~Window();

        bool shouldClose();
        int getFrameRate();
        void setTargetFrameRate(int fps);
        void open();
        void beginDrawing();
        void endDrawing();
        void close();
        /// <summary>
    /// Gets how wide the application window is.
    /// </summary>
        static int getScreenWidth() { return m_width; }

        /// <summary>
        /// Gets how tall the application window is.
        /// </summary>
        static int getScreenHeight() { return m_height; }

    private:
        const char* m_title;
        GLFWwindow* m_window;
        static const int m_width = 800;
        static const int m_height = 800;
    };
}


