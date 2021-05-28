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

struct node * return_max(struct node *head)
{
	struct node *current = head;
	struct node *max;
	max = current;
	while(current!= NULL)
	{
		if(max->data < current->data)
		{
			max = current;
			
		}
		current = current->nxt;
	}

	return max;
}

void main()
{
	int arr[] = {10,20,30,40,50,60,60,48,2,9,-34,100};
	int arrlen = sizeof(arr)/sizeof(arr[0]);
	
	create_list(arr,arrlen);
	display(head);

	struct node *temp = return_max(head);
	printf("max = %d\n",temp->data);


}