#ifndef RAYLIBTESTPROJECT_NODE_HPP
#define RAYLIBTESTPROJECT_NODE_HPP

#include <iostream>
#include "drawable.hpp"
namespace LinkedListNamespace{
    class Node : public Simple2DEngine::Drawable {
    public:
        Node(Node* n);
        Node();
        virtual ~Node();

        void draw() override;
        Node *getNext() const;
        void changePos(Vector2 pos) override;
        void setNext(Node *next);
        const Vector2 &getPosition() const;
        void setPosition(const Vector2 &position);
        int getRadius() const;
        void setColor(const Color &color);
        bool isSelected() const;
        void setSelected(bool selected);

    private:
        static unsigned int _calls_count;
        Color _color;
        Color _selectedColor = YELLOW;
        int _data;
        int _radius;
        Node* _next;
        Vector2 _position;
        bool _selected = false;

    };
}



#endif //RAYLIBTESTPROJECT_NODE_HPP
