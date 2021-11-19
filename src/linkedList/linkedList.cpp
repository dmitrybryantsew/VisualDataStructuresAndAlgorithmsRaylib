#include "linkedList.hpp"
namespace LinkedListNamespace {
    LinkedList::LinkedList() {
        _start =  new Node();
       _size = 1;
        Node *traversePtr = _start;
        for (int i = 0; i < 10; i++) {
            traversePtr->setNext(new Node());
            traversePtr = traversePtr->getNext();
            _size++;
        }
        _end = traversePtr;
        _selected = _start;
    }

    void LinkedList::addNode() {
        _end->setNext(new Node());
        _end = _end->getNext();
    }

    void LinkedList::draw() {
        Node *traversePtr = _start;
        while (traversePtr != nullptr) {
            if (traversePtr->getNext() != nullptr)
                drawArrow(traversePtr, traversePtr->getNext(), 1, BLACK);
            traversePtr->draw();
            traversePtr = traversePtr->getNext();
        }
    }

    void LinkedList::changePos(Vector2 pos) {

        for (auto begin = _start; begin != _end; begin = begin->getNext()) {
            if (begin == nullptr) break;
            auto[x, y] = begin->getPosition();
            begin->setPosition({x + pos.x, y + pos.y});
        }
    }

    void LinkedList::drawArrow(Node *startNode, Node *endNode, float thickness, Color ArrowColor) {
        Vector2 startPos = startNode->getPosition();
        Vector2 endPos;
        if (endNode != nullptr)
            endPos = endNode->getPosition();
        else return;
        double dx = endPos.x - startPos.x;
        double dy = endPos.y - startPos.y;
        double length = sqrt(dx*dx + dy*dy ) - endNode->getRadius();

        int arrowSize = 10;
        double angle = atan2(dy, dx) + M_PI;
        Vector2 arrowPoint1 = {static_cast<float>(endPos.x + arrowSize * cos(angle + 0.3)),
                               static_cast<float>(endPos.y + arrowSize * sin(angle + 0.3))};
        Vector2 arrowPoint2 = {static_cast<float>(endPos.x + arrowSize * cos(angle - 0.3)),
                               static_cast<float>(endPos.y + arrowSize * sin(angle - 0.3))};

        endPos ={static_cast<float>(startPos.x - length * cos(angle)), static_cast<float>(startPos.y - length * sin(angle))};
        DrawLineEx(startPos, endPos , thickness, ArrowColor);
        DrawLineEx(endPos, arrowPoint1, thickness, ArrowColor);
        DrawLineEx(endPos, arrowPoint2, thickness, ArrowColor);
    }

    void LinkedList::addNode(int n) {
        if(n > _size)  {
            std::cerr << "list size exceeded \n";
            return;
        }
        if(n == _size || _size == 1)
        {
            LinkedList::addNode();
            return;
        }
        int counter = 0;
        auto firstTraversePtr = _start;
        auto secondTraversePtr = _start->getNext();
        while(counter != n){
            firstTraversePtr = secondTraversePtr;
            secondTraversePtr = firstTraversePtr->getNext();
            counter++;
        }
        firstTraversePtr->setNext(new Node());
        firstTraversePtr->getNext()->setNext(secondTraversePtr);
        firstTraversePtr->getNext()->setPosition({400 + (float)_size*50, (float)400*_size});
        _size++;
    }

    void LinkedList::setSelected(Node *selected) {
        _selected->setSelected(false);
        _selected = selected;
        _selected->setSelected(true);
    }

    Node *LinkedList::getSelected() const {
        return _selected;
    }

    Node *LinkedList::getStart() const {
        return _start;
    }

    LinkedList::~LinkedList() {
        std::cout << "called linked list destructor\n";
    }

    size_t LinkedList::getSize() const {
        return _size;
    }
}