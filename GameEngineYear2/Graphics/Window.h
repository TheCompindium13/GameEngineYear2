#pragma once

namespace Graphics
{
	class Window
	{
	public:
		Window( const char* title = "Window");

		bool shouldClose();
		/// <summary>
	/// Gets how wide the application window is.
	/// </summary>
		static int getScreenWidth() { return m_width; }

		/// <summary>
		/// Gets how tall the application window is.
		/// </summary>
		static int getScreenHeight() { return m_height; }
		int getFrameRate();
		void setTargetFrameRate(int fps);

		void open();
		void beginDrawing();
		void endDrawing();
		void close();

	private:
		static const int m_width = 800;
		static const int m_height = 800;
		const char* m_title;
	};
}


