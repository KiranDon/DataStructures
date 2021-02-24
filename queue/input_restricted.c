#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 5
int queue[SIZE];
int front=-1,rear=-1;
void insert(int);
void deletion();
void traverse();
void main()
{
	int op,ele;
	while(1)
	{
	
	printf("menu\n");
	printf("1.input restricted\n");
	printf("2.delte\n");
	printf("3.display\n");
	printf("4.exit\n");
	printf("enter option\n");
	scanf("%d",&op);
	switch(op)
	{
		case 1:
				printf("enter element\n");
				scanf("%d",&ele);
				insert(ele);
				break;
		case 2:
				deletion();
				break;
		case 3:
				traverse();
				break;
		case 4:
				exit(0);
				break;
	}
	}
	
}
void insert(int ele)
{
	if(front==rear+1||(rear==SIZE-1&&front==0))
	{
		printf("queue is full\n");
	}
	else if(front==-1&& rear==-1)
	{
		front=0;
		rear=0;
		queue[rear]=ele;
	}
	else if(rear==SIZE-1&&front!=0)
	{
		rear=0;
		queue[rear]=ele;
		
	}
	else
	{
		rear++;
		queue[rear]=ele;
	}
}
void deletion()
{
	if(front==-1&&rear==-1)
	{
		printf("queue is empty\n");
	}
	else if(front==rear)
	{
		printf("deleted element:%d\n",queue[rear]);
		front=-1;
		rear=-1;
	}
	else
	{
		int ch;
		printf("1.leftside deletion\n");
		printf("2.rightside deletion\n");
		printf("enter choice\n");
		scanf("%d",&ch);
		if(ch==1)
		{
			printf("deleted elemnt:%d\n",queue[front]);
			front++;
		}
		else if(ch==2)
		{
			printf("deleted element:%d\n",queue[rear]);
			rear--;
		}
	}
}
void traverse()
{
	int i;
	if(front<=rear)
	{
		for(i=front;i<=rear;i++)
		{
			printf("%d\t",queue[i]);
		}
	}
	else
	{
		for(i=front;i<SIZE;i++)
		{
			printf("%d\t",queue[i]);
		}
		for(i=0;i<=rear;i++)
		{
			printf("%d\t",queue[i]);
		}
	}
}


