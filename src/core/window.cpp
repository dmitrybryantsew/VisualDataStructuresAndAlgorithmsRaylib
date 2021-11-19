#include "window.hpp"
namespace Simple2DEngine{
    Window::Window()
    {
        CreateWindow("default title", _screenResolution);
    }

    Window::Window(std::string title, int resolution_X, int resolution_Y)
    {
        CreateWindow(title, std::make_pair(resolution_X, resolution_Y));
    }

    Window::~Window()
    {
        CloseWindow();
    }

    void Window::CreateWindow(std::string title, std::pair<int, int> resolution)
    {
        InitWindow(resolution.first, resolution.second, title.c_str());
    }

}

