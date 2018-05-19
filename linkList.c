#include "restaurant.h"

int debugMode;

// add to List
void addToList (Node **head, char *groupName, int groupSize, boolean status) {

    // allocate a new node
    Node *insert = (Node*) malloc (sizeof (Node));

    // set values
    insert->groupName = groupName;
    insert->groupSize = groupSize;
    insert->waiting = status;
    insert->next = NULL;

    // add to back of the List

    // if list is empty
    if (*head == NULL) {
        *head = insert;
        return;
    }

    Node *temp = *head;

    if(debugMode) {
        printf("Debugmode for addToList function: \n");
    }

    // get to the last spot of the List
    while (temp->next != NULL) {

        if (debugMode) {
            if (temp->waiting == TRUE) {
                printf("Group Name:  %s with a group size of %d and they are inside the restaurant\n", temp->groupName, temp->groupSize);
            }
            else {
                printf("Group Name:  %s with a group size of %d and they are NOT in the restaurant\n", temp->groupName, temp->groupSize);
            }
        }

        temp = temp->next;
    }

    // connect to the new node
    temp->next = insert;

    return;

}
//------------------------------------------------------------------------------------------------------------------------
// check for duplicate names
boolean doesNameExist (Node **head, char *name) {

    // check if it is empty
    if (*head == NULL) {
        return FALSE;
    }

    Node *temp = *head;

    if (debugMode) {
        printf("DebugMode For doesNameExist function:\n");
    }

    while (temp != NULL) {

        //debug info
        if (debugMode) {
            if (temp->waiting == TRUE) {
                printf("Group Name:  %s with a group size of %d and they are inside the restaurant\n", temp->groupName, temp->groupSize);
            }
            else {
                printf("Group Name:  %s with a group size of %d and they are NOT in the restaurant\n", temp->groupName, temp->groupSize);
            }
        }


        // use strcmp function to see if two names equal
        if (strcmp (temp->groupName, name) == 0 ) {
            return TRUE;
        }
        temp = temp->next;  // move along list
    }

    // found nothing so return FALSE
    return FALSE;

}
//-----------------------------------------------------------------------------------------------------------------------------------------
// change status at restaurant
boolean updateStatus (Node **head, char *name) {

    // check if list is empty
    if (*head == NULL) {
        return FALSE;
    }

    Node *temp = *head;

    if (debugMode) {
        printf("DebugMode for updateSTATUS function: \n");
    }

    // loop through list to find name
    while (temp != NULL) {

        //debug info
        if (debugMode) {
            if (temp->waiting == TRUE) {
                printf("Group Name:  %s with a group size of %d and they are inside the restaurant\n", temp->groupName, temp->groupSize);
            }
            else {
                printf("Group Name:  %s with a group size of %d and they are NOT in the restaurant\n", temp->groupName, temp->groupSize);
            }
        }

        // find the group name
        if (strcmp(temp->groupName, name) == 0) {

            // group is already waiting so return false
            if (temp->waiting == TRUE) {
                return FALSE;
            }

            // change group to waiting and return true
            if (temp->waiting == FALSE) {
                temp->waiting = TRUE;
                return TRUE;
            }

        } // end of outer iff

        temp = temp->next;

    } // end of while loop

    // found nothing so return FALSE
    return FALSE;

}
//-------------------------------------------------------------------------------------------------------------------------------------------
// return back name of group and delete in the link list
char *retrieveAndRemove (Node **head, int tableSize) {

    // create a new word
    char *word;
    // might need to allocate................
    Node *temp = *head;
    Node *toDelete;

    // list is empty
    if (*head == NULL) {
        printf("Error list is empty\n");
        return NULL ;
    }

    // check first node
    if (temp->groupSize <= tableSize && temp->waiting == TRUE) {

        // store the name
        word = temp->groupName;

        // move head
        *head = (*head)->next;
        free (temp);
        return word;
    }

    if (debugMode) {
        printf("Debugmode for retrieveAndRemove function:\n");
    }

    // traverse the List
    while (temp->next != NULL) {

        //debug info
        if (debugMode) {
            if (temp->waiting == TRUE) {
                printf("Group Name:  %s with a group size of %d and they are inside the restaurant\n", temp->groupName, temp->groupSize);
            }
            else {
                printf("Group Name:  %s with a group size of %d and they are NOT in the restaurant\n", temp->groupName, temp->groupSize);
            }
        }

        // check groupsizse
        if (temp->next->groupSize <= tableSize && temp->next->waiting == TRUE) {
            word = temp->next->groupName;
            toDelete = temp->next; // point to node that i want to get rid of
            temp->next = toDelete->next;
            free (toDelete);
            return word;
        }
        temp = temp->next;

    } // end of while loop

    // none
    printf("No table size available yet\n");
    return NULL;

}
//------------------------------------------------------------------------------------------------------------------------------------------
// count how many people are ahead
int countGroupsAhead (Node **head, char *name) {

    // if list is empty
    if (*head == NULL) {
        return 0;
    }

    Node *temp = *head;
    int count = 0;

    if (debugMode) {
        printf("debugMode for countGroupsAhead function:\n");
    }

    // as long as the names do not match up we book keep
    while (temp != NULL && strcmp(temp->groupName, name) != 0) {

        //debug info
        if (debugMode) {
            if (temp->waiting == TRUE) {
                printf("Group Name:  %s with a group size of %d and they are inside the restaurant\n", temp->groupName, temp->groupSize);
            }
            else {
                printf("Group Name:  %s with a group size of %d and they are NOT in the restaurant\n", temp->groupName, temp->groupSize);
            }
        }

        count++;
        temp = temp->next;
    }

    return count;

}
//-----------------------------------------------------------------------------------------------------------------------------------------------
// display groupsize ahead
void displayGroupSizeAhead ( Node **head, char *name) {

    // if list is empty
    if (*head == NULL) {
        return;
    }

    Node *temp = *head;

    // if they are on the first in Line
    if (strcmp (temp->groupName, name) == 0) {
        printf ("They are first in line!\n");
        return;
    }

    if(debugMode) {
        printf("debugmode for displayGroupSizeAhead function:\n");
    }

    // traverse through list to print out group size
    while (temp != NULL && strcmp (temp->groupName, name) != 0) {

        //debug info
        if (debugMode) {
            if (temp->waiting == TRUE) {
                printf("Group Name:  %s with a group size of %d and they are inside the restaurant\n", temp->groupName, temp->groupSize);
            }
            else {
                printf("Group Name:  %s with a group size of %d and they are NOT in the restaurant\n", temp->groupName, temp->groupSize);
            }
        }

        printf ("%s group has %d people.\n", temp->groupName, temp->groupSize);
        temp = temp->next;
    }

}
//-------------------------------------------------------------------------------------------------------------------------------------------------
void displayListInformation ( Node **head) {

    // if list is empty
    if (*head == NULL) {
        printf("No one is in waiting list\n");
        return;
    }

    Node *temp = *head;

    if (debugMode) {
        printf("DebugMode for displayListInformation function:\n");
    }

    // traverse through the list
    while (temp != NULL) {

        //debug info
        if (debugMode) {
            if (temp->waiting == TRUE) {
                printf("Group Name:  %s with a group size of %d and they are inside the restaurant\n", temp->groupName, temp->groupSize);
            }
            else {
                printf("Group Name:  %s with a group size of %d and they are NOT in the restaurant\n", temp->groupName, temp->groupSize);
            }
        }

        if (temp->waiting == TRUE) {
            printf ("Group %s with a size of %d people, and are waiting at the restaurant\n", temp->groupName, temp->groupSize);
        }
        else {
            printf ("Group %s with a size of %d people and are not at the restaurant yet \n", temp->groupName, temp->groupSize);
        }

        temp = temp->next;

    } // end of while loop

}

//--------------------------------------------------------------------------------------------------------------

// used when quitting the program to delete the entire list to avoid memory leaks
void deleteList (Node **head) {

    // if list is empty do nothing
    if (*head == NULL) {
        return;
    }

    Node *temp = *head;
    Node *temp2;
    char *name;

    while (temp != NULL) {
        name = temp->groupName;
        free (name);
        temp2 = temp->next; // point to the next in list
        free (temp); // delete the current one
        temp = temp2; // move to another one

    }

    *head = NULL;

}
