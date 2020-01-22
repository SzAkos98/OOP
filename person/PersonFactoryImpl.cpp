//
// Created by szakos on 2020. 01. 20..
//

#include "PersonFactoryImpl.h"

Person *PersonFactoryImpl::createPerson() const{
    return new Person();
}