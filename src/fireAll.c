#include "../include/headerA3.h"

//Menu 9 - Removes all the employees from the list

void fireAll(a3Emp **headLL) {
    
  //intializing pointers
  a3Emp *pos;
  a3Emp *next = *headLL;

  //while not null
  while (next != NULL) {
    pos = next;
    next = pos->nextEmployee;
      
    //freeing the allocated memory
    for (int i = 0; i < pos->numDependents; i++) {
      free(pos->dependents[i]);
    }
    free(pos->dependents);
    free(pos);
  }

  *headLL = NULL;
    
  printf("\nAll fired. Linked list is now empty.\n");
}
