#include "pch.h"

#include "IWindow.h"

IWindow::IWindow(const std::string &windowName, unsigned int width, unsigned int height, bool bFullScreen, bool bVSync)
	:m_windowName(windowName), m_width(width), m_height(height), m_bFullScreen(bFullScreen), m_bVSync(bVSync)
{
	m_window = nullptr;
}

IWindow::~IWindow()
{
}

bool IWindow::Initialize()
{
	if (!glfwInit())
	{
		// TODO:
		return false;
	}

	glfwDefaultWindowHints();
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_window = glfwCreateWindow(m_width, m_height, m_windowName.c_str(), 
		m_bFullScreen ? glfwGetPrimaryMonitor() : NULL, NULL);

	if (!m_window)
	{
		// TODO:
		glfwTerminate();
		return false;
	}

	glfwSetWindowTitle(m_window, m_windowName.c_str());

	// TODO:
	glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSwapInterval(m_bVSync ? 1 : 0);

	glfwMakeContextCurrent(m_window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        // TODO:
        return false;
    }

	return true;
}

void IWindow::Run()
{
	while (!glfwWindowShouldClose(m_window))
    {
        // Check if any events have been activated (key pressed, mouse moved etc.) and call corresponding response functions
        glfwPollEvents();

        // Render
        // Clear the colorbuffer
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Swap the screen buffers
        glfwSwapBuffers(m_window);
    }

	// TODO: need to be remove and fill the function in Finalize
	glfwDestroyWindow(m_window);
	glfwTerminate();
}

void IWindow::Finalize()
{
	glfwDestroyWindow(m_window);
	glfwTerminate();
}
