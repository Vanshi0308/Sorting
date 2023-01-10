#include <stdio.h> 
#include <stdlib.h>
#include "t2.h"

int number_comparisons = 0;
int number_swaps = 0;

void swap(int *x, int *y)
{
    number_swaps++;
    int temp = *x;    
    *x = *y;
    *y = temp;
}

void selectionSort(int arr[], int size) 
{ 
  int i, j, min;
    for (i = 0; i < size-1; i++)
    {
        min = i;
        for (j = i+1; j < size; j++)
          if (arr[j] < arr[min])
          {
              min = j;
            number_comparisons++;
          }
            
        swap(&arr[min], &arr[i]);
    }
} 

void insertionSort(int arr[], int size) 
{ 
  int i, key, j;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            number_swaps++;
        }
        number_comparisons++;
        arr[j + 1] = key;
    }
  
}

void partition_and_sort(int arr[], int first, int last)
{
  int i, j, pivot, temp;

   if(first<last){
      pivot = first;
      i = first;
      j = last;

      while(i<j){
         while(arr[i]<=arr[pivot]&&i<last)
         {
            i++;
            number_comparisons++; 
         }
        
         while(arr[j]>arr[pivot])
         {
             j--;
             number_comparisons++;
         }
         if(i<j){
            //temp = arr[i];
            //arr[i] = arr[j];
            //arr[j] = temp;
            swap(&arr[i], &arr[j]);
            number_swaps++;
         }
      }

      temp = arr[pivot];
      arr[pivot] = arr[j];
      arr[j] = temp;
      number_swaps++;
      partition_and_sort(arr,first,j-1);
      partition_and_sort(arr,j+1,last);

   }
}



void quickSort(int arr[], int size) 
{ 
 partition_and_sort(arr, 0, size-1);
}



