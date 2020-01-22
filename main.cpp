#include <iostream>
#include <vector>
#include <fstream>
#include "person/Person.h"
#include "person/PersonList.h"
#include "person/PersonFactory.h"
#include "person/PersonFactoryImpl.h"


void readPersonListFromFile (PersonList &personlist, const std::string &inFile = "../PersonDatabase.txt");
void writePersonListToFile (PersonList &personList, const std::string &outFile = "../PersonDatabase.txt");

void DataBaseEdit();

int main() {

    DataBaseEdit();
    return 0;
}


void DataBaseEdit() {
    std::string fileName="../PersonDatabase.txt";

    int id;
    std::string firstName;
    std::string lastName;
    int age;
    std::string newMember;

    std::cout << std::endl << "-------------------------------------" << std:: endl;

    std::cout << "Welcome to the database simulation!" << std::endl <<
              "Commands:\n 1. List all members (1)" << std::endl <<
              " 2. Add a new member (2)" << std::endl;

    std::string input;
    std::cin >> input;
    if (input == "1") {
        //list members
        PersonList personList;
        readPersonListFromFile(personList, fileName);
        personList.printPersonList(std::cout);
        DataBaseEdit();
    } else if (input == "2"){
        //add new member
        std::cout << "Pleas enter an ID: ";
        std::cin >> id;
        std::cout << std::endl;

        std::cout << "Please enter the first name: ";
        std::cin >> firstName;
        std::cout << std::endl;

        std::cout << "Please enter the last name: ";
        std::cin >> lastName;
        std::cout << std::endl;

        std::cout << "Please enter the age: ";
        std::cin >> age;
        std::cout << std::endl;

        PersonList personList;
        readPersonListFromFile(personList, fileName);
        personList.addPerson(new Person(id,firstName,lastName,age));
        personList.printPersonList(std::cout);
        writePersonListToFile(personList,fileName);
        DataBaseEdit();
    } else {
        std::cout << "Wrong command please try again" << std::endl;
    }
}


void readPersonListFromFile(PersonList &personList, const std::string &fileName){
    std::ifstream infile(fileName);
    if (!infile) {
        throw std::invalid_argument("Error opening input file");
    }
    PersonFactory::setPersonFactory(new PersonFactoryImpl());
    personList.readPersonList(infile);
    std::cout << "Reading was succesful" << std::endl;
}

void writePersonListToFile(PersonList &personList, const std::string &fileName) {
    std::ofstream outfile(fileName);
    if (!outfile) {
        throw std::invalid_argument("Error opening output file");
    }
    personList.writePersonList(outfile);
    std::cout << "Writeing was succesful" << std::endl;
}
