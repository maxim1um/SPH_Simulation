#pragma once

#include "IWindow.h"

class WindowManager
{
public:
	WindowManager(const std::string &windowName, unsigned int width = 1024, unsigned int height = 768, bool bFullScreen = false, bool bVSync = false);
	~WindowManager();

	WindowManager() = delete;
	WindowManager(WindowManager&) = delete;
	WindowManager(WindowManager&&) = delete;

	bool Initialize();
	void Run();
	void Finalize();
private:
	std::string m_windowName;
	unsigned int m_width;
	unsigned int m_height;

	bool m_bFullScreen;
	bool m_bVSync;

	std::unique_ptr<IWindow> m_window;
};