#ifndef RAYLIBTESTPROJECT_LINKEDLISTSTATE_HPP
#define RAYLIBTESTPROJECT_LINKEDLISTSTATE_HPP

#include <stack>
#include "linkedList.hpp"
#include "renderState.hpp"
#include "gui/circle.hpp"

namespace Simple2DEngine{
    class LinkedListState : public RenderState {
    public:
        void Initialize();
        void ProcessInput() override;
        LinkedListState(std::stack<RenderState *> *renderStateStackPointer);
        void Update() override;

        virtual ~LinkedListState();

        void Render() override;

    private:
        std::stack<RenderState*>* renderStateStackPointer;
        Camera2D camera = { 0 };
        Vector2 prevMousePos = {0, 0};
        bool _nodeMouseSticked = false;
    };
}



#endif //RAYLIBTESTPROJECT_LINKEDLISTSTATE_HPP
