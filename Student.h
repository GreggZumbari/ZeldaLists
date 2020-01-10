/*
 * This student class holds information for a single student. This class was made specially for the Node class, which can hold one Student. Otherwise, the Student class can only be used to store student info.
 * @author Greggory Hickman, Dec-Jan 2019
 * @version 2
 */
#ifndef STUDENT_H
#define STUDENT_H

class Student {

 public:
  //Constructor & Destructor
  Student();
  Student(int id);
  ~Student();
  
  //Functions
  void setName(char* name);
  void setSurname(char* surname);
  char* getName();
  char* getSurname();
  void setID(int id);
  int getID();
  void setGPA(float gpa);
  float getGPA();

 private:
  //Student info
  char* name;
  char* surname;
  int id;
  float gpa;
  
};

#endif
