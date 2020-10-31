#include "pch.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "WindowManager.h"

int main(int argc, char* argv[])
{

    std::unique_ptr<WindowManager> windowManager = std::make_unique<WindowManager>("SPH simulation");

    if (!windowManager->Initialize())
    {
        exit(EXIT_FAILURE); 
    }

    windowManager->Run();
    
    return 0;
}
