#include "../include/headerA3.h"

void sortEmployeesId(struct employee *headLL){
  
    struct employee *temp = headLL;

    //strcuture variable
    struct sorted_employee{
        int id;
        struct employee *employee;
        struct sorted_employee *nextEmployee;
    };
    
    
    struct sorted_employee *head = NULL;

    while (temp != NULL){
        struct sorted_employee *node = malloc(sizeof(struct sorted_employee));

        node->id = temp->empId;
        node->employee = temp;
        node->nextEmployee = NULL;

        if (head == NULL){
            head = node;
        }
        else{
            struct sorted_employee *prev = NULL;
            struct sorted_employee *tempSorted = head;

            while (tempSorted != NULL && tempSorted->id < node->id){
                prev = tempSorted;
                tempSorted = tempSorted->nextEmployee;
            }

            if (prev == NULL){
                node->nextEmployee = head;
                head = node;
            }
            else{
                node->nextEmployee = prev->nextEmployee;
                prev->nextEmployee = node;
            }
        }
        temp = temp->nextEmployee;
    }

    printf("After sorting on id, the employees are as follows: \n\n");
    
    int index = 1;   // intializing
    
    //printing in while
    while (head != NULL){
        printf("Employee # %d\n", index);
        printf("\tEmployee id: %d\n", head->employee->empId);
        printf("\tFirst name: %s\n", head->employee->fname);
        printf("\tLast name: %s\n", head->employee->lname);
        printf("\tDependents[%d]: ", head->employee->numDependents);

        for (int i = 0; i < head->employee->numDependents; i++){
            printf("%s", head->employee->dependents[i]);  
            if (head->employee->numDependents != i + 1){
                printf(",");
            }
        }

        printf("\n\n");

        index += 1; //incrementing

        struct sorted_employee *temp = head;
        head = head->nextEmployee;
        
        free(temp); // freeing the data
    }
}
