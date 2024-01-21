#include "../include/headerA3.h"

int main(int argc, char **argv) {

  // intializing variables
  a3Emp *headLL = NULL;
  int task = 0;
  char fullName[100];
  int pos;
  int whichEmpId;
  int whichOne;
  char ans;
  loadEmpData(&headLL, "proFile.txt");
  // do while loop menu
  do {
    printf("1. Add a new employee\n");
    printf("2. Print data of all employees\n");
    printf("3. Print data of the nth employee\n");
    printf("4. Search for employee based on empId\n");
    printf("5. Search for employee based on full name\n");
    printf("6. Count the total number of employees\n");
    printf("7. Sort the employees based on their empId\n");
    printf("8. Remove the nth employee in the current LL\n");
    printf("9. Remove all employees in the current LL\n");
    printf("10. Exit\n");
    printf("\nChoose a menu option: ");

    (void)!scanf("%d", &task);
    printf("\n");

    switch (task) {

    // Menu 1
    case 1:
      recruitEmployee(&headLL); // Calling
      break;

    // Menu 2
    case 2:
      printAll(headLL); // Calling
      break;

    // Menu 3
    case 3:
      printf("Enter a position: ");
      (void)!scanf("%d", &pos);
      printf("\n");
      printOne(headLL, pos);
      break;

    case 4:
      printf("Enter an employee ID: ");
      (void)!scanf("%d", &whichEmpId);
      printf("\n");
      int position = lookOnId(headLL, whichEmpId);
      if (position != -1) {
        printOne(headLL, position); /*print details by calling printOne*/
      } else {
        printf("Employee with ID %d not found.\n", whichEmpId);
      }
      break;

    case 5:
      printf("Enter the full name of the employee: ");
      (void)!scanf(" %[^\n]", fullName);
      printf("\n");

      position = lookOnFullName(headLL, fullName);

      if (position != -1) {
        printOne(headLL, position);
      } else {
        printf("Employee not found.\n");
      }
      break;

    case 6:
      printf("Total number of employees = %d\n", countEmployees(headLL));
      break;

    case 7:
      sortEmployeesId(headLL);
      break;

    case 8:
      printf("Currently there are %d employees.\n", countEmployees(headLL));
      printf("\nWhich employee do you wish to fire – enter a value between 1 "
             "and %d: ",
             countEmployees(headLL));
      (void)!scanf("%d", &whichOne);
      fireOne(&headLL, whichOne);
      printf("\nThere are now %d employees.\n\n", countEmployees(headLL));
      break;

    case 9:
      printf("Are you sure you want to fire everyone: ");
      (void)!scanf(" %c", &ans);
      if (ans == 'y' || ans == 'Y') {
        fireAll(&headLL);
      }
      break;

    case 10:
      printf("Exiting...\n");
      break;

    default:
      printf("Invalid menu option.\n");
      break;
    }
    printf("\n");
  } while (task != 10);

  free(headLL);

  return 0;
}