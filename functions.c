#include "restaurant.h"

void doAdd (Node **head)
{
 /* get group size from input */
 int size = getPosInt();
 if (size < 1)
   {
    printf ("Error: Add command requires an integer value of at least 1\n");
    printf ("Add command is of form: a <size> <name>\n");
    printf ("  where: <size> is the size of the group making the reservation\n");
    printf ("         <name> is the name of the group making the reservation\n");
    return;
   }

 /* get group name from input */
 char *name = getName();
 if (NULL == name)
   {
    printf ("Error: Add command requires a name to be given\n");
    printf ("Add command is of form: a <size> <name>\n");
    printf ("  where: <size> is the size of the group making the reservation\n");
    printf ("         <name> is the name of the group making the reservation\n");
    return;
   }



 // check for same name
 if (doesNameExist(head, name) == TRUE) {
     printf("Sorry name already exists, please try another\n");
     free(name);
     return;
 }

 // add to list
 printf ("Adding In-restaurant group \"%s\" of size %d\n", name, size);
 addToList(head, name, size, TRUE);

}

//--------------------------------------------------------------------------------------------------------------------------
void doCallAhead (Node **head)
{
 /* get group size from input */
 int size = getPosInt();
 if (size < 1)
   {
    printf ("Error: Call-ahead command requires an integer value of at least 1\n");
    printf ("Call-ahead command is of form: c <size> <name>\n");
    printf ("  where: <size> is the size of the group making the reservation\n");
    printf ("         <name> is the name of the group making the reservation\n");
    return;
   }

 /* get group name from input */
 char *name = getName();
 if (NULL == name)
   {
    printf ("Error: Call-ahead command requires a name to be given\n");
    printf ("Call-ahead command is of form: c <size> <name>\n");
    printf ("  where: <size> is the size of the group making the reservation\n");
    printf ("         <name> is the name of the group making the reservation\n");
    return;
   }

 // check for already existing name
 if (doesNameExist(head, name) == TRUE) {
     printf("Sorry name already exists, please try another\n");
     free(name);
     return;
 }

 // add to list
 printf ("Adding Call-ahead group \"%s\" of size %d\n", name, size);
 addToList(head, name, size, FALSE);


}

//----------------------------------------------------------------------------------------------------------------------------------
void doWaiting (Node **head)
{
 /* get group name from input */
 char *name = getName();
 if (NULL == name)
   {
    printf ("Error: Waiting command requires a name to be given\n");
    printf ("Waiting command is of form: w <name>\n");
    printf ("  where: <name> is the name of the group that is now waiting\n");
    return;
   }

 // check if the person exists
 if (doesNameExist(head, name) == FALSE) {
     printf("Sorry we could not find your name\n");
     free(name);
     return;
 }

 // check if their status is already true
 if (updateStatus(head, name) == FALSE) {
     printf("This group is already set to waiting inside resturant\n");
     free(name);
     return;
 }

 // update status
 else {
     updateStatus(head,name);
     printf("Call-ahead group \"%s\" is now waiting in the restaurant\n", name);
     free(name);
     return;
 }


}

//--------------------------------------------------------------------------------------------------------------------------------------
void doRetrieve (Node **head)
{
 /* get table size from input */
 int size = getPosInt();
 if (size < 1)
   {
    printf ("Error: Retrieve command requires an integer value of at least 1\n");
    printf ("Retrieve command is of form: r <size>\n");
    printf ("  where: <size> is the size of the group making the reservation\n");
    return;
   }
 clearToEoln();

 char *retrieveName;  // store the name

 // get the name back
 retrieveName = retrieveAndRemove(head, size);

 // onnly print out if a name actually came back
 if (retrieveName != NULL) {
     printf ("Retrieved the group \"%s\" that can fit at a table of size %d\n", retrieveName, size);
     free (retrieveName);
 }

}

//---------------------------------------------------------------------------------------------------------------------------------------
void doList (Node **head)
{
 /* get group name from input */
 char *name = getName();
 if (NULL == name)
   {
    printf ("Error: List command requires a name to be given\n");
    printf ("List command is of form: l <name>\n");
    printf ("  where: <name> is the name of the group to inquire about\n");
    return;
   }

 // check for name
 if (doesNameExist(head, name) == FALSE) {
     printf("Sorry we could not find your name\n");
     free(name);
     return;
 }

 int peopleAhead;
 peopleAhead = countGroupsAhead(head, name);      // count how many are ahead

 printf("There are %d groups ahead of \"%s\" \n", peopleAhead, name);

 printf ("Group \"%s\" is behind the following groups:\n", name);
 displayGroupSizeAhead(head, name);
 free(name);

}

//-------------------------------------------------------------------------------------------------------------------------------------------
void doDisplay (Node **head)
{
 clearToEoln();
 printf ("Display information about all groups:\n");

 displayListInformation(head);



}

//------------------------------------------------------------------------------------------------------------------------------------------------
