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
    struct node *prevnode,*currnode,*temp = root;
    if(root!=NULL)
    {
        prevnode=root;
        currnode = root->link;
        root=root->link;
        prevnode->link=NULL;

        while(root!=NULL)
        {
            root=root->link;
            currnode->link=prevnode;
            prevnode=currnode;
            currnode=root;
        }
        root = prevnode;
    }
}

int main()
{
       int ch,n,i;
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
        case 1 : printf("How many nodes u want to create : ");
                     scanf("%d",&n);
                     for(i=1;i<=n;i++)
                        create();
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
