
#include "mainMenuState.hpp"


namespace Simple2DEngine {
    void MainMenuState::ProcessInput() {
        if(IsKeyPressed(KEY_W)) {
            if(selectedItem - cols >= 0){
                dynamic_cast<Button*>(scene._objectPool[selectedItem].get())->SetButtonState(IDLE);
                selectedItem -= cols;
                dynamic_cast<Button*>(scene._objectPool[selectedItem].get())->SetButtonState(SELECTED);
            }
            else selectedItem = 0;
        }
        if(IsKeyPressed(KEY_S)) {
            if(selectedItem + cols <= _sceneSize){
                dynamic_cast<Button*>(scene._objectPool[selectedItem].get())->SetButtonState(IDLE);
                selectedItem += cols;
                dynamic_cast<Button*>(scene._objectPool[selectedItem].get())->SetButtonState(SELECTED);
            }
            else selectedItem = _sceneSize;
        }
        if(IsKeyPressed(KEY_A)) {
            if(selectedItem - 1 >= 0){
                dynamic_cast<Button*>(scene._objectPool[selectedItem].get())->SetButtonState(IDLE);
                selectedItem -= 1;
                dynamic_cast<Button*>(scene._objectPool[selectedItem].get())->SetButtonState(SELECTED);
            }
            else selectedItem = 0;
        }
        if(IsKeyPressed(KEY_D)) {
            if(selectedItem + 1 <= _sceneSize) {
                dynamic_cast<Button*>(scene._objectPool[selectedItem].get())->SetButtonState(IDLE);
                selectedItem += 1;
                dynamic_cast<Button*>(scene._objectPool[selectedItem].get())->SetButtonState(SELECTED);
            }
            else selectedItem = 0;
        }
        if(IsKeyPressed(KEY_ENTER)){
            dynamic_cast<Button*>(scene._objectPool[selectedItem].get())->SetButtonState(PRESSED);
            if(dynamic_cast<Button*>(scene._objectPool[selectedItem].get())->getButtonId() == 0){
                renderStateStackPointer->push(new LinkedListState(renderStateStackPointer));
            }
        }
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
            std::cout << GetMousePosition().x << " " << GetMousePosition().y;
            DrawCircle(GetMousePosition().x, GetMousePosition().y, 20, RED);
        }
    }

    void MainMenuState::Update() {
    }

    void MainMenuState::Render() {

        for(auto& object : scene._objectPool) {
            object->draw();
        }
    }

    MainMenuState::MainMenuState() {
        Initialize();
    }

    void MainMenuState::Initialize() {
        ClearBackground(WHITE);
        Vector2 pos;
        for (int i=0; i < rows; i++){
            for(int j = 0; j < cols; j++ ){
                pos.x = j * resolution.first/cols;
                pos.y = i * resolution.second / rows;
                scene._objectPool.push_back(std::make_unique<Button>(pos,Vector2{static_cast<float>(resolution.first/cols - 5),
                                                                                 static_cast<float>(resolution.second / rows - 5)},
                                                                     getMenuItems()[j*10 + i], BLACK, GRAY,15, j*10 + i));
            }


             }
        _sceneSize = scene._objectPool.size() - 1;
    }

    MainMenuState::MainMenuState(std::stack<RenderState *> *renderStateStackPointer, std::pair<int, int> resolution) :
    renderStateStackPointer(renderStateStackPointer),
    resolution(resolution)
    { Initialize();}

    const std::vector<std::string> &MainMenuState::getMenuItems() const {
        return menuItems;
    }
}