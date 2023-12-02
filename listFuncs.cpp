// Name: Steve Regala
// USC NetID: sregala
// CSCI 455 PA5
// Fall 2021


#include <iostream>

#include <cassert>

#include "listFuncs.h"

using namespace std;

Node::Node(const string &theKey, int theValue) {
   key = theKey;
   value = theValue;
   next = NULL;
}

Node::Node(const string &theKey, int theValue, Node *n) {
   key = theKey;
   value = theValue;
   next = n;
}



//*************************************************************************
// put the function definitions for your list functions below


bool listInsert(ListType &list, const string &target, int value) {

   // NULL case
   if (list == NULL) {
      list = new Node(target, value);
      return true;
   }

   // check if target is already a key
   Node *p = list;
   while (p!=NULL) {
      if (p->key == target) {
         return false;
      }
      p=p->next;
   }

   // insert at the front
   list = new Node(target, value, list);
   return true;

}


bool listRemove(ListType &list, const string &target) {

   // NULL case
   if (list==NULL) {
      return false;
   }

   Node *p = list;
   Node *holdNode = list; // node holder, keeps track of where to point after deletion

   while (p!=NULL) {

      if (p->key == target) {

         // case when target is the first element
         if (p==holdNode) {
            list = list->next;
            delete p;
            return true;
         }
         
         while (holdNode->next != p) {
            holdNode=holdNode->next; 
         }
         // point holdNode's next to p's next, then delete p
         holdNode->next=p->next;
         delete p;
         return true;

      }
      
      p=p->next;
   }

   return false;
}


int *lookupValue(ListType &list,const std::string &targetKey) {

   Node *p = list;

   while (p!=NULL) {
      if (p->key == targetKey) {
         return &p->value;
      }
      p=p->next;
   }

   return NULL;
}


void printList(ListType &list) {

   Node * p = list;
   while (p!=NULL) {
      cout << p->key << " " << p->value << endl;
      p=p->next;
   }

}


int numNodes(ListType &list) {

   int count=0;
   Node *p = list;
   while (p!=NULL) {
      count++;
      p=p->next;
   }

   return count;
}