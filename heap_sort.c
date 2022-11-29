/* 
Building a heap from an array and sorting it
*/ 

#include <stdio.h>
#include <stdlib.h>

void swap_el(int *x, int *y)
{
    int temp; // temporary element
    
    temp = *x;
    *x = *y;
    *y = temp;
}

// function to convert an array to a heap
void array2heap(int *a, int n, int i){
  int parent = i;
  int right = (2*i)+2;
  int left = (2*i)+1;

  //if right child > parent
  if (right<n && a[parent]<a[right]){
    parent = right;
  }
 
  //similarly if left child > parent
  if (left<n && a[parent]<a[left]){
    parent = left;
  }

  if (parent!=i){
    swap_el(&a[i], &a[parent]);

    //heapify it again
    array2heap(a, n, parent);
  }
}

void maxHeap(int *a, int n){
  int last = (n-1)/2;
  int i;

  for(i=last; i>=0; i--){
    array2heap(a, n, i);
  } 
}

void heapSort(int *a, int n){
  // call and build a max heap
  maxHeap(a, n);

  // sort it
  for(int i=n-1; i>=0; i--){
    swap_el(&a[0], &a[i]);
    array2heap(a, i, 0);  
  }
}

int main(void) {

  int a[100], n, i, k;

  printf("\nEnter size of the input array: ");
  scanf("%d", &n);
  
  printf("\nEnter the input array: ");
  for(i=0; i<n; i++) scanf("%d", &a[i]); 

  printf("\nInput array is: ");
  for(i=0; i<n; i++) printf("%d ", a[i]);

  heapSort(a, n);
  printf("\n\nArray sorted using heapsort is: ");
  for(i=0; i<n; i++) printf("%d ", a[i]);
  
  return 0; 
}