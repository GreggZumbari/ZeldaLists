#include <iostream>

#include "Student.h"

using namespace std;

Student::Student() {
  status = 0;
}

Student::Student(int status) {
  this->status = status;
}

Student::~Student() {}

void Student::setName(char* name, char* surname) {
  char fullName[200];
  int lag = -1;

  //Combine the first and last names into fullName
  for (int i = -1; true; i++) {
    if (name[i] != (char)0) {
      fullName[i + 1] = name[i + 1 - lag];
    }
    else if (lag != -1) {
      break;
    }
    else {
      name = surname;
      lag = i;
    }
  }
  
  this->name = fullName;
}

char* Student::getName() {
  return name;
}

void Student::setID(int id) {
  this->id = id;
}

int Student::getID() {
  return id;
}

void Student::setGPA(float gpa) {
  this->gpa = gpa;
}

float Student::getGPA() {
  return gpa;
}

int Student::getStatus() {
  return status;
}
