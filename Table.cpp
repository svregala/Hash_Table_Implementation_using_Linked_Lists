// Name: Steve Regala
// USC NetID: sregala
// CSCI 455 PA5
// Fall 2021

// Table.cpp  Table class implementation


#include "Table.h"

#include <iostream>
#include <string>
#include <cassert>

// for hash function called in private hashCode method defined below
#include <functional>

using namespace std;


// listFuncs.h has the definition of Node and its methods.  -- when
// you complete it it will also have the function prototypes for your
// list functions.  With this #include, you can use Node type (and
// Node*, and ListType), and call those list functions from inside
// your Table methods, below.

#include "listFuncs.h"


//*************************************************************************


Table::Table() {
   data = new ListType[HASH_SIZE]();
   hashSize = HASH_SIZE;
}


Table::Table(unsigned int hSize) {
   data = new ListType[hSize]();
   hashSize = hSize;
}


int * Table::lookup(const string &key) {

   return lookupValue(data[hashCode(key)], key);

}


bool Table::remove(const string &key) {

   return listRemove(data[hashCode(key)], key);

}


bool Table::insert(const string &key, int value) {

   return listInsert(data[hashCode(key)], key, value);

}


int Table::numEntries() const {

   int totalEntries = 0;
   for (int i=0; i<hashSize; i++) {
      totalEntries += numNodes(data[i]);
   }

   return totalEntries;
}


void Table::printAll() const {

   for (int i=0; i<hashSize; i++) {
      printList(data[i]);
   }

}


void Table::hashStats(ostream &out) const {

   out << "number of buckets: " << hashSize << endl;
   out << "number of entries: " << numEntries() << endl;
   out << "number of non-empty buckets: " << findNonEmptyBuckets() << endl;
   out << "longest chain: " << findLongestChain() << endl;

}


// hash function for a string
// (we defined it for you)
// returns a value in the range [0, hashSize)
unsigned int Table::hashCode(const string &word) const {

   // Note: calls a std library hash function for string (it uses the good hash
   //   algorithm for strings that we discussed in lecture).
   return hash<string>()(word) % hashSize;

}


// add definitions for your private methods here

int Table::findNonEmptyBuckets() const {
   int count = 0;

   for (int i=0; i<hashSize; i++) {
      if (data[i] != NULL) {
         count++;
      }
   }

   return count;
}

int Table::findLongestChain() const {
   int longChain = 0;

   for (int i=0; i<hashSize; i++) {
      if (longChain < numNodes(data[i])) {
         longChain = numNodes(data[i]);
      }
   }

   return longChain;
}
