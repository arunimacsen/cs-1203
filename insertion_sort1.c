/* Program to implement insertion sort to an array, assuming the order implied is ascending 

Algorithm: enter array -> call sort function -> going in sequential order, if an element is bigger
than another one, their places are swapped -> ouput sorted array

References: Programiz, Wikipedia
*/

#include <stdio.h>


//sort function --> n is for size, a is the input array
void insertion_sort1(int arr[], int n)
{
  int temp; 
    for (int i=1; i<n; i++)
    { 
      for (int j=i; j>0 && arr[j]<arr[j-1]; j--)
      {
          temp = arr[j];
          arr[j] = arr[j - 1];
          arr[j - 1] = temp;
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
    insertion_sort1(input, size); 

    //print sorted array
    printf("\nSorted array is: \n");
    for(i=0; i<size; i++) printf("%d ", input[i]);

    return 0;
}
