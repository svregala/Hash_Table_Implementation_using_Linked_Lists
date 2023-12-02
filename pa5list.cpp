// Name: Steve Regala
// USC NetID: sregala
// CS 455 PA5
// Fall 2021

// pa5list.cpp
// a program to test the linked list code necessary for a hash table chain

// You are not required to submit this program for pa5.

// We gave you this starter file for it so you don't have to figure
// out the #include stuff.  The code that's being tested will be in
// listFuncs.cpp, which uses the header file listFuncs.h

// The pa5 Makefile includes a rule that compiles these two modules
// into one executable.

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

#include "listFuncs.h"

void testInsert();

void testRemove();

void testLookUpValue();

void testNumNodes();

int main() {

   testInsert();

   cout << "---------------------------------" << endl;

   testRemove();

   cout << "---------------------------------" << endl;

   testLookUpValue();

   cout << "---------------------------------" << endl;

   testNumNodes();

   return 0;
}


void testInsert() {

   cout << endl << "Testing listInsert.." << endl;
   Node* list1 = new Node("first", 1);

   printList(list1);
   cout << "(exp: first 1)" << endl << endl;

   // test true
   bool testInsert1 = listInsert(list1, "second", 2);
   // test false
   bool testInsert2 = listInsert(list1, "second", 98);

   // test true
   bool testInsert3 = listInsert(list1, "third", 10);

   if (testInsert1) {
      cout << "testInsert1 is true" << endl;
   }
   else {
      cout << "testInsert1 is false" << endl;
   }

   if (testInsert2) {
      cout << "testInsert2 is true" << endl;
   }
   else {
      cout << "testInsert2 is false" << endl;
   }

   if (testInsert3) {
      cout << "testInsert3 is true" << endl;
   }
   else {
      cout << "testInsert3 is false" << endl;
   }

   cout << endl;

   cout << "Our current list is..." << endl;
   printList(list1);

   cout << "exp:" << endl;
   cout << "third 10" << endl;
   cout << "second 2" << endl;
   cout << "first 1" << endl;

}

void testRemove() {

   cout << endl << "Testing listRemove..." << endl;

   // remove the only item in the list
   cout <<  "Testing listRemove on a one item list" << endl;
   Node* oneItem = new Node("onlyOne", 11);
   bool remOneItem = listRemove(oneItem, "onlyOne");
   if (remOneItem) { 
      cout << "Removed onlyOne" << endl;
   }
   else {
      cout << "DID NOT remove onlyOne" << endl;
   }

   cout << "The empty list is: " << endl;
   printList(oneItem);

   cout << endl <<  "^^^" << endl;
   cout << endl;

   cout << "Testing listRemove on a well-formed list" << endl;
   Node* list1 = new Node("firstOne", 10);
   bool insert1 = listInsert(list1, "second", 2);
   bool insert2 = listInsert(list1, "third", 98);
   bool insert3 = listInsert(list1, "fourth", 23);
   bool insert4 = listInsert(list1, "fifth", 8);
   bool insert5 = listInsert(list1, "sixth", 12);
   bool insert6 = listInsert(list1, "seventh", 10);

   cout << "The original list is:" << endl;
   printList(list1);
   cout << endl;

   // delete first element
   bool delete1 = listRemove(list1, "seventh");
   cout << "'seventh' key is now gone..." << endl;
   printList(list1);
   cout << endl;

   // delete last element
   bool delete2 = listRemove(list1, "firstOne");
   cout << "'firstOne' is now gone..." << endl;
   printList(list1);
   cout << endl;

   // delete middle
   bool delete3 = listRemove(list1, "fourth");
   cout << "'fourth' is now gone..." << endl;
   printList(list1);
   cout << endl;

   // delete non-existent
   cout << "Remove non-existent element..." << endl;
   bool remNonExistent = listRemove(list1, "NonExistent");
   if (!remNonExistent) {
      cout << "remNonExistent is false, as expected" << endl;
   }
   else {
      cout << "remNonExistent FAILED";
   }
   cout << endl;

   // keep deleting
   bool delete4 = listRemove(list1, "fifth");
   cout << "'fifth' is now gone..." << endl;
   printList(list1);
   cout << endl;

   bool delete5 = listRemove(list1, "third");
   cout << "'third' is now gone..." << endl;
   printList(list1);
   cout << endl;

   bool delete6 = listRemove(list1, "second");
   cout << "'second' is now gone..." << endl;
   printList(list1);
   cout << endl;

   bool delete7 = listRemove(list1, "sixth");
   cout << "the last element 'sixth' is now gone..." << endl;
   printList(list1);
   cout << endl;

   cout << "delete from an empty list" << endl;
   bool deleteFromEmpty = listRemove(list1, "sixth");
   if (!deleteFromEmpty) {
      cout << "listRemove worked on an empty list" << endl;
   }
   else {
      cout << "failed on an empty list";
   }
   cout << "printing list..." << endl;
   printList(list1);
   cout << endl;

}

void testLookUpValue() {

   cout << endl << "Testing lookupValue..." << endl;
   Node* list1 = new Node("first", 1);
   bool insert2 = listInsert(list1, "second", 2);
   bool insert3 = listInsert(list1, "third", 3);

   int *val = lookupValue(list1, "fourth");
   if (val == NULL) {
      cout << "lookupValue worked for non-existent key" << endl;
   }
   else {
      cout << "lookupValue failed" << endl;
   }

   int *valOne = lookupValue(list1, "second");
   if (valOne == NULL) {
      cout << "lookupValue failed" << endl;
   }
   else {
      cout << "lookupValue worked" << endl;
   }

   cout << endl;

   cout << "Original list:" << endl;
   printList(list1);

   cout << "Modified list: <second, 2> becomes <second, 4>" << endl;
   (*valOne)++;
   (*valOne)++;
   printList(list1);

}

void testNumNodes() {

   cout << endl << "Testing numNodes..." << endl;
   Node* list1 = new Node("first", 1);
   bool insert2 = listInsert(list1, "second", 2);
   bool insert3 = listInsert(list1, "third", 3);
   bool insert4 = listInsert(list1, "fourth", 1);

   int numberOfNodes = numNodes(list1);

   cout << numberOfNodes << endl;
   cout << "exp: 4" << endl;

}