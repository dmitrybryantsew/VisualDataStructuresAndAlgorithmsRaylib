#ifndef RAYLIBTESTPROJECT_CIRCLE_HPP
#define RAYLIBTESTPROJECT_CIRCLE_HPP
#include "drawable.hpp"
#include <iostream>
namespace Simple2DEngine{
    class Circle : public Drawable {

    public:
        Circle();
        void draw() override;
        void changePos(Vector2 pos) override;
    private:
        Vector2 _position;
        Color _color;
        float _radius;

    };
}
#endif //RAYLIBTESTPROJECT_CIRCLE_HPP
