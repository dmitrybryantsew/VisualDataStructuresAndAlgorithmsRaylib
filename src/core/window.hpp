#ifndef WINDOW_HPP
#define WINDOW_HPP
#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>

#include <raylib.h>

#include "scene.hpp"
namespace Simple2DEngine{
    class Window
    {
    public:
        Window();
        Window(std::string title, int resolution_X, int resolution_Y);

        ~Window();
        void CreateWindow(std::string title, std::pair<int, int>resolution);
        std::pair<int, int> _screenResolution = {600, 400};
    };
}

#endif WINDOW_HPP