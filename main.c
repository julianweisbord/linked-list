#include "list.h"
#include <stdio.h>
#include <stdlib.h>

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
				printf("what is the position of the number that should be deleted?:\n");
				scanf("%d",&location);
				head = removing(head, location);
			}	

			do{
				printf("do you want to enter something into the middle of the list?(y or n): \n");
				scanf("%1s", &choice);

				if(choice=='y'){
					printf("What posotion do you want to enter a number to?:\n");
					scanf("%d", &position);
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



