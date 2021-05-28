#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *nxt;
};
struct node *head = NULL;


void display(struct node *head)
{
	struct node *current;
	current=head;
	while(current->nxt!=NULL)
	{
		printf("%d ",current->data);
		current=current->nxt;
	}
	printf("%d\n",current->data);
}


int create_list(int arr[],int arrlen)
{
	for(int i=0; i<arrlen; i++)
	{

		struct node *temp;
		temp = (struct node *)malloc(sizeof(struct node));
		temp->data = arr[i];
		temp->nxt = NULL;
		if(head == NULL)
		{
			head = temp;
		}

		else
		{	struct node *current;
			current = head;
			while(current->nxt != NULL)
			{
				current = current->nxt;
			}
			current->nxt = temp;
		}
	}
	
}


struct node * insert_in_sortedlist(struct node * head, int key)
{
	struct node *current, *prev, *temp;
	current = head;

	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = key;
	temp->nxt  = NULL;

	if(key<head->data)
	{
		
		temp->nxt = head;
		head = temp;
	}
	else
	{
		while(current && current->data <key)
		{
			prev = current;
			current = current->nxt;
		}
		if(current == NULL)
		{
			prev->nxt = temp;
		}
		else
		{
			temp->nxt = prev->nxt;
			prev->nxt = temp;
		}

	}
	
	return head;	 
}


void main()
{
	struct node *res;
	int arr[] = {10,20,30,40,50,100};
	int result,key = 3500;

	int arrlen = sizeof(arr)/sizeof(arr[0]);
	create_list(arr,arrlen);
	printf("created list\n");
	display(head);
	
	res = insert_in_sortedlist(head,key);
	display(res);
}