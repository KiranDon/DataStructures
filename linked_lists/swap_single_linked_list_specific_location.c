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

void swap_specific_location()
{
    struct node *p,*q,*r,*s;
    int loc1,loc2,i=1,j=1;
    printf("Enter location 1: ");
    scanf("%d",&loc1);
    printf("Enter location 2 : ");
    scanf("%d",&loc2);
    if(loc1>length()||loc2>length())
        printf("Invalid location\n");
    else
    {
        p=root,r=root;
        while(i<loc1-1)
        {
            p=p->link;
            i++;
        }
        q=p->link;
        while(j<loc2-1)
        {
            r=r->link;
            j++;
        }
        s=r->link;
        q->link=s->link;
        s->link=r;
        p->link=s;
        r->link=q;
    }
}

void swap_start_end()
{
    struct node *p=root,*q=root,*r,*s;
    int i=1;
    while(i<length()-1)
    {
        q=q->link;
        i++;
    }
    r=q->link;
    s=p->link;
    root=r;
    r->link=s;
    q->link=p;
    p->link=NULL;
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

int main()
{
    int ch;
    while(1)
    {
    printf("\n1.Create\n");
    printf("2.Swap at consecutive locations\n");
    printf("3.Swap at specific locations\n");
    printf("4.Swap first and last nodes\n");
    printf("5.Display\n");
    printf("6.Exit\n");

    printf("Enter your choice : ");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1 : create();
                     break;
        case 2 : swap();
                     break;
        case 3 : swap_specific_location();
                     break;
        case 4 : swap_start_end();
                     break;
        case 5 : display();
                     break;
        case 6 : exit(0);
                     break;
        default : printf("Invalid location\n");
    }
    }
    return 0;
}
