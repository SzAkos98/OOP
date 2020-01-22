//
// Created by szakos on 2020. 01. 20..
//

#ifndef UNTITLED_PERSONFACTORY_H
#define UNTITLED_PERSONFACTORY_H

#include "Person.h"

class PersonFactory {
    static PersonFactory *instance;
public:
    virtual ~PersonFactory();

    static PersonFactory *getInstance();

    static void setPersonFactory(PersonFactory *personFactory);

    Person *readAndCreatePerson(std::istream &istream);

    virtual Person *createPerson() const;
};

#endif //UNTITLED_PERSONFACTORY_H
