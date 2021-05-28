#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *nxt;
};
struct node * head;

int count(struct node *head)
{
	struct node *current;
	current = head;
	int count= 0;
	do
	{
		count++;
		current = current->nxt;
	}while(current!= head);

	return count;
}

void display(struct node *h)
{	
	int total;
	struct node *current;
	current = h;
	do
	{
		printf("%d->",current->data);
		current = current->nxt;
	}while(current!= h);
	printf("\n");

	total = count(h);
	printf("No.of.Nodes = %d\n\n",total);
}




struct node * create_circular_llst(int arr[],int arrlen)
{
	struct node * head, *last;
	head = (struct node *)malloc(sizeof(struct node *));
	head->data = arr[0];
	head->nxt = head;
	last = head; 

	for(int i=1; i<arrlen; i++)
	{
		struct node *temp;
		temp = (struct node*)malloc(sizeof(struct node));
		temp->data = arr[i];
		temp->nxt  = last->nxt;
		last->nxt  = temp;
		last 	   = temp;

	}
	return head;
	
}

struct node * delete_first(struct node * head)
{
	struct node *del, *current;
	del  = head;
	current = head;

	while(current->nxt != head)
	{
		current = current->nxt;
	}
	current->nxt = head->nxt;
	head = head->nxt;
	free(del);
	return head;
}

struct node * delete_last(struct node *head)
{
	struct node * prev;
	struct node * current = head;
	while(current->nxt != head)
	{
		prev = current;
		current = current->nxt;
	}
	prev->nxt = current->nxt;
	free(current);
	return head;
}

struct node *insert_first(struct node *head, int value)
{
	struct node * current, *temp;
	current = head;
	while(current->nxt != head)
	{
		current = current->nxt;
	}
	temp 		 = (struct node *)malloc(sizeof(struct node *));
	temp->data   = value;
	temp->nxt 	 = current->nxt;
	head      	 = temp;
	current->nxt = head;
	return head;
}

struct node * insert_last(struct node *head,int value)
{
	struct node * current, *temp;
	current = head;
	while(current->nxt != head)
	{
		current = current->nxt;
	}
	temp 		 = (struct node *)malloc(sizeof(struct node *));
	temp->data   = value;
	temp->nxt    = current->nxt;
	current->nxt = temp;
	return head;
}

struct node * insert_mid(struct node *head, int pos, int value)
{
	if(pos<0 || pos>count(head))
	{
		printf("Please enter valid position from [0 to %d]\n",count(head));
		return head;
	}
	else
	{
		struct node *prev, *current, *temp;
		current = head;
		for(int i=0; i<pos-1; i++)
		{
			prev    = current;
			current = current->nxt;
		}
		temp 		= (struct node *)malloc(sizeof(struct node));
		temp->data 	= value;
		temp->nxt 	= prev->nxt;
		prev->nxt 	= temp;
		return head;
	}
}

struct node * delete_mid(struct node *head, int pos)
{
	if(pos<0 || pos>count(head))
	{
		printf("Please enter valid position from [0 to %d]\n",count(head));
		return head;
	}
	else
	{
		struct node *prev, *current, *temp;
		current = head;
		for(int i=0; i<pos-1; i++)
		{
			prev    = current;
			current = current->nxt;
		}
		temp = current;
		prev->nxt = current->nxt;
		free(temp);
		return head;
	}

}

void main()
{
	int pos = 4;
	int delpos = 7;
	struct node * res;
	int arr[]  = { 10,20,30,40,50,60};
	int arrlen =  sizeof(arr)/sizeof(arr[0]);

	printf("list created\n");
	res = create_circular_llst(arr,arrlen);
	display(res);
	

	printf("Insert node at last position\n");
	res = insert_last(res,100);
	res = insert_last(res,200);
	display(res);

	printf("delete node from last position\n");
	res = delete_last(res);
	res = delete_last(res);
	display(res);

	printf("Insert node at first Position\n");
	res = insert_first(res,5);
	res = insert_first(res,7);
	display(res);

	printf("delete node from first position\n");
	res = delete_first(res);
	res = delete_first(res);
	display(res);

	printf("Insert node at position = %d\n",pos);
	res = insert_mid(res,pos,1000);
	display(res);

	printf("delete node at position = %d\n",delpos);
	res = delete_mid(res,delpos);
	display(res);
}