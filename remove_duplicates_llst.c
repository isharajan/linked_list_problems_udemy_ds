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

struct node * remove_duplicates(struct node * head)
{
	struct node *p, *q;
	p = head;
	q = p->nxt;

	while(q!=NULL)
	{
		if(p->data != q->data)
		{
			p = q;
			q = q->nxt;
		}
		else
		{
			p->nxt = q->nxt;
			free(q);
			q = p->nxt;
		}
	}
	return head;
}


void main()
{
	struct node *res;
	int arr[] = {1,1,2,3,4,4,4,5,5,6,7,8,9,10,10};

	int arrlen = sizeof(arr)/sizeof(arr[0]);
	create_list(arr,arrlen);
	printf("created list\n");
	display(head);
	
	res = remove_duplicates(head);
	printf("\nafter removing duplicates\n");
	display(res);

}