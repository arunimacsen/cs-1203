/* Program to implement quick sort to an array, assuming the order implied is ascending 

Algorithm: enter array -> pick pivot element -> position pivot element @ right, smaller elements to the left of it, larger elements to the right -> ouput sorted array

References: Geeks4Geeks, Programiz
*/


#include <stdio.h>
#include <stdlib.h>

//function to switch 2 elements
void swap_el(int *x, int *y)
{
    int temp; //temporary element
    
    temp = *x;
    *x = *y;
    *y = temp;
}

/* h is for higher bound and l is for lower bound
* the pivot element is the last element in the array. all elements
* are compared with the pivot element. if an element is larger, it is swapped with the pivot element
* else if it is smaller, it is swapped with the larger element
*/ 
int pickPivot(int *a, int l, int h){
  int i = l-1; //-1 to follow
  int j;
  int pivotPos = a[h]; //choosing the last element as pivot

  for(j = l; j<h; j++){
    if(pivotPos >= a[j]){
      i++;
      swap_el(&a[i], &a[j]);
    }
  }
  swap_el(&a[i+1], &a[h]);

  return (i+1);
}

/* quicksort_1 finds the pivot element s.t elements on its right 
* are larger and that on its left are smaller. 
* then it recursively calls itself on both of its sides
*/
void quicksort_1(int *a, int l, int h){
  int x; 
  
  if(h>l){
    x = pickPivot(a, l, h);
    quicksort_1(a, l, x-1);
    quicksort_1(a, x+1, h);
  } 
}

int main(void) {

  int input[100], size; //initializing array of size 100

  printf("\nEnter size of array: ");
  scanf("%d", &size);
  printf("\nEnter elements of array: ");

  int i;

  for(i=0; i<size; i++) scanf("%d", &input[i]); 

  printf("\nArray entered is: \n");
  for(i=0; i<size; i++) printf("%d ", input[i]); 

  //call sort function
  quicksort_1(input, 0, size-1); 

  printf("\nSorted array is: \n");
  for(i=0; i<size; i++) printf("%d ", input[i]);
  
  return 0;
}