#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue[MAX];
front=-1;
rear=-1;
void insert()

{

    int x;
     printf("Inset the element in queue : ");

        scanf("%d", &x);


    if (rear == MAX - 1)
    {

    printf("Queue is full");
}

    else if (front == - 1&&rear==-1)
    {

        front = rear=0;
        queue[rear]=x;
}
        
        else
        {
        rear++;
        queue[rear] = x;
}
}

void delete()

{

    if (front == - 1&&rear==-1)

    {

        printf("Queue is empty");

    }

    else if(front==rear)
    {
    front=rear=-1;
}
else
    {

    front++;

    }

}

 

void display()

{

    int i;

    if (front == - 1&&rear==-1)

        printf("Queue is empty");

    else

    {

        printf("Queue elements are ");

        for (i = front; i <= rear; i++)

            printf("%d ", queue[i]);

    }

} 
int main()
{
       int ch;
    while(1)
    {
    printf("\n1.Create\n");
    printf("2.Display\n");
    printf("3.Delete\n");
    printf("4.Exit\n");

    printf("Enter your choice : ");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1 : insert();
                     break;
        case 2 : display();
                     break;
        case 3 : delete();
                     break;
        case 4 : exit(0);
                     break;
        default : printf("Invalid location\n");
    }
    }
    return 0;
}

