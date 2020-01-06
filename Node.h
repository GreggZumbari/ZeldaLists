/*
 * This is an extremely simple Node object whose main ability is to point to another one of itself;
 * another Node. This allows for a long chain of Nodes, each one pointing to the next. Each node may
 * also contain a Student, 
 */
#ifndef NODE_H
#define NODE_H

#include "Student.h"

class Node {

 public:
  //Functions
  Node* getNext(); //Get the next node in the chain
  Student* getStudent(); //Get the student pointer
  void setNext(Node* node); //Set the next node in the chain

  //Constructor & Destructor
  Node(Student* student);
  ~Node();

 private:
  Node* node;
  Student* student;
};

#endif
