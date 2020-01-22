cmake_minimum_required(VERSION 3.15)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp person/Person.h person/Person.cpp person/PersonList.h person/PersonList.cpp person/PersonFactory.h person/PersonFactory.cpp person/PersonFactoryImpl.h person/PersonFactoryImpl.cpp)