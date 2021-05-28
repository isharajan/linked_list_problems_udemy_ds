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

struct node * intersecting_lists(struct node *head1,struct node *head2,int intersect_pos)
{
	struct node *current1, *current2, *intersect;
	current1 = head1;
	current2 = head2;
	for(int i=0; i<intersect_pos-1; i++)
	{
		current1 = current1->nxt;
	}
    intersect = current1;
    while(current2->nxt != NULL)
    {
    	current2 = current2->nxt;
    }
    current2->nxt = intersect;
 	return head1;
}

struct node * find_intersect_pos(struct node *head1, struct node *head2)
{
	struct node *c1,*c2;
	c1 = head1;
	c2 = head2;
	while(c1 != c2)
	{
		if(c1 == NULL)
		{
			c1 = head2;
		}
		else if(c2 == NULL)
		{
			c2 = head1;
		}
		else
		{
			c1 = c1->nxt;
			c2 = c2->nxt;
		}
	}
	return c1;

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

void main()
{
	struct node * head1=NULL;
	struct node * head2=NULL;
	struct node * head3;
	struct node * intersect_node;

	int intersect_pos = 4;
	int arr1[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
	int arr2[] = {100,200,300,400};
	
	int arrlen1 = sizeof(arr1)/sizeof(arr1[0]);
	int arrlen2 = sizeof(arr2)/sizeof(arr2[0]);
	
	head1 = create_list(head,arr1,arrlen1);
	head2 = create_list(head,arr2,arrlen2);
	
	//display(head1);
	//display(head2);
	head3 = intersecting_lists(head1,head2,intersect_pos);
	
	display(head1);
	display(head2);
	intersect_node = find_intersect_pos(head1,head2);
	printf("intersect node = %d\n",intersect_node->data);



}