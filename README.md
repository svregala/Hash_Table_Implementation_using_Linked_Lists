# Hash_Table_Implementation_using_Linked_Lists

**Synopsis**:
The following descriptions are as follows.

- Table.h Header file for the Table class. This contains the Table class definition (but not the method implementations). The Table class is similar in functionality to the Java Map class.

- Table.cpp Implementation file for the Table class. This contains Table method definitions. 

- listFuncs.h Header file for linked list module. Contains Node struct definition and prototypes for functions on linked lists. 

- listFuncs.cpp Implementation file for the Node struct and list functions. Contains Node constructors and definitions of functions to operate on a linked list. 

- pa5list.cpp A test program for your list functions.

- grades.cpp Test program for your Table class. It's a simple program to keep track of students and their scores in a class. The program takes one optional command-line argument, the size for the hash table -- if the argument is left off, the program uses the default hash size. When the program starts up it creates a hash table, immediately prints out the hashStats() for that empty table, and then should print the initial command prompt ("cmd> "). In the following example of program startup % is the Linux shell prompt and user input is shown:

% grades 7

number of buckets: 7

number of entries: 0

number of non-empty buckets: 0

longest chain: 0

cmd> 


Once this start-up happens the program repeatedly reads and executes commands from the user, printing out the command prompt (cmd>) after it finishes the previous command, until the user enters the quit command.

Here are the commands for the program (in the following a name will always be a single word):
- insert name score --> - Insert this name and score in the grade table. If this name was already present, print a message to that effect, and don't do the insert.
- change name newscore --> Change the score for name. Print an appropriate message if this name isn't present.
- lookup name --> Lookup the name, and print out his or her score, or a message indicating that student is not in the table.
- remove name --> Remove this student. If this student wasn't in the grade table, print a message to that effect.
- print --> Prints out all names and scores in the table.
- size --> Prints out the number of entries in the table.
- stats --> Prints out statistics about the hash table at this point. (Calls hashStats() method)
- help --> Prints out a brief command summary.
- quit --> Exits the program.


- concord.cpp A second program to try out your Table class with. Then, use concord.cpp program along with the .txt files (melville.txt and poe.txt) to test Table class with a larger amount of data.

- melville.txt and poe.txt Some text files to test the concordance program on.

- Makefile A file with rules for the "make" command. This Makefile has rules for compiling the source code to make the executables.