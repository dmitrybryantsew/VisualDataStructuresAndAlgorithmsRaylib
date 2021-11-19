#ifndef RAYLIBTESTPROJECT_SCENE_HPP
#define RAYLIBTESTPROJECT_SCENE_HPP
#include <vector>
#include <memory>
#include "drawable.hpp"
namespace Simple2DEngine{
    class Scene{
    public:
        virtual ~Scene();

        std::vector<std::unique_ptr<Drawable>> _objectPool;
    };
};

#endif //RAYLIBTESTPROJECT_SCENE_HPP
