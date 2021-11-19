#ifndef RAYLIBTESTPROJECT_LINKEDLIST_HPP
#define RAYLIBTESTPROJECT_LINKEDLIST_HPP
#include "node.hpp"
#include "drawable.hpp"

#include <memory>
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
//FIXME for visual studio toolchain
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

namespace LinkedListNamespace{
    class LinkedList : public Simple2DEngine::Drawable  {
    public:
        LinkedList();

        virtual ~LinkedList();

        void addNode();
        void addNode(int n);

        void draw() override;
        void changePos(Vector2 pos) override;

        void setSelected(Node *selected);
        //add node remove node
        Node *getStart() const;
        Node *getSelected() const;
    private:
        void drawArrow(Node* startNode, Node* endNode, float thickness, Color ArrowColor);

        size_t _size = 0;
    public:
        size_t getSize() const;

    private:
        Node* _start;
        Node* _end;
        Node* _selected;
    };
}



#endif //RAYLIBTESTPROJECT_LINKEDLIST_HPP
