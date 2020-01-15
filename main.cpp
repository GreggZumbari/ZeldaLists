/* This program is a really crappy console application which can store the info of any number of students. Now with recursion!
 * You can add a student with the "ADD" command (none of these commands are case-sensitive), inputting their name, ID number, and GPA. You can print out the list of students logged in this session with the "PRINT" command, printing them out in the order that they were logged. The "DELETE" command will delete a student by their ID number, and the MEAN command will return the average GPA. And finally, the "QUIT" command will abort the program, deleting all students stored inside.
 *
 * Previously, this was done with vectors. Now that I'm all grown up, I'm using my own thing called nodes! I'm using Austyn Ngo's code for the Node object, but you get the idea.
 *  
 * @author Greggory Hickman, Dec-Jan 2019
 * @version dev 2.0
 */
#include <iostream>
#include <iomanip>
#include "Student.h"
#include "Node.h"

using namespace std;

//Prototypes
void add(Node*&, Node*, Node*);
void print(Node*, int);
void del(Node*, int);

int main() {
  //Print all floats to the hundredth's place
  cout << setprecision(2) << fixed;
  
  //Input cstring
  char* cmd = new char[100];
  //The beginning and end of the chain
  Node* head = new Node(new Student(-1)); //-1 means head or end of the chain
  Node* tail = new Node(new Student(-1));

  //Connecting the head and the tail
  head->setNext(tail);
  
  cout << "Type in a command to get started. (Non-case sensitive)" << endl;
  
  while (true) {
    
    cout << endl << "Commands: " << endl << "ADD" << endl << "PRINT" << endl << "DELETE" << endl << "AVERAGE" << endl << "QUIT" << endl;
    
    cout << "> ";
    
    cin.getline(cmd, 100);

    cout << "-----" << endl;
    
    //Another way to do what I just did: if (strcmp(input,"ADD") == 0) {
    //Add a student to the chain with specified parameters
    if ((cmd[0] == 'A' || cmd[0] == 'a') &&
	(cmd[1] == 'D' || cmd[1] == 'd') &&
	(cmd[2] == 'D' || cmd[2] == 'd')) {
      
      Student* s = new Student();
      char* name = new char[100];
      char* surname = new char[100];
      int id;
      float gpa;

      //Get parameters
      cout << "Student\'s first name: ";
      cin.getline(name, 100);
      
      cout << "Student\'s last name: ";
      cin.getline(surname, 100);

      while (true) {
	cout << "Student ID: ";
	cin >> id; cin.clear(); cin.ignore(100, '\n');

	bool r = false;
	Node* n = head;
        while (true) {
	  if (n->getNext()->getStudent()->getID() == -1) {
	    break;
	  }
	  else if (n->getNext()->getStudent()->getID() == id) {
	    r = true;
	    cout << "A student with that ID already exists! Please retype." << endl;
	    break;
	  }
	  Node* t = n->getNext();
	  n = t;
	}
	if (r == false) {
	  break;
	}
      }
      
      cout << "Student GPA: ";
      cin >> gpa; cin.clear(); cin.ignore(100, '\n');
      cout << endl;

      //Put all o' that knowledge into a student
      s->setName(name);
      s->setSurname(surname);
      s->setID(id);
      s->setGPA(gpa);

      //Make a new node with that student
      Node* newNode = new Node(s);

      //Stick it into the borg collective
      add(head, head, newNode);      
    }
      
    //List all current students
    else if ((cmd[0] == 'P' || cmd[0] == 'p') &&
	     (cmd[1] == 'R' || cmd[1] == 'r') &&
	     (cmd[2] == 'I' || cmd[2] == 'i') &&
	     (cmd[3] == 'N' || cmd[3] == 'n') &&
	     (cmd[4] == 'T' || cmd[4] == 't')) {

      if (head->getNext()->getStudent()->getID() != -1) {
	print(head->getNext(), 0);
      }
      else {
	cout << "EMPTY" << endl;
      }
      
      /*Node* n;
      Node* m;
      n = head;
      m = n;

      //Go through the chain and print all o' them kids
      for (int i = 0; i < 10; i++) {
	n = m;
	cout << "Student #" << i+1 << ":" << endl
	     << "Name: " << n->getNext()->getStudent()->getName() << " " << n->getNext()->getStudent()->getSurname() << endl
	     << "ID: " << n->getNext()->getStudent()->getID() << endl
	     << "GPA: " << n->getNext()->getStudent()->getGPA() << endl << endl;
	m = n->getNext();
      }*/
      
    }

    //Delete a student
    else if ((cmd[0] == 'D' || cmd[0] == 'd') &&
	     (cmd[1] == 'E' || cmd[1] == 'e') &&
	     (cmd[2] == 'L' || cmd[2] == 'l') &&
	     (cmd[3] == 'E' || cmd[3] == 'e') &&
	     (cmd[4] == 'T' || cmd[4] == 't') &&
	     (cmd[5] == 'E' || cmd[5] == 'e')) {
      
      int id;

      //Get parameters
      cout << "Student ID: ";
      cin >> id; cin.clear(); cin.ignore(100, '\n');

      //cout << id << endl;
      //Remove it from the borg collective just like Seven of Nine from Star Trek
      del(head, id);
    }

    //I could have done the following function this way, but I have decided that my brute force method is better, even though it's way less efficient
    //    else if (strcmp("mean", cmd) == 0 || strcmp("Mean", cmd) == 0 || strcmp("MEAN", cmd)) {

    //Print out the average of each student's IDs
    else if ((cmd[0] == 'A' || cmd[0] == 'a') &&
	     (cmd[1] == 'V' || cmd[1] == 'v') &&
	     (cmd[2] == 'E' || cmd[2] == 'e') &&
	     (cmd[3] == 'R' || cmd[3] == 'r') &&
	     (cmd[4] == 'A' || cmd[4] == 'a') &&
	     (cmd[5] == 'G' || cmd[5] == 'g') &&
	     (cmd[6] == 'E' || cmd[6] == 'e')) {
      float ave = 0;
      int cnt = 0;
      Node* temp = head;

      //Go through and add together every id, stored in ave, and then divide it by the number of numbers, which is cnt, and boom! Average.
      while (true) {
	if (temp->getNext()->getStudent()->getID() != -1) {
	  ave += temp->getNext()->getStudent()->getGPA();
	  cnt++;
	  temp = temp->getNext();
	}
	else {
	  if (cnt == 0) {
	    cout << "THERE ARE NO STUDENTS YET" << endl;
	  }
	  else {
	    ave = ave / cnt;
	    if (cnt == 1) {
	      cout << "There is only 1 student, so the average GPA is " << ave << "." << endl;
	    }
	    else {
	      cout << "The average of the " << cnt << " students' GPAs is " << ave << "." << endl;
	    }
	  }
	  break;
	}
      }
    }

    //Kill the program
    else if ((cmd[0] == 'Q' || cmd[0] == 'q') &&
	     (cmd[1] == 'U' || cmd[1] == 'u') &&
	     (cmd[2] == 'I' || cmd[2] == 'i') &&
	     (cmd[3] == 'T' || cmd[3] == 't')) {
      cout << "Okay, bye. Thank you for donating to the Child Storage Association (CSA)!" << endl;
      return 0;
    }
    
    else {
      cout << "COMMAND NOT RECOGNIZED" << endl;
    }

    cout << "-----";
  }
}

