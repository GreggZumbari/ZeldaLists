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

void Student::setName(char* name) {
  /*char fullName[200];
    int flen = 0;*/

  //Get the length of the name because strlen() DOES NOT ALWAYS WORK and I need some consistency in my life
  //Also I could have done a for loop for this but I haven't used a while loop in a while and I don't want it to feel left out
  /*while (flen < 100) {
    if (name[flen]) {

    }
    flen++;
  }*/
  /*int lag = -1;

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
  }*/
  
  this->name = name;
}

void Student::setSurname(char* surname) {
  //I finally caved and just made a separate method instead of trying to combine the two cstrings
  this->surname = surname;
}

char* Student::getName() {
  return name;
}

char* Student::getSurname() {
  return surname;
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
