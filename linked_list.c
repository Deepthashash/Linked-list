#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
	
};

typedef struct node node;

node* start = NULL;
int n,m;



void insert_front(int n)
{
	if (start ==  NULL)
	{
		node* newnode = (node*) malloc(sizeof(node));
		newnode -> data = n;
		newnode -> next = NULL;
		start = newnode;
	}
	else
	{
		node* newnode = (node*) malloc(sizeof(node));
		newnode -> data = n;
		newnode -> next = start;
		start = newnode;
	}

}

void insert_back(int n)
{
	if(start == NULL)
	{
		printf("This linked list empty so the node is added to the front\n");
		insert_front(n);
	}
	else
	{
		node* newnode = (node*) malloc(sizeof(node));
		newnode -> data = n;
		newnode -> next = NULL;
		node* ptr = start;
		while(ptr -> next != NULL)
		{
			ptr = ptr -> next;
		}
		ptr -> next = newnode;
	}

}

void insert_nextto(int n,int m)
{
	node* newnode = (node*) malloc(sizeof(node));
	newnode -> data = n;
	node* ptr = start;
	while(ptr -> data != m)
	{
		ptr = ptr -> next;
	}
	newnode -> next = ptr -> next;
	ptr -> next = newnode;
}

void insert_previousto(int n, int m)
{
	node* newnode = (node*) malloc(sizeof(node));
	newnode -> data = n;
	node* ptr = start;
	node* preptr = NULL;
	while(ptr -> data != m )
	{
		preptr = ptr;
		ptr = ptr -> next;
	}
	newnode -> next = ptr;
	preptr -> next = newnode; 
}

void delete_front()
{
	if(start == NULL)
	{
		printf("Linked list is empty\n");
	}
	else
	{
		node* temp = start;
		start = start -> next;
		free(temp);
	}
}

void delete_back()
{
		if(start == NULL)
	{
		printf("Linked list is empty\n");
	}
	else
	{
		node* ptr = start;
		node* preptr = NULL;
		while(ptr -> next != NULL)
		{
			preptr = ptr;
			ptr = ptr -> next;
		}	
		preptr -> next = NULL;
		free(ptr);
	}
}

void delete_nextto(int m)
{
	node* ptr = start;
	while(ptr -> next != NULL)
	{
		ptr = ptr -> next;
	}
	node* temp = ptr -> next;
	ptr -> next = temp -> next;
	free(temp);
}

void traverse()
{
	if(start == NULL)
	{
		printf("Linked list is empty\n");

	}
	else
	{
		node* ptr = start;
		while(ptr != NULL)
		{
			printf("%d ",ptr -> data);
			ptr = ptr -> next;
		}
		printf("\n");
	}
}

int main()
{
	int option;


	do{
		printf("Enter ur option\n");
		printf("Press '1' for insert front\n");
		printf("Press '2' for insert back\n");
		printf("Press '3' for insert nextto\n");
		printf("Press '4' for insert previousto\n");
		printf("Press '5' for delete front\n");
		printf("Press '6' for delete back \n");
		printf("Press '7' for delete nextto\n");
		printf("Press '8' to traverse\n");
		printf("Press '9' to quit\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				printf("Enter the num\n");
				scanf("%d",&n);
				insert_front(n);
				break;
			case 2:
				printf("Enter the num\n");
				scanf("%d",&n);
				insert_back(n);
				break;
			case 3:
				printf("Enter the num\n");
				scanf("%d",&n);
				printf("Enter the position\n");
				scanf("%d",&m);	
				insert_nextto(n,m);
				break;
			case 4:
				printf("Enter the num\n");
				scanf("%d",&n);
				printf("Enter the position\n");
				scanf("%d",&m);	
				insert_previousto(n,m);
				break;
			case 5:
				delete_front();
				break;
			case 6:
				delete_back();
				break;
			case 7:
				printf("Enter the position\n");
				scanf("%d",&m);
				delete_nextto(m);
				break;
			case 8:
				traverse();
				break;
		}
	}while(option != 9);

	return 0; 
}



