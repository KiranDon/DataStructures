#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 5
int stack[CAPACITY], top=-1;
int isFull()
{
	if(top==CAPACITY-1)
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
	if(top==-1)
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
		printf("Stack is Full\n");
	}
	else
	{
		top++;
		stack[top]=ele;
	}
}
int pop()
{
	if(isEmpty())
	{
		return 0;
	}
	else
	{
		return stack[top--];
	}
}
void peek()
{
	if(isEmpty())
	{
		printf("Stack is empty\n");
	}
	else
	{
		printf("Element at the top : %d\n",stack[top]);
	}
}
void traverse()
{
	if(isEmpty())
	{
		printf("No elements in the stack\n");
	}
	else
	{
		int i;
		printf("Stack elements are : \n");
		for(i=top;i>=0;i--)
		{
			printf("stack[%d] = %d\n",i,stack[i]);
		}
	}
}
int main()
{
	int ch,ele,del;
	while(1)
	{
	printf("1.Push\n");
	printf("2.Pop\n");
	printf("3.Peek\n");
	printf("4.Traverse\n");
	printf("5.Quit\n");
	printf("Enter your choice : ");
	scanf("%d",&ch);

	switch(ch)
	{
		case 1: printf("Enter a number : ");
				scanf("%d",&ele);
				push(ele);
				break;
		case 2: del=pop();
				if(del==0)
				{
					printf("Stack is empty\n");
				}
				else
				{
					printf("Element deleted : %d\n",del);
				}
				break;
		case 3: peek();
				break;
		case 4: traverse();
				break;
		case 5: exit(0);
				break;
		default: printf("Invalid response\n\n");
	}
}
	return 0;
}

