#include<stdio.h>
#define MAX 5
int cqueue[MAX],front,rear;
front = -1,rear = -1;
void insert(int ele)
{
    if((front==0&&rear==MAX-1)||front==rear+1)
        printf("Circular Queue is Full\n");
    else if(front==-1&&rear==-1)
    {
        front=rear=0;
        cqueue[rear]=ele;
    }
    else if(rear==MAX-1&&front!=0)
    {
        rear =0;
        cqueue[rear]=ele;
    }
    else
    {
        rear++;
        cqueue[rear]=ele;
    }
}
void delete()
{
    int ele;
    if(front==-1&&rear==-1)
        printf("Circular Queue is Empty\n");
    else if(front==rear)
    {
        ele = cqueue[front];
        printf("Element deleted : %d\n",ele);
        front = rear =-1;
    }
    else if(front==MAX-1)
    {
        ele = cqueue[front];
        printf("Element deleted : %d\n",ele);
        front = 0;
    }
    else
    {
        ele = cqueue[front];
        printf("Element deleted : %d\n",ele);
        front++;
    }
}
void display()
{
    int i;
    if(front==-1&&rear==-1)
        printf("Circular Queue is Empty\n");
    else{
        if(front<rear){
            for(i=front;i<=rear;i++)
                printf("%d\t",cqueue[i]);
        }
        else{
            for(i=front;i<MAX;i++)
                printf("%d\t",cqueue[i]);
            for(i=0;i<=rear;i++)
                printf("%d\t",cqueue[i]);
        }
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
