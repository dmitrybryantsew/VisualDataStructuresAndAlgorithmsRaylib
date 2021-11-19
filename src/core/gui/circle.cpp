#include "circle.hpp"
namespace Simple2DEngine {
    void Circle::draw() {
        DrawCircle(_position.x, _position.y, _radius, _color);
    }

    Circle::Circle() {
        _position = {200, 200};
        _color = {255, 0, 255, 255};
        _radius = 10;
    }

    void Circle::changePos(Vector2 pos) {
        _position.x += pos.x;
        _position.y += pos.y;
    }
}

