#include <stdio.h>
#define MAX 5
int queue[MAX], front = -1, rear = -1;
void enqueue(int ele)
{
	if((front==0 && rear==MAX-1) || (front = rear+1))
	{
		printf("QUEUE is full...");
	}
	else if(front == -1 && rear == -1)
	{
		front = rear = 0;
		queue[rear] = ele;
	}
	else if(rear = MAX-1 && front!=0)
	{
		rear = 0;
		queue[rear] = ele;
	}
	else
	{
		rear++;
		queue[rear] = ele;
	}
}
void delete()
{
	int ele;
}
int main()
{
	int ele;
	while(1)
	{
		scanf("%d", &ele);
		enqueue(ele);
	}
}
