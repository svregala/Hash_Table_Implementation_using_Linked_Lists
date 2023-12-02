// Name: Steve Regala
// USC NetID: sregala
// CSCI 455 PA5
// Fall 2021

/*
 * grades.cpp
 * A program to test the Table class.
 * How to run it:
 *      grades [hashSize]
 * 
 * the optional argument hashSize is the size of hash table to use.
 * if it's not given, the program uses default size (Table::HASH_SIZE)
 *
 */

#include "Table.h"

// cstdlib needed for call to atoi
#include <cstdlib>

using namespace std;


/*
- this helper function passes in the Table pointer by reference 
- it will handle the user command arguments, and will keep prompting the user to enter commands
*/
void runProgram(Table* &theGrades);


/*
- prints a brief command summary
*/
void printCommandSummary();


/*
- this helper function passes in the Table pointer by reference, the user command by value, 
  the key (to be inserted or changed) by reference, and the corresponding value by value
- if the user inputs the 'insert' or 'change' command, this helper function will be called
- it performs the insert and/or change functions on the object pointed to by the Table pointer
*/
void insertChangeFunctions(Table* &theGrades, string theCommand, string &theKey, int theValue);


/*
- this helper function passes in the Table pointer by reference, the user command by value,
  and the key (to be looked up or removed) by reference
- if the user inputs 'lookup' or 'remove' command, this helper function will be called
- it performs the lookup and/or remove functions on the object pointed to by the Table pointer
*/
void lookupRemoveFunctions(Table* &theGrades, string theCommand, string &theKey);


/*
- this helper function passes in the Table pointer by reference, and the user command by value
- if the user inputs the other functions such as 'print', 'size', 'stats', or 'help', this helper 
  function will be called
- it performs the print, size, stats, and/or help functions on the object pointed to by the Table pointer
*/
void otherFunctions(Table* &theGrades, string theCommand);


int main(int argc, char * argv[]) {

   // gets the hash table size from the command line

   int hashSize = Table::HASH_SIZE;

   Table * grades;  // Table is dynamically allocated below, so we can call
   // different constructors depending on input from the user.

   if (argc > 1) {
      hashSize = atoi(argv[1]);  // atoi converts c-string to int

      if (hashSize < 1) {
         cout << "Command line argument (hashSize) must be a positive number" 
              << endl;
         return 1;
      }

      grades = new Table(hashSize);

   }
   else {   // no command line args given -- use default table size
      grades = new Table();
   }


   grades->hashStats(cout);

   // add more code here
   // Reminder: use -> when calling Table methods, since grades is type Table*

   runProgram(grades);

   return 0;
}


void runProgram(Table* &theGrades) {

   string command;
   string name;
   int scoreValue;
   bool keepgoing = true;

   cout << "cmd> ";

   do {
      cin >> command;

      if (command=="insert" || command=="change") {
         cin >> name;
         cin >> scoreValue;
         // call insert and change helper here
         insertChangeFunctions(theGrades, command, name, scoreValue);
         cout << "cmd> ";
      }

      else if (command=="lookup" || command=="remove") {
         cin >> name;
         // call lookup and remove helper here
         lookupRemoveFunctions(theGrades, command, name);
         cout << "cmd> ";
      }

      else if (command=="print" || command=="size" || command=="stats" || command=="help") {
         // call print, size, stats, and help helper here
         otherFunctions(theGrades, command);
         cout << "cmd> ";
      }

      else if (command=="quit") {
         keepgoing = false;
      }

      else {
         cout << "ERROR: invalid command" << endl;
         printCommandSummary();
         cout << "cmd> ";
      }
      
   } while (keepgoing);

}


void printCommandSummary() {

   cout << "Valid commands are:" << endl;
   cout << "(1) insert [name] [score] - (Insert name and score)" << endl;
   cout << "(2) change [name] [newscore] - (Change the score for name)" << endl;
   cout << "(3) lookup [name] - (Lookup the score for name)" << endl;
   cout << "(4) remove [name] - (Remove name)" << endl;
   cout << "(5) print - (Print out entries)" << endl;
   cout << "(6) size - (Print out number of entries)" << endl;
   cout << "(7) stats - (Print out statistics about table)" << endl;
   cout << "(8) help - (Command Summary)" << endl;
   cout << "(9) quit - (Exit program)" << endl;

}


void insertChangeFunctions(Table* &theGrades, string theCommand, string &theKey, int theValue) {

   if (theCommand=="insert") {

      bool inserted = theGrades->insert(theKey, theValue);
      if (!inserted){
         cout << theKey << " is already in the table." << endl;
      }

   }

   else if (theCommand=="change") {

      int* val = theGrades->lookup(theKey);
      if (val == NULL) {
         cout << theKey << " is not present in the table." << endl;
      }
      else {
         (*val) = theValue;
      }

   }

}


void lookupRemoveFunctions(Table* &theGrades, string theCommand, string &theKey) {

   if (theCommand=="lookup") {

      int* val = theGrades->lookup(theKey);
      if (val == NULL) {
         cout << theKey << " is not present in the table." << endl;
      }
      else {
         cout << (*val) << endl;
      }

   }

   else if (theCommand == "remove") {
      
      bool deleted = theGrades->remove(theKey);
      if (!deleted) {
         cout << theKey << " is not present in the table." << endl;
      }

   }

}


void otherFunctions(Table* &theGrades, string theCommand) {

   if (theCommand=="print") {
      theGrades->printAll();
   }

   else if (theCommand=="size") {
      cout << theGrades->numEntries() << endl;
   }

   else if (theCommand=="stats") {
      theGrades->hashStats(cout);
   }

   else if (theCommand=="help") {
      printCommandSummary();
   }

}