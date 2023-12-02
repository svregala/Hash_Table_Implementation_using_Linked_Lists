// Name: Steve Regala
// USC NetID: sregala
// CSCI 455 PA5
// Fall 2021


//*************************************************************************
// Node class definition 
// and declarations for functions on ListType

// Note: we don't need Node in Table.h
// because it's used by the Table class; not by any Table client code.

// Note2: it's good practice to *not* put "using" statement in *header* files.  Thus
// here, things from std libary appear as, for example, std::string

#ifndef LIST_FUNCS_H
#define LIST_FUNCS_H

#include <string>
  

struct Node {
   std::string key;
   int value;

   Node *next;

   Node(const std::string &theKey, int theValue);

   Node(const std::string &theKey, int theValue, Node *n);
};


typedef Node * ListType;

//*************************************************************************
//add function headers (aka, function prototypes) for your functions
//that operate on a list here (i.e., each includes a parameter of type
//ListType or ListType&).  No function definitions go in this file.


/*
// inserts new node with target key and value at the front of list, return true
// returns false if target key is already present (no changes made to value of key)
*/
bool listInsert(ListType &list, const std::string &target, int value);
 

/*
// removes node with target key (type string), return true
// return false if target key was NOT present in list
*/
bool listRemove(ListType &list, const std::string &target);


/*
// returns the address of the value that goes with the passed-in key
// returns NULL if the key does not exist
*/
int *lookupValue(ListType &list, const std::string &targetKey);


/*
// print out entries in the single linked list:
//   <string, int>, <key, value>
//   zhou 283
//   sam 84
//   babs 99
*/
void printList(ListType &list);


/*
// return number of entries/nodes in list
int numNodes();
*/
int numNodes(ListType &list);


// keep the following line at the end of the file
#endif
