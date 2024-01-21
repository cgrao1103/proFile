#include "../include/headerA3.h"
#include <stdio.h>

//Menu 2 - Prints all employees 

void printAll(struct employee *headLL) {

  //if the employee doesnt exists 
  if (headLL == NULL) {
    printf("No employees in the list.\n");
    return;
  }

  //intializing variable 
  int empCount = 0;

  // Printing the employee data from while loop
  while (headLL != NULL) {
    
    printf("Employee #%d:\n", ++empCount);
    printf("\tEmployee id: %d\n", headLL->empId);
    printf("\tFirst name: %s\n", headLL->fname);
    printf("\tLast name: %s\n", headLL->lname);
    printf("\tDependents [%d]: ", headLL->numDependents);
    
    for (int i = 0; i < headLL->numDependents; i++) {
      printf("%s", headLL->dependents[i]);
      
      if (i != headLL->numDependents - 1)
        printf(", ");
    }
    
    printf("\n\n");
    
    headLL = headLL->nextEmployee;
  }

  // english grammatical changes
  if (empCount == 1) {
    printf("Currently, there is %d employee.\n", empCount);
  } 
  else {
    printf("Currently, there are %d employees.\n", empCount);
  }
}
