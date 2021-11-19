#ifndef RAYLIBTESTPROJECT_RENDERSTATE_HPP
#define RAYLIBTESTPROJECT_RENDERSTATE_HPP
#include <memory>
#include <vector>
#include <iostream>
#include "scene.hpp"

namespace Simple2DEngine {
    class RenderState {
    public:
        virtual ~RenderState();

        virtual void ProcessInput() = 0;

        virtual void Update() = 0;

        virtual void Render() = 0;
        Scene scene;
    };
}

#endif //RAYLIBTESTPROJECT_RENDERSTATE_HPP
