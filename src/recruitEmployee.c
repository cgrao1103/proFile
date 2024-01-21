#include "../include/headerA3.h"

void recruitEmployee(struct employee **headLL) {
    
  // creating a new emp node
  struct employee *newEmployee = (struct employee *)malloc(sizeof(struct employee));

  // taking user details
  printf("\nEnter the first name of the employee: ");
  (void)!scanf("%s", newEmployee->fname);

  printf("Enter the last name of the employee: ");
  (void)!scanf("%s", newEmployee->lname);

  // generating the automated emp id
  int empId = 0;
  for (int i = 0; i < strlen(newEmployee->fname); i++) {
    empId += (int)newEmployee->fname[i];
  }

  empId += strlen(newEmployee->lname);
  newEmployee->empId = empId;

  
  struct employee *currentEmployee = *headLL;
  while (currentEmployee != NULL) {

    if (currentEmployee->empId == newEmployee->empId) {
      newEmployee->empId += rand() % 999 + 1; //random function
      currentEmployee = *headLL;
    } 
    else {
      currentEmployee = currentEmployee->nextEmployee;
    }
  }

  newEmployee->numDependents = 0;
  newEmployee->dependents = NULL;
  char input = 'y';

    //do-while to enter details
  do {
    newEmployee->numDependents++;
    newEmployee->dependents = (char **)realloc( newEmployee->dependents, sizeof(char *) * newEmployee->numDependents);

    newEmployee->dependents[newEmployee->numDependents - 1] = (char *)malloc(sizeof(char) * MAX_LENGTH);

    //entering dependent details
    printf("\nEnter name of dependent# %d: ", newEmployee->numDependents);
    (void)!scanf("%s", newEmployee->dependents[newEmployee->numDependents - 1]);

    printf("Do you have any more dependents? ");
    (void)!scanf(" %c", &input);
  
  } while (toupper(input) == 'Y');

  // add new employee node to linked list
  newEmployee->nextEmployee = NULL;

  if (*headLL == NULL) {
    *headLL = newEmployee;
  } 
  else {
    struct employee *currentEmployee = *headLL;

    while (currentEmployee->nextEmployee != NULL) {
      currentEmployee = currentEmployee->nextEmployee;
    }
    currentEmployee->nextEmployee = newEmployee;
  }

  if (newEmployee->numDependents == 1) {
    printf("\nYou have %d dependent.\n", newEmployee->numDependents);
  } 
  else {
    printf("\nYou have %d dependents.\n", newEmployee->numDependents);
  }

  printf("\nYour computer-generated empId is %d\n", newEmployee->empId);
    
  if (newEmployee == NULL) {
    printf("Failed to allocate memory for new employee\n");
      
    //exiting
    exit(EXIT_FAILURE);
  }
  
  if (newEmployee->dependents == NULL) {
    printf("Failed to allocate memory for dependents array\n");
      
    //exiting
    exit(EXIT_FAILURE);
    }
}