//Looks for a Node with an ID higher than newNode, and one that is lower than newNode. Once it has found that spot, it sandwiches newNode in there. Until then, it will keep calling itself to go through each possible sandwich destination before the correct one. RECURSION ACQUIRED!
void add(Node*& headr, Node* head, Node* newNode) {
  //"headr" is the head passed by reference, and head is headr passed by pointer. We will not be using "headr" until the insert function. "newNode" is the newNode which will be inserted.
  
  //If next is the tail, or if newNode is in between this and next, insert
  if ((head->getNext()->getStudent()->getID() == -1) ||
      (head->getStudent()->getID() < newNode->getStudent()->getID() &&
       head->getNext()->getStudent()->getID() > newNode->getStudent()->getID())) {
    //cout << head->getNext()->getStudent()->getID() << ", success"  << endl;
    //Insert
    Node* temp = head->getNext();
    newNode->setNext(temp);
    head->setNext(newNode);
  }
  else {
    //cout << head->getNext()->getStudent()->getID() << ", again!"  << endl;
    
    add(headr, head->getNext(), newNode);
  }
  
}

//Prints out a single student, then calls itself over and over again until there are no more students
void print(Node* n, int iter) {
  cout << "Student #" << ++iter << " -" << endl
       << "Name: " << n->getStudent()->getName() << " " << n->getStudent()->getSurname() << endl
       << "ID: " << n->getStudent()->getID() << endl
       << "GPA: " << n->getStudent()->getGPA() << endl;

    if (n->getNext()->getStudent()->getID() != -1) {
      print(n->getNext(), iter);
    }
    else {
      cout << endl;
    }
}

//Looks through each Student using recursion until it finds the one with the specified ID. It then frees it from the collective so that it can go join the U.S.S. Voyager.
void del(Node* head, int id) {

  //cout << head->getNext()->getStudent()->getID() << endl;
  if (head->getNext()->getStudent()->getID() == -1) {
    cout << "No student with that ID was found!" << endl;
  }
  //If next is the tail, or if newNode is in between this and next, insert
  else if (head->getNext()->getStudent()->getID() == id) {
    //cout << head->getNext()->getStudent()->getID() << ", success"  << endl;
    //Delete
    Node* temp = head->getNext()->getNext();
    head->setNext(temp);
    cout << "Student deleted." << endl;
  }
  else {
    //cout << head->getNext()->getStudent()->getID() << ", again!"  << endl;
    del(head->getNext(), id);
  }
	
}

//Old code
//int iter = 0;
  //iter++;
  /*
  Node* n;
  n = &head;
  Node* m = n;
  
  //Cycle through the chain until *n is the very last Node in the chain
  for (int i = 0; m.getNext()->getStudent()->getID() != -1; i++) {
    *n = *n->getNext();
    Node m = *n;
  }
  //Once that has happened, add a new link to the end
  *n->getNext()->setNext(m.getNext());
  Node* n;
  Node* m;
  m = head;
  
  //This is all to try and get to the last Node in the chain
  for (int i = 0; i < iter; i++) {
    n = m;
    m = n->getNext();
    //cout << i << endl;
  }
  
  Node* o = new Node(s);
  m->setNext(o);
  //cout << m->getNext()->getStudent()->getID() << endl;
  */

/*
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

