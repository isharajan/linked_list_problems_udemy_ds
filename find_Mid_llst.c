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

int count_node(struct node *head)
{
	struct node *current;
	current = head;
	int count = 0;

	while(current!= NULL)
	{	
		count++;
		current = current->nxt;
	}
	return count;
}

struct node * find_mid(struct node *head)
{
	struct node *current =  head;
	int i,mid;
	mid = count_node(head)/2;

	if(count_node(head)%2 != 0)
	{
		for(i=1; i<=mid; i++)
		{
			current = current->nxt;
		}
		return current;
	}
	else
	{
		for(i=1; i<mid; i++)
		{
			current = current->nxt;
		}
		return current;
	}
}
void main()
{
	struct node * head=NULL;
	int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
	int arrlen = sizeof(arr)/sizeof(arr[0]);
	head = create_list(head,arr,arrlen);
	
	display(head);
	head= find_mid(head);
	printf("mid = %d\n",head->data);
	
}