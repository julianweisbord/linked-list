#include <stdlib.h>
#include <stdio.h>
#include "list.h"
/*********************************************************************
 ** Name: Length
 ** Description: finds length of list
 ** Input: none
 ** Output: length
 *********************************************************************/
int length(struct node*head){
	int count = 0;
	if(head){
		struct node*current = head;


		while(current!=NULL){
			count++;
			current = current->next;
		}
	}
	return count;

}
/*********************************************************************
 ** Name: push
 ** Description: adds node to front
 ** Input: none
 ** Output: node
 *********************************************************************/
struct node* push(struct node*head, int data){
		struct node* newNode = malloc(sizeof(struct node));
		newNode->val =data;
		newNode->next = head;
		head = newNode;
		return head;
}
/*********************************************************************
 ** Name: append
 ** Description: adds node to back
 ** Input: none
 ** Output: node
 *********************************************************************/
struct node* append(struct node*head,int data){
		struct node* current = head;
		struct node*newNode = malloc(sizeof(struct node));
		newNode->val = data;
		newNode->next = NULL;
		//special case for length 0
		if(current == NULL){
			head =newNode;
		}
		else{
			while(current->next!=NULL){
				current = current->next;
			}
			current->next = newNode;
		}

		return head;

}

/*********************************************************************
 ** Name: print
 ** Description: prints list
 ** Input: values
 ** Output: list
 *********************************************************************/
void print(struct node*head, int data){
	if(head){
		struct node*current;
		int count = 0;
		current=head;
		while(current!=NULL){
			++count;
			printf("The value of the node at position %d is %d\n",count,current->val);
			current=current->next;
		}
		// current = NULL;
		if(current == NULL){
			printf("End of list\n");
		}
	}
	else{
		printf("No list items...\n");
	}

}
/*********************************************************************
 ** Name: swap
 ** Description: switches nodes around
 ** Input: nodes
 ** Output: none
 *********************************************************************/
void swap(struct node *a, struct node *b)
{
    int temp = a->val;
    a->val = b->val;
    b->val = temp;
}
/*********************************************************************
 ** Name: sort_ascending
 ** Description: sorts list from smallest to largest
 ** Input: node
 ** Output: ordered list
 *********************************************************************/
struct node* sort_ascending(struct node* head){
  if(head){
		int swapped, i;
    struct node *ptr1;
    struct node *lptr = NULL;

    /* Checking for empty list
    if (ptr1 == NULL)
    	printf("is null");
        return;
    */

    do
    {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr)
        {
            if (ptr1->val > ptr1->next->val)
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;

    }
    while (swapped);
	}
  return head;

}
/*********************************************************************
 ** Name: sort_descending
 ** Description: sorts nodes from largest to smallest
 ** Input: node
 ** Output: ordered list
 *********************************************************************/
struct node* sort_descending(struct node *head){
	if(head){
  	int swapped, i;
    struct node *ptr1;
    struct node *lptr = NULL;

    /* Checking for empty list
    if (ptr1 == NULL)
        return;
    */

    do
    {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr)
        {
            if (ptr1->val < ptr1->next->val)
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
	}
  return head;
}

/*********************************************************************
 ** Name: insert_middle
 ** Description: adds node to a location
 ** Input: node and value
 ** Output: node to a location
 *********************************************************************/
struct node* insert_middle(struct node*head, int data, int size){
	if (head){
		struct node*current=head;
		struct node*newNode = malloc(sizeof(struct node));

		newNode->val = data;

		int counter= 0;
		for(current; current!=NULL; current=current->next){
			counter++;
			if(counter==(size)){
				break;
			}
		}
		newNode->next =current->next;
		current->next = newNode;
		printf("new node value: %d \n", newNode->val);
	}
	//current->next = newNode;
	//newNode = current;
	return head;
}
/*********************************************************************
 ** Name: clear
 ** Description: deletes the list
 ** Input: none
 ** Output: none
 *********************************************************************/
struct node* clear(struct node*head){
	//struct node*current= malloc(sizeof(struct node));
	//current = head->next;
	if(head){
		struct node* current = head;
	  	 struct node* next;

	   while (current != NULL)
	   {
	       next = current->next;
	       free(current);
	       current = next;
	   }
	}

}
/*********************************************************************
 ** Name: removing
 ** Description: deletes a single node
 ** Input: none
 ** Output: none
 *********************************************************************/
struct node * removing(struct node * head, int pos){
	//seg faults when try to remove a node at position one .
	int counter = 0;
	struct node* current = head;
  struct node* previous = NULL;

    while (current != NULL) {
        if (counter == pos-1) {
            if (previous == NULL) {
                current = current->next;
                free(head);
								head = current;
            } else {
                previous->next = current->next;
                free(current);
                current = previous->next;
            }
        } else {
            previous = current;
            current = current->next;
        }
				++counter;
    }


