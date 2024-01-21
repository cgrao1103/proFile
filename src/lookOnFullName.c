#include "../include/headerA3.h"
#include <stdio.h>

//Menu 5 - looks for the employee by using their full name
int lookOnFullName(struct employee *headLL, char whichName[100]) {
    //intializing a postion of 0
    int pos = 0;

  //pointing to head
    struct employee *emp = headLL;

  //while loop for the function 
    while (emp != NULL) {
        pos++;
        char fullName[100]; //intializing temp string 
        strcpy(fullName, emp->fname);
        strcat(fullName, " ");
        strcat(fullName, emp->lname);

        //if the name is found it returns the output
        if (strcmp(whichName, fullName) == 0) {
            return pos;
        }

        emp = emp->nextEmployee;
    }

   //returns -1 if doesnt exists 
    return -1;
}