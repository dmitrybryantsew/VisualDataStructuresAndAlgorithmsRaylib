#include "app.hpp"
namespace Simple2DEngine{
    constexpr float App::_TimePerFrame;

    App::App()
    {
        Initialize();
    }

    App::~App()
    {
        std::cout << "app destructor\n";
        //CloseWindow();
    }

    void App::ProcessInput()
    {
        renderStateStack.top()->ProcessInput();
    }

    void App::Run()
   {
//        Timer* timer = Timer::GetInstance();
//        while (!WindowShouldClose())
//        {
//            timer->Tick();
//
//            if (timer->GetDeltaTime() >= _TimePerFrame)
//            {
//                timer->ResetTimer();
//                ProcessInput();
//                Update(_TimePerFrame);
//                Render();
//            }
//
//        }
    while (!WindowShouldClose()) {

            ProcessInput();
            Update(_TimePerFrame);
            Render();
}

    }


    void App::Render()
    {
        BeginDrawing();
        ClearBackground(WHITE);
        renderStateStack.top()->Render();
        DrawFPS(10, 10);
        EndDrawing();
    }

    void App::Update(float t)
    {
        renderStateStack.top()->Update();
    }

    void App::Initialize()
    {
        SetTargetFPS(60);
        _window.reset(new Window("my cool title", _resolution.first, _resolution.second));
        renderStateStack.push(new MainMenuState(&renderStateStack, _resolution));
    }

}