	return head;

}
/*********************************************************************
 ** Name: Main
 ** Date: 6/7/15
 ** Description: runs the program
 ** Input: nodes
 ** Output: linked list
 *********************************************************************/
int main(){
	char ans, ans2, ans3, ans4,ans5, choice;
	int num, position, location;
	struct node*head = NULL;
	struct node*tail = NULL;


	do{
		do {
			printf("Enter a number: \n");
			scanf("%d", &num);

			printf("Do you want to push or append?(p or a):\n");
			scanf("%1s", &ans4);
			if(ans4=='a'){
				//head = altAppend(head, num);
				head = append(head, num);
			}
			else if(ans4=='p'){
				head =push(head, num);
			}
			printf("Would you like to remove a number?(y or n): \n");
			scanf("%1s",&ans5);
			if(ans5=='y'){
				printf("what is the position of the number that should be deleted(must be 1 or greater)?:\n");
				scanf("%d",&location);
				head = removing(head, location);
			}

			do{
				printf("do you want to enter something into the middle of the list?(y or n): \n");
				scanf("%1s", &choice);

				if(choice=='y'){
					printf("What posotion do you want to enter a number to?(cant be 0 or 1) :\n");
					scanf("%d", &position);
					if (position == 0 || position ==1){
						printf("Must be greater than zero or one!\n");
						break;
					}
					printf("what is this numbers value? \n");
					scanf("%d",&num);
					head = insert_middle(head, num, position);
				}
				else{
					break;
				}
			}while(choice =='y');

			printf("Do you want to add another num (y or n) ?: \n");
			scanf("%1s",&ans);

		}while(ans=='y');

		printf("Sort ascending, descending, or unsorted (a or d or u)? \n");
        scanf("%1s",&ans2);

       // printf("answer is: %1c\n", ans2);

        if(ans2 == 'a'){
        	//printf("in if\n");
        	//head=sort_ascending(head);
        	head = sort_ascending(head);
        }
        else if(ans2 == 'd'){
        	head = sort_descending(head);

        }
        else if(ans2 =='u'){
        	printf("we will not sort this list...\n");
        }

        print(head, length(head));

        printf("Do you want to do this again?(y or n): \n");
        scanf("%1s",&ans3);
        if(ans3 == 'y'){
        	head = clear(head);
        	printf("Lets print the cleared list...\n");
        	print(head, length(head));
        	printf("we will do this again...\n");
        }

	}while(ans3=='y');

	return 0;

}

//		Linked List Menu Driven Program Using C
/*
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void create(struct node **);
void display(struct node *);
void insert(struct node **);
void delete (struct node **);

int main()
{
    struct node *head = NULL;
    int option;

    printf("\nPlease select your desired option from below : \n");
    printf("1.  Create a Linked List.\n");
    printf("2.  Display the Linked List.\n");
    printf("3.  Inserting a node to Linked List.\n");
    printf("4.  Deleting a node from Linked List.\n");
    printf("5.  EXIT\n");
    scanf("%d", &option);

    while (option != 5)
    {
        switch (option)
        {
        case 1:
            create(&head);
            display(head);
            break;
        case 2:
            display(head);
            break;
        case 3:
            insert(&head);
            display(head);
            break;
        case 4:
            delete (&head);
            display(head);
            break;
        default:
            printf("Please enter a number between 1 and 5 according to your choice : ");
            break;
        }
        printf("\nPlease select your desired option from below : \n");
        printf("1.  Create a Linked List.\n");
        printf("2.  Display the Linked List.\n");
        printf("3.  Inserting a node to Linked List.\n");
        printf("4.  Deleting a node from Linked List.\n");
        printf("5.  EXIT\n");
        scanf("%d", &option);
    }
    return 0;
}

void create(struct node **h)
{
    struct node *curr, *ptr;
    int n, i;
    printf("Enter the number of nodes you want : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        curr = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data of Node %d : ", i + 1);
        scanf("%d", &curr->data);
        curr->next = NULL;

        if (*h == NULL)
        {
            *h = curr;
            ptr = curr;
        }
        else
        {
            ptr->next = curr;
            ptr = curr;
        }
    }
}

void display(struct node *h)
{
    struct node *curr;
    for (curr = h; curr != NULL; curr = curr->next)
    {
        printf("%d\t", curr->data);
    }
}

void insert(struct node **h)
{
    int v, p;
    struct node *curr, *ptr;
    printf("Enter the value you want to add : ");
    scanf("%d", &v);
    printf("Enter the position at which you want to enter the value : ");
    scanf("%d", &p);

    curr = (struct node *)malloc(sizeof(struct node));
    curr->data = v;
    curr->next = NULL;

    if (*h == NULL)
    {
        (*h) = curr;
    }
    else if (p == 0)
    {
        curr->next = *h;
        *h = curr;
    }
    else
    {
        ptr = *h;
        int i = 1;
        while (i < p && ptr->next != NULL)
        {
            ptr = ptr->next;
            i++;
        }
        curr->next = ptr->next;
        ptr->next = curr;
    }
}

void delete (struct node **h)
{
    struct node *ptr;
    int p;
    printf("Enter the position at which you want to delete : ");
    scanf("%d", &p);

    if (*h == NULL)
    {
        printf("Linked List is Empty.");
    }
    else if (p == 1)
    {
        ptr = *h;
        *h = ptr->next;
        free(ptr);
    }
    else
    {
        ptr = *h;
        struct node *prv;
        int i = 1;
        while (i < p && ptr != NULL)
        {
            i++;
            prv = ptr;
            ptr = ptr->next;
        }
        if (ptr == NULL)
        {
            printf("Not found.");
        }
        else
        {
            prv->next = ptr->next;
            free(ptr);
        }
    }
}
*/
