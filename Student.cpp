#include "Student.h"

Student::Student() {}

Student::~Student() {
  cout << getName() << " says goodbye." << endl;
}

void Student::setName(char* name, char* surname) {
  this->name = name << " " << surname;
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
