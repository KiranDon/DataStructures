#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *front = NULL;
struct node *rear = NULL;

void insert()
{
    struct node *temp;
    temp = (struct node * )malloc(sizeof(struct node));
    printf("Enter the node data : ");
    scanf("%d",&temp->data);
    temp->link = NULL;
    if(front==NULL && rear ==NULL)
    {
        front=temp;
        rear=temp;
    }
    else
    {
        rear->link=temp;
        rear=temp;
    }
}

void delete()
{
    struct node *temp=front;
    if(front==NULL)
        printf("No nodes to delete\n");
    else
    {
        printf("Element deleted : %d\n",temp->data);
        front=front->link;
        temp->link=NULL;
        free(temp);
    }
}

void display()
{
    struct node *temp=front;
    if(front==NULL)
        printf("No nodes to display\n");
    else
    {
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->link;
        }
    }
}

int main()
{
    int ch;
    while(1)
    {
        printf("\n1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Exit\n");

        printf("Enter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1 : insert();
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
