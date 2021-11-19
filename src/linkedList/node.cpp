#include "node.hpp"

unsigned int LinkedListNamespace::Node::_calls_count = 0;
namespace LinkedListNamespace {
    Node::Node() {
        _data = _calls_count;
        _calls_count++;
        _color = BLUE;
        _position = {float(100 + _data * 50), 250};
        _radius = 5;
        _next = nullptr;
        std::cout << "default Node created global id is " << getObjectID() << "\n";
    }

    void Node::draw() {
        if(_selected)
            DrawCircleV(_position, _radius, _selectedColor);
        else
            DrawCircleV(_position, _radius, _color);
    }

    void Node::changePos(Vector2 pos) {

    }

  Node::Node(Node *n) {
        _data = _calls_count;
        _calls_count++;
        _color = BLUE;
        _position = {100, float(250 + _data * 50)};
        _radius = 5;
        _next = nullptr;
      std::cout << "Node to node created global id is " << getObjectID() << "\n";
    }

   Node *Node::getNext() const {
        return _next;
    }

    void Node::setNext(Node *next) {
        _next = next;
    }

    const Vector2 &Node::getPosition() const {
        return _position;
    }

    int Node::getRadius() const {
        return _radius;
    }

    void Node::setPosition(const Vector2 &position) {
        _position = position;
    }

    void Node::setColor(const Color &color) {
        _color = color;
    }

    bool Node::isSelected() const {
        return _selected;
    }

    void Node::setSelected(bool selected) {
        _selected = selected;
    }

    Node::~Node() {
        std::cout << "node destructor called " << "global id " << getObjectID() << "\n";
    }
}