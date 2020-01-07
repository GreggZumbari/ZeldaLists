#include "Student.h"

Student::Student() {}

Student::~Student() {}

void Student::setName(char* name, char* surname) {
  //char fullName[100];
  this->name = name;
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
