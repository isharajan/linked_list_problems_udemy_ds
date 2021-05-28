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

int is_sorted(struct node * head)
{
	struct node *current;
	current = head;
	 while(current->nxt!= NULL && current->data < current->nxt->data)
	 {
	 	current  =  current->nxt;
	 }
	 if(current->nxt== NULL)
	 {
	 	return 1;
	 }
	 else
	 {
	 	return 0;
	 }
}

void main()
{
	int arr[] = {10,20,80,40,50};
	int result;
	int arrlen = sizeof(arr)/sizeof(arr[0]);
	create_list(arr,arrlen);


	printf("created list\n");
	display(head);
	is_sorted(head);

	if(result ==1)
	{
		printf("\nList is sorted\n");
	}
	else
	{
		printf("\nList is not sorted\n");
	}

}