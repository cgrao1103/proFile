#include "../include/headerA3.h"

//Menu 6 - counts the existing employees

int countEmployees (a3Emp * headLL){
    
  int count=0; //intializing count
    
  a3Emp* pos = headLL;
  
  //while index is not a null value
  while(pos != NULL){
    count++;
    pos = pos->nextEmployee;
  }
  
  return count; //returns an int
}
