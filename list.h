#include <stdlib.h>
#include <stdio.h>

struct node{
	int val;
	struct node *next;
};

int length(struct node *);
struct node* push(struct node *, int);//add to the front of the list
struct node* append(struct node *, int);
void print(struct node *, int);
struct node* sort_ascending(struct node*);
void swap(struct node *, struct node *);
struct node* sort_descending(struct node*);
struct node * clear(struct node *);
struct node * removing(struct node *, int);
struct node* insert_middle(struct node *, int, int);
//struct node* altAppend(struct node*, int);