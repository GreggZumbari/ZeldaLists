#include "Node.h"

//Get the next node in the chain
Node* Node::getNext() {
  return node;
}

//Get the student pointer
Student* Node::getStudent() {
  return student;
}

//Set the next node in the chain
void Node::setNext(Node* node) {
  this->node = node;
}

//Constructor
Node::Node(Student* student) {
  this->student = student;
}

//Destructor
Node::~Node() {

}
