#include <stdio.h>

#define CAPACITY 5	//CONSTANTS

//Global variables
int queue[CAPACITY];
int front = 0;
int rear = 0;

//Functional prototype
void insert();
void delete();
void display();

void main()
{
	int option;
	while(1)
	{
		printf("\n\nQueue Operations\n");
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Traverse\n");
		printf("4. Exit\n");
		
		printf("Enter the option\n");
		scanf("%d",&option);
		
		switch(option)
		{
			case 1: insert();
					break;
			case 2: delete();
					break;
			case 3: display();
					break;
			case 4: exit(1);
			default: printf("Invalid option\n");
		}
	}
}

void insert()
{
	if(rear==CAPACITY)
	{
		printf("Queue is full\n");
	}
	else
	{
		printf("Enter the data\n");
		scanf("%d",&queue[rear]);
		rear++;
	}
}

void delete()
{
	if(rear==front)
	{
		printf("Queue is empty\n");
	}
	else
	{
		int i;
		for(i=1;i<rear;i++)
		{
			queue[i-1] = queue[i]; 
		}
		rear--;
	}
}

void display()
{
	if(rear==front)
	{
		printf("queue is empty\n");
	}
	else
	{
		int i;
		for(i=front;i<rear;i++)
		{
			printf("%d | ", queue[i]);
		}
	}
}
