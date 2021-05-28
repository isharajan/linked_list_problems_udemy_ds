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

//print elements in reverse
void rev_llst1(struct node *current)
{
	if(current== NULL)
	{
		return;
	}
	rev_llst1(current->nxt);
	printf("%d ",current->data);
	
}

// Reverse a linked list
void rev_llst2(struct node *current)
{
	struct node *p,*q,*n;
	p = NULL;
	q = current;
	n = q->nxt;
	while(n!=NULL)
	{
		q->nxt = p;
		p=q;
		q=n;
		n = n->nxt;
	}
	q->nxt = p;
	head = q;
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

void main()
{
	int arr[] = {10,20,30,40,50};
	int arrlen = sizeof(arr)/sizeof(arr[0]);
	create_list(arr,arrlen);

	printf("created list\n");
	display(head);

	printf("\nList printed reverse:\n");
	rev_llst1(head);

	printf("\n\nReversed list\n");
	rev_llst2(head);
	display(head);


}