#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *top=NULL;

void push()
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("Enter the node data : ");
    scanf("%d",&temp->data);
    temp->link=top;
    top=temp;
}

void pop()
{
    struct node *temp;
    temp=top;
    if(temp==NULL)
        printf("No nodes to delete \n");
    else
    {
        printf("Element deleting  : %d\n",temp->data);
        top=top->link;
        temp->link=NULL;
        free(temp);
    }
}
int length()
{
    struct node *temp=top;
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->link;
    }
    return count;
}
void traverse()
{
    struct node *temp;
    if(top==NULL)
        printf("Stack is EMPTY\n");
    else
    {
        temp=top;
        while(temp!=NULL)
        {
            printf("%d-->",temp->data);
            temp=temp->link;
        }
    }
}
void peek()
{
    struct node *temp=top;
    if(temp==NULL)
        printf("NO nodes to display \n");
    else
    {
        printf("Element at the top : %d\n",temp->data);
    }
}

int main()
{
    int ch,len;
    while(1)
    {
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Traverse\n");
        printf("5.Length\n");
        printf("6.Exit\n");
        printf("Enter anyone of the following : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1 : push();
            break;
            case 2 : pop();
            break;
            case 3 : peek();
            break;
            case 4 : traverse();
            break;
            case 5 : len=length();
            printf("Length :  %d\n",len);
            break;
            case 6 : exit(0);
            break;
            default : printf("Invalid location\n");
        }
    }
    return 0;
}
