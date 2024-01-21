#include "../include/headerA3.h"

void fireOne(a3Emp **headLL, int whichOne) {

  if (whichOne < 1) {
    printf("Invalid index!\n");
    return;
  }
  
  a3Emp *back = NULL;

  // pointing the cur to the head
  a3Emp *cur = *headLL;


  // while loop for if the cur doesnt exists and the count is not equal to emp
  // id

  for (int i = 1; i < whichOne && cur != NULL;
       i++) // for loop to make the pointer point at right list
  {
    back = cur;
    cur = cur->nextEmployee;
  }
  

  // reutrns if there is no employee found
  if (cur == NULL) {
    printf("Emplyee not found!");
    return;
  }

  // if the previous employee doesn't exists it skips to the next
  if (back == NULL) {
    *headLL = cur->nextEmployee;
  } 
  else {
    back->nextEmployee = cur->nextEmployee;
  }

  printf("Employee [Id : %d] fired. ", cur->empId);

  // freeing
  for (int i = 0; i < cur->numDependents; i++) {
    free(cur->dependents[i]);
  }
  free(cur->dependents);
  free(cur);
}

/*void fireOne(a3Emp **headLL, int whichOne) {

  if (whichOne < 1) {
    printf("Invalid index!\n");
    return;
  }

  a3Emp *employee_to_remove = *headLL;
  a3Emp *previous_employee = NULL;

  int i;
  for (i = 1; i < whichOne && employee_to_remove != NULL;
       i++) // for loop to make the pointer point at right list
  {
    previous_employee = employee_to_remove;
    employee_to_remove = employee_to_remove->nextEmployee;
  }

  if (employee_to_remove ==
      NULL) // checking if the list that needs to be free is empty or not
  {
    printf("Employee not found!\n");
    return;
  }

  if (previous_employee ==
      NULL) // checking if the list before the list that is to be deleted is
            // empty or not and conditions accordingly
  {
    *headLL = employee_to_remove->nextEmployee;
  } else {
    previous_employee->nextEmployee = employee_to_remove->nextEmployee;
  }
  for (int i = 0; i < employee_to_remove->numDependents; i++) {
    free(employee_to_remove->dependents[i]);
  }

  free(employee_to_remove->dependents);
  free(employee_to_remove); // freeing the desired employee data in linked list
}*/
