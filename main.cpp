/* This program is a really crappy console application which can store the info of any number of students. Now with recursion!
 * You can add a student with the "ADD" command (none of these commands are case-sensitive), inputting their name, ID number, and 
 * GPA. You can print out the list of students logged in this session with the "PRINT" command, printing them out in the order that
 * they were logged. The "DELETE" command will delete a student by their ID number, and finally, the "QUIT" command will abort
 * the program, deleting all students stored inside.
 *
 * Previously, this was done with vectors. Now that I'm all grown up, I'm using my own thing called nodes! I'm using Austyn Ngo's code for the Node object, but you get the idea.
 *  
 * @author Greggory Hickman
 * @version dev 1.0
 */
#include <iostream>
#include "Student.h"
#include "Node.h"

using namespace std;

int main() {
  //Input cstring
  char* cmd = new char[100];
  Node* start = new Node(new Student(-1)); //-1 means start or end of the chain
  int iter = 0;
  
  cout << "This is a repurposed version of my old \"student list\" program, meant to showcase my \"Node\" object." << endl; 
  cout << "Type in a command to get started." << endl;
  
  while (true) {
    
    cout << endl << "Commands: " << endl << "ADD" << endl << "PRINT" << endl << "DELETE" << endl << "QUIT" << endl;
    
    cout << "> ";
    
    cin.getline(cmd, 100);
    
    //Another way to do what I just did: if (strcmp(input,"ADD")) {
    //Add command - Add a student to the list with specified parameters
    if ((cmd[0] == 'A' || cmd[0] == 'a') &&
	(cmd[1] == 'D' || cmd[1] == 'd') &&
	(cmd[2] == 'D' || cmd[2] == 'd')) {

      
      Student* s = new Student();
      char* name = new char[100];
      char* surname = new char[100];
      int id;
      float gpa;
      
      cout << endl << "-----" << endl;
      cout << "Student\'s first name: ";
      cin.getline(name, 100);
      
      cout << "Student\'s last name: ";
      cin.getline(surname, 100);
      
      cout << "Student ID: ";
      cin >> id; cin.clear(); cin.ignore(100, '\n');
      
      cout << "Student GPA: ";
      cin >> gpa; cin.clear(); cin.ignore(100, '\n');

      s->setName(name, surname);
      s->setID(id);
      s->setGPA(gpa);
      
      cout << "-----" << endl;
      /*
	Node *n;
	n = &start;
	Node m = *n;
	
	//Cycle through the chain until *n is the very last Node in the chain
	for (int i = 0; m.getNext()->getStudent()->getID() != -1; i++) {
	*n = *n->getNext();
	Node m = *n;
	}
	//Once that has happened, add a new link to the end
	*n->getNext()->setNext(m.getNext());
	*/
      Node* n;
      Node* m;
      m = start;

      //This is all to try and get to the last Node in the chain
      for (int i = 0; i < iter; i++) {
      	n = m;
	m = n->getNext();
	//cout << i << endl;
      }

      Node* o = new Node(s);
      m->setNext(o);
      //cout << m->getNext()->getStudent()->getID() << endl;
      
      iter++;
      
    }
      
    //List all current students
    if ((cmd[0] == 'P' || cmd[0] == 'p') &&
	(cmd[1] == 'R' || cmd[1] == 'r') &&
	(cmd[2] == 'I' || cmd[2] == 'i') &&
	(cmd[3] == 'N' || cmd[3] == 'n') &&
	(cmd[4] == 'T' || cmd[4] == 't')) {

      cout << "-----" << endl;
      //char zeroes[6];
      
      Node* n;
      Node* m;
      n = start;
      m = n;

      //Go through the chain and print all o' them kids
      for (int i = 0; i < iter; i++) {
	n = m;
	cout << "Student #" << i+1 << ":" << endl;
	cout << "Name: " << n->getNext()->getStudent()->getName() << endl
	     << "ID: " << n->getNext()->getStudent()->getID() << endl
	     << "GPA: " << n->getNext()->getStudent()->getGPA() << endl << endl;
	m = n->getNext();
      }
      
      cout << "-----" << endl;
    }

    //Delete a student
    if ((cmd[0] == 'D' || cmd[0] == 'd') &&
	(cmd[1] == 'E' || cmd[1] == 'e') &&
	(cmd[2] == 'L' || cmd[2] == 'l') &&
	(cmd[3] == 'E' || cmd[3] == 'e') &&
	(cmd[4] == 'T' || cmd[4] == 't') &&
	(cmd[5] == 'E' || cmd[5] == 'e')) {
      /*
      int id;

      cout << endl << "-----" << endl;

      cout << "Student ID: ";
      cin >> id;
      cin.ignore();
      
      if (id != -1) {
	for (int i = id; i < list.size() - 1; i++) { //Because XCode doesn't seem to like vector.erase(id)
	  list[i] = list[i+1];
	}
	list.pop_back();
	cout << "Thank you. " << list[id].name << " " << list[id].surname  << " has been successfully located and disposed of." << endl;
      }
      else {
	cout << "No student with that ID currently exists" << endl;
      }
      
      cout << "-----" << endl;
      */
    }

    //Kill the program
    if ((cmd[0] == 'Q' || cmd[0] == 'q') &&
	(cmd[1] == 'U' || cmd[1] == 'u') &&
	(cmd[2] == 'I' || cmd[2] == 'i') &&
	(cmd[3] == 'T' || cmd[3] == 't')) {
      cout << endl << "Okay, bye. Thank you for donating to the Child Storage Association (CSA)!" << endl;
      return 0;
    }
    
  }
}

/*
//Create a new Student, must return Child
Child add(char* name, char* surname, int id, float gpa) {
  Child c;
  cout.precision(3);
  c.name = name;
  c.surname = surname;
  c.id = id;
  c.gpa = gpa;
  cout << endl << "New Student Added: " << c.name << " " << c.surname << ", " << c.id << ", " << showpoint << c.gpa << endl;
  cout << "Thank you for your donation." << endl;
  cout << "-----" << endl;
  return c;
}

//Return a child's iterator address in the list vector with the ID inputted.
int find(vector<Child> list, int id) {
  for (int i = 0; i < list.size(); i++) {
    if (list[i].id == id) {
      return i;
    }
  }
  return -1; //This means that there are no students with the inputted id
}
*/

