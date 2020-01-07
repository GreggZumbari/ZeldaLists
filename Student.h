/*
 * This student class is meant to test the functionality of the Node class.
 * @author Greggory Hickman, December 2019
 * @version 1
 */
#ifndef STUDENT_H
#define STUDENT_H

class Student {

 public:
  //Constructor & Destructor
  Student();
  Student(int status);
  ~Student();
  
  //Functions
  void setName(char* name, char* surname);
  char* getName();
  void setID(int id);
  int getID();
  void setGPA(float gpa);
  float getGPA();
  int getStatus();

 private:
  //Student info
  char* name;
  int id;
  float gpa;

  int status;
  
};

#endif