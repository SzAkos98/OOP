//
// Created by szakos on 2020. 01. 20..
//

#ifndef UNTITLED_PERSONFACTORYIMPL_H
#define UNTITLED_PERSONFACTORYIMPL_H

#include "PersonFactory.h"

class PersonFactoryImpl : public PersonFactory {
public:
    Person *createPerson() const override;
};

#endif //UNTITLED_PERSONFACTORYIMPL_H
