/* Program to implement insertion sort to a linked list, assuming the order implied is ascending 

+ assuming the linked list is a singly linked list so the last node points to NULL

Algorithm: create + input singly linked list (LL) -> traverse through the LL in sequential order while comparing nodes, if a node is bigger than another one, their places are swapped and pointers updated -> output sorted LL/head of it

References: TutorialsPoint, Programiz, Geeks4Geeks, Wikipedia
*/

#include <stdio.h>
#include <stdlib.h>


//define struct
struct node{
  struct node *next; //points to the next node
  int data; //specificied type
};

struct node *head = NULL;
struct node *mod_list = NULL; //for output LL

//function to insert nodes to an LL
void insert2LL(int n){
  //dynamic allocation
  struct node* new_data = (struct node*)malloc(sizeof(struct node));
  
  new_data->data = n;
  new_data->next = NULL;
  
  if(head == NULL){
    head = new_data;
  }
  else{
    struct node *temp = head;
    
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_data;
  }
   
}

void sortLL(struct node *new_el){
  if(new_el->data <= mod_list->data || mod_list == NULL){
    new_el->next = mod_list;
    mod_list = new_el;
  }

  else{
    struct node* curr = mod_list;

    while(new_el->data > curr->next->data && curr->next != NULL){
      curr = curr->next;
    }

    new_el->next = curr->next;
    curr->next = new_el;            
  }
}

//sort function 
void insertion_sort2()
{
  struct node* curr = head;
  
  while (curr != NULL){
    struct node* next = curr->next;
    sortLL(curr);
    curr = next; 
  }

  head = mod_list; 
}

//function to print LL
void print_LL(struct node* head){
  while (head != NULL){
    printf("%d -> ", head->data);
    head = head->next; 
  }
  printf("NULL"); 
}


//main function
int main(){ 
  int size, i, new_data; 

  printf("\nEnter size of linked list: ");
  scanf("%d", &size);

  //head == NULL; 

  printf("\nEnter elements of linked list: ");

  for(i=0; i<size; i++){
    printf("\nEnter node: ");
    scanf("%d", &new_data);
    insert2LL(new_data); 
  } 

  printf("\nLinked list entered is: ");
  print_LL(head);
  
  //call sort function
  insertion_sort2(); 

  //print sorted linked list
  printf("\nSorted linked list is: ");
  print_LL(head);

  return 0;
}
