#include <stdio.h>
#include <stdlib.h> //to get malloc()

//Prototypes of functions
void append(void); 
void addAtBegin(void); 
void addAtAfter(void); 
int length(void); 
void display(void); 
void deleteNode(void); 


//Structure definition
struct node
{
	int data;
	struct node* link;	//one node is holding the address of the other node.
};

//root node to hold address of the first node;
struct node* root = NULL;
int len = 0;

void main()
{
	int option;
	while(1)
	{
		printf("\nSingle Linked List Operation\n");
		printf("1.Append\n");
		printf("2.Add at begin\n");
		printf("3.Add at after\n");
		printf("4.Length\n");
		printf("5.Display\n");
		printf("6.Delete\n");
		printf("7.Exit program\n");
		
		printf("\nEnter your option: ");
		scanf("%d",&option);
		
		switch(option)
		{
			case 1: append(); 
					break;
			case 2: addAtBegin(); 
					break;
			case 3: addAtAfter(); 
					break;
			case 4: len = length(); 
					printf("\nlenght : %d\n",len);
					break;		
			case 5: display(); 
					break;		
			case 6: deleteNode(); 
					break;
			case 7: exit(1); //exit()
			default: printf("\nEnter valid option\n");
		}
	}
}


//append a node to the root node or existing node.
void append()
{
	struct node* temp;	//temporary pointer 
	temp = (struct node*)malloc(sizeof(struct node)); //allocate memory for a node and assign its location to temp
	
	printf("\nenter node data: ");
	scanf("%d",&temp->data);
	
	temp->link = NULL;
	
	if(root == NULL)
	{
		root = temp;
	}
	else
	{
		//another pointer to iterate over existing node from root.
		struct node* p = root;	
		while (p->link != NULL)
		{
			p = p->link;
		}
		//NULL value of the existing node pointing to newly created node.
		p->link = temp;
	}
}


//To find the length of the linked list by iterating over nodes.
int length()
{
	int count = 0;
	//temporary node to iterate over each node.
	struct node* temp;
	temp = root;
	while(temp != NULL)
	{
		temp = temp->link;
		count++;
	}
	return count;
}


//Display Linked List
void display()
{
	struct node* temp = root;
	if(temp == NULL)
	{
		printf("\n\nNo Elements in the list\n\n");
	}
	else
	{
		while(temp->link != NULL)
		{
			printf("%d-->", temp->data);
			temp = temp->link;
		}
		printf("%d\n\n",temp->data);
	}
}


//Add a node at the beginning of linked list.
void addAtBegin()
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("\nenter the data: ");
	scanf("%d",&temp->data);
	
	//root --> temp_node --> 1st element
	temp->link = root;
	root=temp;
}


//Add a node after a particular location in a linked list.
void addAtAfter()
{
	int loc;
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("\nenter the data: ");
	scanf("%d",&temp->data);
	printf("\nEnter location: ");
	scanf("%d",&loc);
	if(loc>length())
	{
		printf("\nLocation not available\n");
	}
	else
	{
		struct node* p = root;
		int count=1;
		while(count<loc)
		{
			p=p->link;
			count++;
		}
		temp->link = p->link;
		p->link=temp;
	}
}


//Delete a node after a particular location
void deleteNode()
{
	int loc;
	printf("\nenter the location to delete: ");
	scanf("%d",&loc);
	if(loc>length())
	{
		printf("invalid location\n");
	}
	//If location = 1
	else if(loc == 1)
	{
		struct node* p = root;
		root = p->link;
		p->link = NULL;
		free(p);
	}
	else
	{
		struct node* q = root, *t;
		int count = 1;
		while(count<loc-1)
		{
			q = q->link;
			count++;
		}
		t = q->link;
		q->link = t->link;
		t->link = NULL;
		free(t);
	}
}
