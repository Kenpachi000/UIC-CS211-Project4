// header file

// include libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// global variable for debug mode
extern int debugMode;

// typedef enum
typedef enum {FALSE = 0, TRUE, NO = 0, YES} boolean;

// create struct of link list
typedef struct Node {
    char *groupName;
    int groupSize;
    boolean waiting;             // is user waiting or no? 1 for yes 0 for no
    struct Node *next;
} Node;

// functions inside along with main
void clearToEoln();
int getNextNWSChar ();
int getPosInt ();
char *getName();
void printCommands();


//functions inside functions.c protypes
void doAdd (Node **head);
void doCallAhead (Node **head);
void doWaiting(Node **head);
void doRetrieve(Node **head);
void doList(Node **head);
void doDisplay(Node **head);

// functions inside linklist.c (create these functions) prototypes
void addToList(Node **head, char *groupName, int groupSize, boolean status);
boolean doesNameExist (Node **head, char *name);
boolean updateStatus (Node **head, char *name);
char *retrieveAndRemove (Node **head, int tableSize);
int countGroupsAhead (Node **head, char *name);
void displayGroupSizeAhead ( Node **head, char *name);
void displayListInformation ( Node **head);
void deleteList( Node ** head);
