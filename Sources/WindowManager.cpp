#include "pch.h"

#include "WindowManager.h"

WindowManager::WindowManager(const std::string &windowName, unsigned int width, unsigned int height, bool bFullScreen, bool bVSync) : 
	m_windowName(windowName), m_width(width), m_height(height), m_bFullScreen(bFullScreen), m_bVSync(bVSync)
{
		m_window = std::make_unique<IWindow>(m_windowName, m_width, m_height, m_bFullScreen, m_bVSync);
}

WindowManager::~WindowManager()
{
}

bool WindowManager::Initialize()
{
	return m_window->Initialize();
}

void WindowManager::Tick()
{
	m_window->Tick();
}

void WindowManager::Finalize()
{
	m_window->Finalize();
}

