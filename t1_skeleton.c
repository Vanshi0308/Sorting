#include <stdio.h>
#include <stdlib.h>
#include "t1.h"


//Fills the array with ascending, consecutive numbers, starting from 0.
void fill_ascending(int *array, int size)
{
    for(int i=0; i<size; i++)
        {
            *(array+i) = i;
        }
    
}
//Fills the array with descending numbers, starting from size-1
void fill_descending(int *array, int size)
{
    for(int i=size-1;i>=0;i--)
        {
            *(array+i) = i;
        }
}

//Fills the array with uniform numbers.
void fill_uniform(int *array, int size)
{
    int val = 3;
    for(int i=0;i<size;i++)
        {
            *(array+i) = val;
        }
}

//Fills the array with random numbers within 0 and size-1. Duplicates are allowed.
void fill_with_duplicates(int *array, int size)
{
    int random_number;
    for(int i=0;i<size;i++)
        {
            random_number = rand() % size/2;
            *(array+i) = random_number;
        }
}   


//Fills the array with unique numbers between 0 and size-1 in a shuffled order. Duplicates are not allowed.
void fill_without_duplicates(int *array, int size)
{
    for(int i=0;i<size;i++)
        {
            *(array+i) = i;
        }
    int temp, randomIndex;
    for (int i = 0; i < size; i++) {    // shuffle array
        temp = *(array+i);
        randomIndex = rand() % size;

        *(array+i)          = *(array+randomIndex);
        *(array+randomIndex) = temp;
        }
    
}

void printArray(int* arr, int size){
  int i;
  for(i=0; i<size;i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
}

