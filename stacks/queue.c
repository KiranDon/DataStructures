include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue[MAX],front=-1,rear=-1;
void insert(int x)
{
    if(rear==MAX-1)
    {
        printf("Queue is FULL\n");
}
        elseif(front==-1&&rear==-1)
        {
        front=rear=0;
        queue[rear]=x;
}
    else
    {
    rear++;
    queue[rear]=x;
}
