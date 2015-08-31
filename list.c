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
