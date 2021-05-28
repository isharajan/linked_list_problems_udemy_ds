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

void Insert_atSorted_list(struct node * head,int key)
{
	struct node *current, *temp, *prev;
	temp= (struct node *)malloc(sizeof(struct node));
	temp->data = key;
	temp->nxt = NULL;

	current = head;
	while(current->data < temp->data);
	{
			printf("%d < %d\n",current->data,temp->data);
			prev= current;
			current = current->nxt;	
	}
	
	
	temp->nxt = current;
	prev->nxt =temp;


}



void main()
{
	int arr[] = {1,45,3,4};
	int arrlen = sizeof(arr)/sizeof(arr[0]);
	int key = 2;
	create_list(arr,arrlen);
	
	display(head);
	Insert_atSorted_list(head,key);
	display(head);


}