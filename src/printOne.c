#include "../include/headerA3.h"
#include <stdio.h>

//Menu 3 - printing one emp
void printOne(struct employee *headLL, int whichOne) {

  if (headLL == NULL) {
    printf("No employees in the list.\n");
    return;
  }

  struct employee *emp = headLL;
  int count = 1;

  //while loop until the employee position found
  while (emp != NULL && count < whichOne) {
    emp = emp->nextEmployee;
    count++;
  }

  if (emp == NULL) {
    printf("Employee not found at position %d\n", whichOne);
    return;
  }

  //printing in order
  printf("Employee id: %d\n", emp->empId);
  printf("First name: %s\n", emp->fname);
  printf("Last name: %s\n", emp->lname);
  printf("Dependents: ");

  //to print all the dependents associated
  for (int i = 0; i < emp->numDependents; i++) {
    printf("%s", emp->dependents[i]);
    if (i < emp->numDependents - 1) {
      printf(", ");
    }
  }

  printf("\n");
}
