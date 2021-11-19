
#include "object.hpp"
namespace Simple2DEngine{
    unsigned  int Object::Id = 0;
    std::vector<unsigned  int> Object::vacantIdPlaces = {};
    Object::Object() {
        if(!vacantIdPlaces.empty()){
            std::cout << "I CAN REACH HERE!!!!!!!!!!!!\n";
           _objectID = vacantIdPlaces.back();
           vacantIdPlaces.pop_back();
        } else {
            _objectID = Id;
            Id++;
        }

    }

    Object::~Object() {
        vacantIdPlaces.push_back(_objectID);

        std::cout << "pushed vacant place " << _objectID << "vacant places size is " << vacantIdPlaces.size() << "\n";
    }

    unsigned int Object::getObjectID() const {
        return _objectID;
    }

}

