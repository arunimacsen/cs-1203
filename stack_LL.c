/* Program to implement a stack using a linked list */
 
#include<stdio.h>
#include<stdlib.h>
 
// defining node for stack
struct node{
int data; // for inputs from user
struct node *next; 
};
 
struct node *head;
 
void push(){
 int n;
 struct node *sp; // stack pointer
 sp = (struct node*)malloc(sizeof(struct node)); // allocating memory
 
 if(sp == NULL) printf("\nError\n"); // erroneous
 
 else{
   printf("\nEnter number to push: ");
   scanf("%d", &n);
 
   // stack empty = n becomes head
   if(head == NULL){
     sp->data = n;
     sp->next = NULL; 
     head = sp;
   }
   // stack not empty
   else{
     sp->data = n;
     sp->next = head; // lifo order
     head = sp;
   }
 }
 printf("\nSuccess\n"); 
}
 
void pop(){
 int n;
 struct node *sp; // stack pointer
 sp = (struct node*)malloc(sizeof(struct node)); // memory alloc
 
 if(sp == NULL) printf("\nStack empty. Nothing to pop\n"); 
 
 else{
   head->data = n; // top most data in stack is assigned to a temp variable
   sp = head;
   head = head->next; // head points to the next item in stck
   free(sp); // restore memory
   printf("\nSuccess\n");
 }
}
 
void display(){
 struct node *sp = head;
 
 if(sp == NULL) printf("\nEmpty\n");
 
 else{
   while(sp!=NULL){
     printf("%d | ", sp->data);
     sp = sp->next; 
   }
 }
}
 
int main(void) {
 
 int c = 1;
 
 while(c!=0){
   printf("\nEnter 1 to push ");
   printf("\nEnter 2 to pop ");
   printf("\nEnter 3 to display ");
   printf("\nEnter 0 to exit \n ");
   printf("\n");
 
   scanf("%d", &c);
 
   switch(c){
   case 1: {
     push();
     break;
   }
   case 2: {
     pop();
     break;
   }
   case 3: {
     display();
     break;
   }
 }
 }
  return 0;
}
