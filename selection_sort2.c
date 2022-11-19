/* implementing selection sort on a linked list */

#include <stdio.h>
#include <stdlib.h>

//define struct
struct node
{
    struct node *next; //points to the next node
    int data;          //specificied type
};

struct node *head = NULL;
struct node *mod_list; //for modified LL

//insert function
void insert2LL(int val)
{
    struct node *new_val = malloc(sizeof(struct node));
    new_val->data = val; //each time a new node is created, the value entered by user is copied onto the data part
    new_val->next = NULL;

    if (head == NULL) //for when the list is empty
    {
        head = new_val;
    }
    else
    {
        struct node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = new_val;
    }
}

void swap_el(struct node *x, struct node *y)
{
    int temp; //temporary element

    temp = x->data;
    x->data = y->data;
    y->data = temp;
}

void selection_sort2(struct node *LL, int n)
{
    struct node *curr;
    curr = head;
    struct node *temp = head;

    while (curr != NULL)
    {
        temp = curr->next;

        while (temp != NULL)
        {
            if (curr->data > temp->data)
            {
                swap_el(curr, temp);
            }
            temp = temp->next;
        }
        curr = curr->next;
    }
}

void print_LL(struct node* head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }

    printf("NULL"); 
}

int main()
{

    int size, i, new_data;

    printf("\nEnter size of linked list: ");
    scanf("%d", &size);

    printf("\nEnter elements of linked list: ");

    for (i = 0; i < size; i++)
    {
        printf("\nEnter node: ");
        scanf("%d", &new_data);
        insert2LL(new_data);
    }

    printf("\nLinked list entered is: ");
    print_LL(head);

    //call sort function
    selection_sort2(head, size);

    //print sorted linked list
    printf("\nSorted linked list is: ");
    print_LL(head);

    return 0;
}