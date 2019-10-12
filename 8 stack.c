#include <stdio.h>

# define CAPACITY 5 //Pre processor macro to create a CONSTANT

int stack[CAPACITY];
int top = -1;


//Prototype
void push(int);
void pop(void);
int isEmpty(void);
int isFull(void);
void peek(void);
void traverse(void);



void main()
{
	int option, ele;
	while(1)
	{
		printf("\nStack Operations\n");
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. is Empty\n");
		printf("4. is Full\n");
		printf("5. Traverse\n");
		printf("6. Peek\n");
		printf("7. Exit\n");
		
		printf("Enter your option\n");
		scanf("%d",&option);
		
		switch(option)
		{
			case 1: printf("\nEnter the element to push\n");
					scanf("%d",&ele);
					push(ele);
					break;
			case 2: pop();
					break;
			case 3: if(isEmpty())
						printf("No element\n");
					else
						printf("%d elements\n",top+1);
					break;
			case 4: if(isFull())
						printf("Stack Full\n");
					else
						printf("space left\n");
					break;
			case 5: traverse();
					break;
			case 6: peek();
					break;
			case 7: exit(0);
			default: printf("\nEnter valid option\n");
			
		}
	}
}


int isFull()
{
	if(top == CAPACITY-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isEmpty()
{
	if(top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void push(int ele)
{
	if(isFull())
	{
		printf("Stack Full\n");
	}
	else
	{
		top++;
		stack[top] = ele;
		printf("%d pushed on top of the stack\n",ele);	
	}	
}

void pop()
{
	int ele;
	if(isEmpty())
	{
		printf("Stack is Empty\n");
	}
	else
	{
		ele = stack[top];
		--top;
		printf("%d is popped of the stack\n",ele);
	}
}

void peek()
{
	if(isEmpty())
	{
		printf("No elements\n");
	}
	else
	{
		printf("%d\n",stack[top]);
	}
}

void traverse()
{
	if(isEmpty())
	{
		printf("No elements\n");
	}
	else
	{
		int i;
		for(i=top;i>=0;i--)
		{
			printf("%d \n",stack[i]);
		}
	}
}
