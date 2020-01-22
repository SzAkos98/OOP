//
// Created by szakos on 2020. 01. 20..
//

#include "PersonFactory.h"

Person *PersonFactory::readAndCreatePerson(std::istream &istream) {
    if (istream.fail() || istream.eof()) {
        throw std::invalid_argument("Line must start with an ID (integer)");
    }

    Person *person = createPerson();

    if (!person) {
        throw std::invalid_argument("The person cannot be created");
    }

    return person;
}

PersonFactory::~PersonFactory() {}

PersonFactory *PersonFactory::instance = nullptr;

void PersonFactory::setPersonFactory(PersonFactory *personFactory) {
    instance = personFactory;
}

PersonFactory *PersonFactory::getInstance() {
    if (!instance) {
        instance = new PersonFactory();
    }
    return instance;
}

Person *PersonFactory::createPerson() const {
    return nullptr;
}