#include<stdio.h>
#include<stdlib.h>


struct node
{
	int data;
	struct node *nxt;
};
struct node *head;

void display(struct node *head)
{
	struct node * current;
	current = head;
	while(current->nxt!=NULL)
	{
		printf("%d->",current->data);
		current=current->nxt;
	}
	printf("%d\n",current->data);
}

struct node * reverse(struct node * head)
{
	struct node * prev 	  = NULL;
	struct node * current = head;
	struct node * next	  = current->nxt;
	while(current->nxt != NULL)
	{
		current->nxt = prev;
		prev 		 = current;
		current      = next;
		next 		 = next->nxt;
	}
	current->nxt = prev;
	head 		 = current;
	return head;
}

struct node * create_list(struct node * head,int arr[],int arrlen)
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
	return head;
	
}

void main()
{
	struct node * head=NULL;
	int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
	int arrlen = sizeof(arr)/sizeof(arr[0]);
	head = create_list(head,arr,arrlen);
	display(head);

	head = reverse(head);
	printf("\nReversed list\n");
	display(head);
}