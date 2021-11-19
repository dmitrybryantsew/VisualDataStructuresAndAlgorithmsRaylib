#ifndef RAYLIBTESTPROJECT_DRAWABLE_HPP
#define RAYLIBTESTPROJECT_DRAWABLE_HPP
#include <raylib.h>

#include "object.hpp"
namespace Simple2DEngine{
    class Drawable : public Object{
    public:
        Drawable();

        virtual void draw() = 0;
        virtual void changePos(Vector2 pos) = 0;
        virtual ~Drawable();
    };
}

#endif //RAYLIBTESTPROJECT_DRAWABLE_HPP
