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

void swap()
{
    struct node *p,*q,*r;
    int loc,i=1;
    printf("Enter a location : ");
    scanf("%d",&loc);
    if(loc>length())
        printf("Invalid location\n");
    else
    {
        p=root;
        while(i<loc-1)
        {
            p=p->link;
            i++;
        }
        q=p->link;
        r=q->link;
        q->link=r->link;
        r->link=q;
        p->link=r;
    }
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

int main()
{
    int ch;
    while(1)
    {
    printf("\n1.Create\n");
    printf("2.Swap\n");
    printf("3.Display\n");
    printf("4.Exit\n");

    printf("Enter your choice : ");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1 : create();
                     break;
        case 2 : swap();
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
