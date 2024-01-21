#include <stdio.h>
#include "../include/headerA3.h"

void printAll(struct employee *headLL){
  
    if (headLL == NULL){
        printf("No employees in the list.\n");
        return ;
    }

    int empCount = 0;

    //printing employee info as per linked list struct
    while (headLL != NULL){
      
        printf("Employee #%d:\n", ++empCount);
        printf("\tEmployee id: %d\n", headLL->empId);
        printf("\tFirst name: %s\n", headLL->fname);
        printf("\tLast name: %s\n", headLL->lname);
        printf("\tDependents [%d]: ", headLL->numDependents);
      
        for (int i = 0; i < headLL->numDependents; i++){
            printf("%s", headLL->dependents[i]);
            if (i != headLL->numDependents - 1)
                printf(", ");
        }
      
        printf("\n\n");
        headLL = headLL->nextEmployee;
    }

  //if statements for english grammatical changes
  if(empCount == 1){
    printf("Currently, there is %d employee.\n", empCount);
  }
  else{
    printf("Currently, there are %d employees.\n", empCount);
  }
}
