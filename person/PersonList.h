//
// Created by szakos on 2020. 01. 20..
//

#ifndef UNTITLED_PERSONLIST_H
#define UNTITLED_PERSONLIST_H

#include <vector>
#include "Person.h"

class PersonList {
public:
    PersonList();

    virtual ~PersonList();

    void readPersonList(std::istream &istream);

    void writePersonList(std::ostream &ostream);

    void printPersonList(std::ostream &ostream);

    void addPerson(Person *person);

protected:
    std::vector<Person *> personList;
};


#endif //UNTITLED_PERSONLIST_H
