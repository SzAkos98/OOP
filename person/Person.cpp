//
// Created by szakos on 2020. 01. 18..
//
#include "Person.h"

Person::Person() {

}

Person::Person(int id, std::string firstName, std::string lastName, int age) :
    id(id), firstName(firstName), lastName(lastName), age(age) {

}
int Person::getId() const {
    return id;
}

const std::string &Person::getFirstName() const {
    return firstName;
}

const std::string &Person::getLastName() const {
    return lastName;
}

int Person::getAge() const {
    return age;
}

void Person::printParams(std::ostream &ostream) const {
    ostream << "Person id: " << getId() << ", "
    << "Person name: " << getFirstName() << " " << getLastName() << ", "
    << "Person age: " << getAge();
}

void Person::writeParamsToStream(std::ostream &ostream) const {
    ostream << id << " " << firstName << " " << lastName << " " << age;
}

void Person::loadParamsFromStream(std::istream &istream) {
    if (istream.fail() || istream.eof()) {
        throw std::invalid_argument("Invalid stream");
    }
    istream >> id;
    istream >> firstName;
    istream >> lastName;
    istream >> age;
}

std::ostream &operator << (std::ostream &ostream, const Person &person) {
    person.writeParamsToStream(ostream);
    return ostream;
}

std::istream &operator >> (std::istream &istream , Person &person) {
    person.loadParamsFromStream(istream);
    return istream;
}

Person::~Person() {}

bool Person::operator == (const Person &person) const {
    return id == person.id && firstName == person.firstName && lastName == person.lastName && age == person.age;
}

bool Person::operator!=(const Person &person) const {
    return !(person == *this);
}

void Person::print(std::ostream &ostream) const {
    printParams(ostream);
}