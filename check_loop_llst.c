#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *nxt;
};
struct node * head;

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

void displayc(struct node *h)
{	
	struct node *current;
	current = h;
	do
	{
		printf("%d->",current->data);
		current = current->nxt;
	}while(current!= h);
	printf("\n");

}

struct node * create_circular_llst(int arrc[],int arrlenc)
{
	struct node * head, *last;
	head = (struct node *)malloc(sizeof(struct node *));
	head->data = arrc[0];
	head->nxt = head;
	last = head; 

	for(int i=1; i<arrlenc; i++)
	{
		struct node *temp;
		temp = (struct node*)malloc(sizeof(struct node));
		temp->data = arrc[i];
		temp->nxt  = last->nxt;
		last->nxt  = temp;
		last 	   = temp;

	}
	return head;
	
}

struct node * create_list(int arr[],int arrlen)
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

int check_loop(struct node *head)
{
	struct node *s,*f;
	s=head;
	f=head;

	do
	{
		s = s->nxt;
		f = f->nxt->nxt;
	}while(f->nxt!=NULL && s!=f);

	if(f->nxt == NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void main()
{
	int is_loop;
	struct node * result;
	int arr[] = {10,20,80,40,50};
	int arrc[] = {1,2,3,4,5};

	int arrlenc = sizeof(arrc)/sizeof(arrc[0]);
	int arrlen = sizeof(arr)/sizeof(arr[0]);

	/*
	result = create_list(arr,arrlen);
	printf("created list\n");
	display(result);
	*/

	result = create_circular_llst(arrc,arrlenc);
	printf("created create_circular_llst\n");
	displayc(result);
	

	is_loop = check_loop(result);
	//printf("%d---\n",is_loop);
	if(is_loop == 1)
	{
		printf("loop is there\n");
	}
	else
	{
		printf("loop is not there\n");
	}

	
}