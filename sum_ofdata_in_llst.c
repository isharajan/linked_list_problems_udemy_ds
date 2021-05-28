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

int sum_ofdata(struct node *head)
{
	struct node *current;
	current = head;
	int sum = 0;

	while(current!= NULL)
	{	
		sum = sum + current->data;
		current = current->nxt;
	}
	return sum;
}

void main()
{
	int arr[] = {10,-2,20,30,-2};
	int arrlen = sizeof(arr)/sizeof(arr[0]);
	create_list(arr,arrlen);
	int sum = sum_ofdata(head);
	display(head);
	printf("Sum of all Elements in List : %d\n",sum);


}