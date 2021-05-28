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

int count_nodes(struct node * head)
{
	struct node *current;
	current = head;
	int count = 0;

	while(current!=NULL)
	{
		count = count +1;
		current = current->nxt;
	}
	return count;
}

void main()
{
	int arr[] = {10,20,30,40,50,60,60,48,2,9,-34};
	int arrlen = sizeof(arr)/sizeof(arr[0]);
	create_list(arr,arrlen);
	int total_nodes = count_nodes(head);
	display(head);
	printf("NO.of. Nodes :%d\n",total_nodes);


}