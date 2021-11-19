#ifndef RAYLIBTESTPROJECT_MAINMENUSTATE_HPP
#define RAYLIBTESTPROJECT_MAINMENUSTATE_HPP
#include <iostream>
#include <stack>
//#include "raylib.h"

#include "gui/button.hpp"
#include "scene.hpp"
#include "renderState.hpp"
#include "linkedListState.hpp"


namespace Simple2DEngine {
    class MainMenuState : public RenderState {
    public:
        MainMenuState();
        void Initialize();
        void ProcessInput() override;

        void Update() override;

        void Render() override;


        std::stack<RenderState*>* renderStateStackPointer;

        MainMenuState(std::stack<RenderState *>* renderStateStackPointer, std::pair<int, int> resolution);

        private:
        int selectedItem = 0;
        int _sceneSize = 0;
        int rows = 10;
        int cols = 1;
        std::pair<int, int> resolution;
        std::vector<std::string> menuItems = {"Linked List", "Vector", "Set", "Stack", "Map", "Queue", "Priority Queue", "Trees", "HashTable", "Algorithms"};
    public:
        const std::vector<std::string> &getMenuItems() const;
    };
}

#endif //RAYLIBTESTPROJECT_MAINMENUSTATE_HPP
