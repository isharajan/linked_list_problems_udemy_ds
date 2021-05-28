#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *nxt;
};
struct node *head1= NULL;
struct node *head2= NULL;


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



struct node * create_list1(int arr1[],int arrlen1)
{
	for(int i=0; i<arrlen1; i++)
	{

		struct node *temp;
		temp = (struct node *)malloc(sizeof(struct node));
		temp->data = arr1[i];
		temp->nxt = NULL;
		if(head1 == NULL)
		{
			head1 = temp;
		}

		else
		{	struct node *current;
			current = head1;
			while(current->nxt != NULL)
			{
				current = current->nxt;
			}
			current->nxt = temp;
		}
	}
	return head1;

	
}
struct node * create_list2(int arr2[],int arrlen2)
{
	for(int i=0; i<arrlen2; i++)
	{

		struct node *temp;
		temp = (struct node *)malloc(sizeof(struct node));
		temp->data = arr2[i];
		temp->nxt = NULL;
		if(head2 == NULL)
		{
			head2 = temp;
		}

		else
		{	struct node *current;
			current = head2;
			while(current->nxt != NULL)
			{
				current = current->nxt;
			}
			current->nxt = temp;
		}
	}

	return head2;
}

struct node * cancat(struct node *head1, struct node * head2)
{
	struct node* current;
	current = head1;
	while(current->nxt != NULL)
	{
		current = current->nxt;
	}
	current->nxt = head2;
}

void main()
{
	struct node *res;
	int arr1[]  = {1,2,3,4,5,6,7,8,9,10};
	int arr2[] = {11,34,22,44,55,66,77,88,99};

	int arrlen1 = sizeof(arr1)/sizeof(arr1[0]);
	int arrlen2 = sizeof(arr2)/sizeof(arr2[0]);

	create_list1(arr1,arrlen1);
	printf("created list1\n");
	display(head1);
	create_list2(arr2,arrlen2);
	display(head2);

	printf("\n");
	cancat(head1,head2);
	printf("after canacat \n");
	display(head1);
	
	

	
	
}