#ifndef RAYLIBTESTPROJECT_OBJECT_HPP
#define RAYLIBTESTPROJECT_OBJECT_HPP
#include <vector>
#include <iostream>
namespace Simple2DEngine{
    class Object {

        static unsigned int Id;
        static std::vector<unsigned  int> vacantIdPlaces;
        size_t _objectID;
    public:
        unsigned int getObjectID() const;

        Object();
        virtual ~Object();
    };
}



#endif //RAYLIBTESTPROJECT_OBJECT_HPP
