#include<stdio.h>
#include<stdlib.h>


struct node
{
	int coeff_data;
	int exp_data;
	struct node *nxt;
};
struct node *head;


void display(struct node *head)
{
	struct node * current;
	current = head;
	while(current->nxt!=NULL)
	{
		printf("%dX%d + ",current->coeff_data,current->exp_data);
		current=current->nxt;
	}
	printf("%dX%d",current->coeff_data,current->exp_data);
}



int power(int x,int exp)
{
	int res =1;
	for(int i=0; i<exp; i++)
	{
		res = res * x;
	}
	return res;
}



int poly_eval(int x,struct node *head)
{
	int sum =0;
	struct node *current = head;
	while(current!=NULL)
	{
		sum 	= sum + (current->coeff_data * power(x,current->exp_data));
		current = current ->nxt;
	}
	return sum;

}



struct node * create_poly(struct node * head)
{	
	int n;
	struct node *last;
	last    = head;
	printf("enter no.of. terms : ");
	scanf("%d",&n);
	
	for(int i=0; i<n; i++)
	{
		struct node *temp = (struct node *)malloc(sizeof(struct node));
		printf("enter coeff_data and exp_data :\n");
		scanf("%d %d",&temp->coeff_data, &temp->exp_data);

		if(head == NULL)
		{
			head = temp;
			last = temp;
		}
		else
		{
			last->nxt = temp;
			last 	  = temp;
		}

	}
	return head;
	
}



void main()
{
	int result, x;
	struct node * head=NULL;
	
	head = create_poly(head); 
	printf("\nPolynomial equation : ");
	display(head);

	printf("\nenter x : ");
	scanf("%d",&x);

	result = poly_eval(x,head);
	printf("\n");
	
	display(head);
	printf(" = %d\n",result);
	
	
}