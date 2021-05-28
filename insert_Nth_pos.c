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

void insert(struct node * head,int pos,int key)
{
	struct node * temp;
	struct node *current = head;
	struct node *prev;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = key;
	temp->nxt = NULL;
	for(int i=0; i<pos-1; i++)
	{
		prev = current;
		current = current->nxt;
	}
	prev->nxt = temp;
	temp->nxt = current;

}

void main()
{
	int arr[] = {10,20,30,40,50,60,60,48,2,9,-34};
	int arrlen = sizeof(arr)/sizeof(arr[0]);
	int key = 70;
	int pos = 7;
	create_list(arr,arrlen);
	printf("Before Insert\n");
	display(head);
	printf("\nafter Insert %d at position = %d\n",key,pos);
	insert(head,pos,key);
	display(head);


}