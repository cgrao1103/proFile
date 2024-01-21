#include "../include/headerA3.h"

//Menu 4 - looks for the data by entering the id

int lookOnId(struct employee *headLL, int whichEmpId) {
  
  struct employee *emp = headLL;

  //intializing count 
  int count = 0;

  // while loop until the employee is found 
  while (emp != NULL) {
    count++; //adding count 
    if (emp->empId == whichEmpId) {
      return count; //returns value count 
    }
    emp = emp->nextEmployee;
  }

  return -1; //returns -1 if not found 
}
