//
// Created by szakos on 2020. 01. 20..
//

#include "PersonList.h"
#include "PersonFactory.h"

PersonList::~PersonList() {
    for(auto &item:personList) {
        delete item;
    }
    personList.clear();
}

void PersonList::readPersonList(std::istream &istream) {
    istream >> std::skipws;
    while (istream.good()) {
        Person *person = PersonFactory::getInstance() -> readAndCreatePerson(istream);
        if(person) {
            istream >> *person;
            addPerson(person);
        } else {
            throw std::invalid_argument("The person can't be created");
        }
    }
}

void PersonList::writePersonList(std::ostream &ostream) {
    for (auto &item:personList) {
        ostream << std::endl << *item ;
    }
}

void PersonList::printPersonList(std::ostream &ostream) {
    for (auto &item:personList) {
        item -> print(ostream);
        ostream << std::endl;
    }
}

void PersonList::addPerson(Person *person) {
    if (!person) {
        throw std::invalid_argument("The person cannot be added");
    }
    personList.push_back(person);
}

PersonList::PersonList() {}