#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *prev;
	struct node *nxt;
};

struct node *head;


int list_length(struct node * head)
{	int count = 0;
	struct node *current;
	current = head;
	do
	{	count++;
		current = current->nxt;
	}while(current!=head);
	return count;
}

void display(struct node *head)
{
	struct node *current;
	current = head;
	do
	{
		printf("%d->",current->data);
		current = current->nxt;
	}while(current!=head);
	printf("\n");
}



struct node * insert_last(struct node *head, int value)
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data  = value;
	temp->prev  = NULL;
	temp->nxt   = NULL;

	if(head == NULL)
	{
		head = temp;
		head->nxt = head;
		head->prev = head;
		
	}
	else
	{
		struct node * current;
		current = head;
		
		while(current->nxt != head)
		{
			current = current->nxt;
		}
		temp->nxt    = current->nxt;
		temp->prev   = current;
		current->nxt = temp;
		head->prev   = temp;
	}
	return head;
}

struct node *insert_mid(struct node *head,int pos,int value)
{	
	int total = list_length(head);
	if(pos<0 || pos>total)
	{
		printf("Please enter valid position from [0 - %d]\n",total);
		return head;
	}
	else
	{
		struct node *current;
		struct node *prev;
		struct node *temp;
		temp = (struct node*)malloc(sizeof(struct node));
		temp->data  = value;
		temp->prev  = NULL;
		temp->nxt   = NULL;

		for(int i=0; i<pos-1; i++)
		{
			prev 	= current;
			current = current->nxt;
		}
		temp->nxt 	  = prev->nxt;
		temp->prev 	  = current->prev;
		prev->nxt 	  = temp;
		current->prev = temp;
		return head;
	}
}


struct node *insert_first(struct node * head, int value)
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data  = value;
	temp->prev  = NULL;
	temp->nxt   = NULL;

	if(head == NULL)
	{
		head = temp;
		head->nxt = head;
		head->prev = head;
		
	}
	else
	{
		struct node *current;
		current = head;
		while(current->nxt != head)
		{
			current = current->nxt;
		}
		temp->nxt 	 = head;
		temp->prev   = current;
		head->prev   = temp;
		current->nxt = temp;
		head         = temp;
	}	
	return head;
}

struct node *delete_last(struct node *head)
{
	struct node * current, *prev;
	current = head;
	while(current->nxt != head)
	{
		prev    = current;
		current = current->nxt;
	}
	prev->nxt  = current->nxt;
	head->prev = prev;
	free(current);
	return head;
}

struct node * delete_first(struct node *head)
{
	struct node * current, *del;
	current =head;
	del = head;
	while(current->nxt != head)
	{
		current = current->nxt;
	}
	current->nxt   = del->nxt;
	del->nxt->prev = current;
	head           = head->nxt;
	free(del);
	return head;
}

struct node * delete_mid(struct node *head, int pos)
{
	int total = list_length(head);
	if(pos<0 || pos>total)
	{
		printf("Please enter valid position from [0 - %d]\n",total);
		return head;
	}
	else
	{
		struct node *current, *prev;
		for(int i=0; i<pos-1; i++)
		{
			prev    = current;
			current = current->nxt;
		}
		prev->nxt 		   = current->nxt;
		current->nxt->prev = prev;
		return head;
	}
}

void main()
{
	head = NULL;
	printf("Insert node at last\n");
	head = insert_last(head,10);
	head = insert_last(head,20);
	head = insert_last(head,30);
	head = insert_last(head,40);
	display(head);

	printf("\nInsert node at front\n");
	head = insert_first(head,50);
	head = insert_first(head,60);
	head = insert_first(head,70);
	display(head);

	
	head = insert_mid(head,3,1000);
	head = insert_mid(head,4,2000);
	printf("\nInsert node at mid\n");
	display(head);

	printf("\nDelete node at front\n");
	head = delete_first(head);
	head = delete_first(head);
	display(head);

	printf("\ndelete node at last\n");
	head = delete_last(head);
	display(head);

	head = delete_mid(head,5);
	printf("\ndelete node at mid\n");
	display(head);

}