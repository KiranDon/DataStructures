#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *root = NULL;
void create()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the node data : ");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if(root==NULL)
        root=temp;
    else
    {
        struct node *p=root;
        while(p->link!=NULL)
            p=p->link;
        p->link=temp;
    }
}

int length()
{
    int count = 0;
    struct node *temp = root;
    while(temp!=NULL)
    {
        count++;
        temp=temp->link;
    }
    return count;
}

void display()
{
        struct node *temp=root;
        if(temp==NULL)
            printf("No nodes are present in the list\n");
        while(temp!=NULL)
        {
            printf("%d-->",temp->data);
            temp=temp->link;
        }
        printf("\n");
}

void reverse()
{
    struct node *p =root,*q = root;
    int i=0,j=length()-1,k,temp;
    while(i<j)
    {
        k=0;
        while(k<j)
        {
            q=q->link;
            k++;
        }
        temp=p->data;
        p->data=q->data;
        q->data=temp;
        i++;
        j--;
        p=p->link;
        q=root;
    }
}

int main()
{
       int ch;
    while(1)
    {
    printf("\n1.Create\n");
    printf("2.Reverse\n");
    printf("3.Display\n");
    printf("4.Exit\n");

    printf("Enter your choice : ");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1 : create();
                     break;
        case 2 : reverse();
                     break;
        case 3 : display();
                     break;
        case 4 : exit(0);
                     break;
        default : printf("Invalid location\n");
    }
    }
    return 0;
}
