/* Program to implement selection sort to an array, assuming the order implied is ascending 

Algorithm: enter array -> call sort function -> going in sequential order, if an element is bigger
than another one, their places are swapped -> ouput sorted array

References: Geeks4Geeks, Programiz, Wikipedia
*/

#include <stdio.h>

//function to switch 2 elements
void swap_el(int *x, int *y)
{
    int temp; //temporary element
    
    temp = *x;
    *x = *y;
    *y = temp;
}

//sort function --> n is for size, a is the input array
void selection_sort1(int arr[], int n)
{
    //int i, j;
    for (int i=0; i<n; i++)
    {
      for (int j=i; j<n; j++)
      {
            if (arr[i] > arr[j]) swap_el(&arr[i], &arr[j]);
      }
    }
}

//main function
int main(){

    int input[100], size; //initializing array of size 100

    printf("\n Enter size of array: ");
    scanf("%d", &size);
    printf("\n Enter elements of array: ");

    int i;

    for(i=0; i<size; i++) scanf("%d", &input[i]); 

    printf("\nArray entered is: \n");
    for(i=0; i<size; i++) printf("%d ", input[i]); 

    //call sort function
    selection_sort1(input, size); 

    printf("\nSorted array is: \n");
    for(i=0; i<size; i++) printf("%d ", input[i]);

    return 0;
}
