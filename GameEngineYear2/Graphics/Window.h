#pragma once

namespace Graphics
{
	class Window
	{
	public:
		Window(int width, int hight, const char* title = "Window");

		bool shouldClose();

		int getFrameRate();
		void setTargetFrameRate(int fps);

		void open();
		void beginDrawing();
		void endDrawing();
		void close();

	private:
		int m_width;
		int m_height;
		const char* m_title;
	};
}


