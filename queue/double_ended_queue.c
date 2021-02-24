 #include<stdio.h>
#include<stdlib.h>
#define MAX 5
int dequeue[MAX],front,rear;
front=-1,rear=-1;
void insert(int ele)
{
    if(front==0&&rear==MAX-1)
        printf("Double ended Queue is Full\n");
    else if(front==-1&&rear==-1)
    {
        front = rear =0;
        dequeue[rear]=ele;
    }
    else if(front==0)
    {
        rear ++;
        dequeue[rear]=ele;
    }
    else if(rear = MAX-1)
    {
        front--;
        dequeue[front]=ele;
    }
    else
    {
        int ch;
        printf("1.Left side insertion\n");
        printf("2.Right side insertion\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        if(ch==1)
        {
            front--;
            dequeue[front]=ele;
        }
        else if(ch==2)
        {
            rear++;
            dequeue[rear]=ele;
        }
        else
            printf("Entered Wrong choice\n");
    }
}
void delete()
{
    if(front==-1&&rear==-1)
        printf("Double Ended Queue is Empty\n");
    else if(front==rear)
    {
        printf("Element deleted : %d\n",dequeue[front]);
        front=rear=-1;
    }
    else
    {
        int ch;
        printf("1.Left side deletion\n");
        printf("2.Right side deletion\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("Element deleted : %d\n",dequeue[front]);
            front++;
        }
        else if(ch==2)
        {
           printf("Element deleted : %d\n",dequeue[rear]);
           rear--;
        }
        else
            printf("Entered Wrong choice\n");
    }
}

void display()
{
    int i;
    if(front==-1&&rear==-1)
        printf("Double Ended Queue is Empty\n");
    else{
        for(i=front;i<=rear;i++)
            printf("%d\t",dequeue[i]);
    }
}

int main()
{
    int ele,ch;
    while(1){
        printf("\n1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : printf("Enter the element you want to insert : ");
                        scanf("%d",&ele);
                        insert(ele);
                        break;
            case 2 : delete();
                        break;
            case 3 : display();
                        break;
            case 4 : exit(0);
                        break;
            default : printf("Invalid choice\n");
        }
    }
    return 0;
}
