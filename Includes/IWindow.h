#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"

class IWindow
{
public:
	IWindow(const std::string &windowName, unsigned int width, unsigned int height, bool bFullScreen, bool bVSync);
	~IWindow();

	IWindow() = delete;
	IWindow(IWindow&) = delete;
	IWindow(IWindow&&) = delete;

	bool Initialize();
	void Tick();
	void Finalize();
private:
	std::string m_windowName;
	unsigned int m_width;
	unsigned int m_height;

	bool m_bFullScreen;
	bool m_bVSync;

	GLFWwindow* m_window;
};