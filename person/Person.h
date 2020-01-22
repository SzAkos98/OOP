//
// Created by szakos on 2020. 01. 18..
//

#ifndef UNTITLED_PERSON_H
#define UNTITLED_PERSON_H

#include <iostream>

class Person {
protected:
    int id;
    std::string firstName;
    std::string lastName;
    int age;
    virtual void printParams(std::ostream &ostream) const;
    virtual void loadParamsFromStream(std::istream &istream);
    virtual void writeParamsToStream(std::ostream &ostream) const;

public:
    Person();

    Person(int id, std::string firstName, std::string lastName, int age);

    virtual ~Person();

    int getId() const;

    const std::string &getFirstName() const;

    const std::string &getLastName() const;

    int getAge() const;

    void print(std::ostream &ostream) const;

    friend std::istream &operator >> (std::istream &istream, Person &person);

    friend std::ostream &operator << (std::ostream &ostream, const Person &person);

    bool operator==(const Person &person) const;

    bool operator!=(const Person &person) const;

    Person(const Person &person) : id(person.id), firstName(person.firstName), lastName(person.lastName), age(person.age) {
        std::cout << "Person ctor" << std::endl;
    }

    Person &operator = (const Person &person) {
        std::cout << "Person copy assign" << std::endl;
        if (this != &person){
            id = person.id;
            firstName = person.firstName;
            lastName = person.lastName;
            age = person.age;
        }
        return *this;
    }

    Person(Person &&person) {
        std::cout << "Person move ctor" << std::endl;
        id = person.id;
        firstName = person.firstName;
        lastName = person.lastName;
        age = person.age;

        person.id=0;
        person.firstName="";
        person.lastName="";
        person.age=0;
    }

    Person &operator=(Person &&person) {
        std::cout << "Person move assign" << std::endl;
        if(this != &person) {
            id = person.id;
            firstName = person.firstName;
            lastName = person.lastName;
            age = person.age;

            person.id=0;
            person.firstName="";
            person.lastName="";
            person.age=0;
        }
        return *this;

    }
};

#endif //UNTITLED_PERSON_H
