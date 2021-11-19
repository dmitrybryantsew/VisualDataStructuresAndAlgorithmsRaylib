#ifndef RAYLIBTESTPROJECT_BUTTON_HPP
#define RAYLIBTESTPROJECT_BUTTON_HPP
#include <string>
#include <iostream>
#include <raylib.h>

#include "drawable.hpp"
namespace Simple2DEngine {
    enum ButtonStates {
        IDLE = 0,
        SELECTED,
        PRESSED
    };
    class Button : public Drawable {
    public:
        Button();
        virtual ~Button();

        Button(Vector2 position,Vector2 size, const std::string& text, Color textColor, Color buttonColor, size_t fontSize, unsigned int id);
        void draw() override;
        void changePos(Vector2 pos) override;
        ButtonStates GetButtonState() const;
        void SetButtonState(ButtonStates buttonState);
    private:

        ButtonStates _buttonState = IDLE;
    private:
        static int _MaxId;
        std::string _buttonText;
        Color _buttonColor;
        Color _buttonTextColor;
        Vector2 _position;
        Vector2 _size;
        size_t _fontSize;
        unsigned int _buttonId;
    public:
        int getButtonId() const;

        void setButtonId(int id);
    };
}

#endif //RAYLIBTESTPROJECT_BUTTON_HPP
