#include "linkedListState.hpp"
namespace Simple2DEngine{
    void LinkedListState::ProcessInput() {
        if(IsKeyPressed(KEY_A)){
            renderStateStackPointer->pop();
        }



        if (IsMouseButtonDown(0)){
            Vector2 thisPos = GetMousePosition();
            //std::cout << thisPos.x << " " << thisPos.y << "\n";
            Vector2 delta = {prevMousePos.x - thisPos.x, prevMousePos.y - thisPos.y};
            prevMousePos = thisPos;
            camera.target = GetScreenToWorld2D({camera.offset.x + delta.x, camera.offset.y + delta.y} ,camera);
        }




        else if (IsKeyDown(KEY_S)) camera.rotation++;

        // Limit camera rotation to 80 degrees (-40 to 40)
        if (camera.rotation > 40) camera.rotation = 40;
        else if (camera.rotation < -40) camera.rotation = -40;

        // Camera zoom controls
        camera.zoom += ((float)GetMouseWheelMove()*0.05f);

        if (camera.zoom > 3.0f) camera.zoom = 3.0f;
        else if (camera.zoom < 0.1f) camera.zoom = 0.1f;

        // Camera reset (zoom and rotation)
        if (IsKeyPressed(KEY_R))
        {
            camera.zoom = 1.0f;
            camera.rotation = 0.0f;
        }

        if (IsKeyPressed(KEY_C))
        {
            auto list = dynamic_cast<LinkedListNamespace::LinkedList*>(scene._objectPool[0].get());
            list->changePos({10, 0});
        }
        if (IsKeyPressed(KEY_B))
        {
            auto list = dynamic_cast<LinkedListNamespace::LinkedList*>(scene._objectPool[0].get());
            list->addNode(3);
        }
        if (IsKeyPressed(KEY_P))
        {
            auto list = dynamic_cast<LinkedListNamespace::LinkedList*>(scene._objectPool[0].get());
            if(list->getSelected()->getNext() == nullptr)
                list->setSelected(list->getStart());
            else
                list->setSelected(list->getSelected()->getNext());

        }
        if (IsKeyPressed(KEY_H)){
            _nodeMouseSticked = !_nodeMouseSticked;
        }
        if(_nodeMouseSticked){
            auto list = dynamic_cast<LinkedListNamespace::LinkedList*>(scene._objectPool[0].get());
            list->getSelected()->setPosition(GetScreenToWorld2D(GetMousePosition(), camera));
        }
        prevMousePos = GetMousePosition(); // bad?
    }

    void LinkedListState::Update() {

    }

    void LinkedListState::Render() {
        BeginMode2D(camera);
        for(auto& object : scene._objectPool) {
            object->draw();
        }
        EndMode2D();
    }

    void LinkedListState::Initialize() {
        EnableCursor();
        scene._objectPool.push_back(std::make_unique<LinkedListNamespace::LinkedList>());
        std::cout << "size of pool is" << dynamic_cast<LinkedListNamespace::LinkedList*>(scene._objectPool[0].get())->getSize()<< "\n";
        camera.target = {  20.0f, 20.0f };
        camera.offset = { 600/2.0f, 600/2.0f };
        camera.rotation = 0.0f;
        camera.zoom = 1.0f;
    }

    LinkedListState::LinkedListState(std::stack<RenderState *> *renderStateStackPointer) : renderStateStackPointer(
            renderStateStackPointer) {
        Initialize();
    }

    LinkedListState::~LinkedListState() {
       std::cout <<"called linked list state destructor \n";
    }
}

