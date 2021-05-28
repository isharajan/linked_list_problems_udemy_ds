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

struct node *search(struct node *head,int key)
{
	struct node * current;
	current = head;
	while(current!=NULL)
	{
		if(key == current->data)
		{
			return current;
		}
		current = current->nxt;
	}
	return NULL;
}

void main()
{
	int arr[] = {10,-2,20,30,-2};
	struct node * temp;
	int key = 30;
	int i;
	int arrlen = sizeof(arr)/sizeof(arr[0]);
	create_list(arr,arrlen);
	display(head);
	temp = search(head,30);

	printf("key = %d\n",key);

	if(key==temp->data)
	{
		printf("element %d found \n",key);
	}
	else
	{
		printf("Key element %d not found\n",key);
	}


}