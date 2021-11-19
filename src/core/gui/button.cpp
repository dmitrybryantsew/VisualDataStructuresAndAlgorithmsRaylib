#include "button.hpp"
namespace Simple2DEngine {
    int Button::_MaxId = 0;
    void Simple2DEngine::Button::draw() {
        if(_buttonState == IDLE) DrawRectangleV(_position, _size, _buttonColor);
        else if (_buttonState == SELECTED) DrawRectangleV(_position, _size, YELLOW);
        else if (_buttonState == PRESSED) DrawRectangleV(_position, _size, PURPLE);
        DrawText(_buttonText.c_str(), _position.x + _size.x/2 - _buttonText.size()*_fontSize/5, _position.y +_size.y/2, _fontSize, _buttonTextColor);
    }

    void Simple2DEngine::Button::changePos(Vector2 pos) {
        _position.x += pos.x;
        _position.y += pos.y;
    }

    Button::Button() {
        _buttonText = "defaultText";
        _buttonState = IDLE;
        _buttonColor = YELLOW;
        _buttonTextColor = BLACK;
        _position = {50, 50};
        _size = {50, 50};
        _fontSize = 15;
        _buttonId = _MaxId;
        _MaxId++;
    }

    Button::Button(Vector2 position,Vector2 size, const std::string &text, Color textColor, Color buttonColor, size_t fontSize, unsigned int id)
    : _position(position),
      _size(size),
      _buttonText(text),
      _buttonTextColor(textColor),
      _buttonColor(buttonColor),
      _buttonState(IDLE),
      _fontSize(fontSize),
      _buttonId(id)
    {
        std::cout << "Constructor of button id " << getButtonId() << " global id: " << getObjectID() << " called\n";
        _MaxId++;}

    void Button::SetButtonState(ButtonStates buttonState) {
        _buttonState = buttonState;
    }

    ButtonStates Button::GetButtonState() const {
        return _buttonState;
    }

    int Button::getButtonId() const {
        return _buttonId;
    }

    void Button::setButtonId(int id) {
        _buttonId = id;
    }

    Button::~Button() {
        std::cout << "destructor of button id " << getObjectID() << " called\n";
    }
}