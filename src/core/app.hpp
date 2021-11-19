#ifndef GAME_HPP
#define GAME_HPP
#include <stdexcept>
#include <memory>
#include <raylib.h>
#include <stack>
#include <utility>

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

#include "gui/circle.hpp"
#include "states/renderState.hpp"
#include "states/mainMenuState.hpp"
#include "scene.hpp"
#include "util/timer.hpp"
#include "window.hpp"





namespace Simple2DEngine{
    class App
    {
    public:
        //constructors
        App();

        //destructor
        ~App();
        //init

        //functions
        void Run();
        void ProcessInput();
        void Update(float time);
        void Render();
        void Initialize();

        std::unique_ptr<Window> _window;
        static constexpr float _TimePerFrame = 1 / 60.f;
        std::stack<RenderState*> renderStateStack;
        std::pair<int, int> _resolution = {600, 600}; //default
        Scene scene;
    };
}

#endif //GAME_HPP