 #include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *root;

void append()
{
    struct node *temp,*current;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("Enter the node data : ");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if(root==NULL)
    {
        root=temp;
        root->link=root;
    }
    else
    {
        current = root;
        while(current->link!=root)
            current=current->link;
        current->link=temp;
        temp->link=root;
    }
}

void addatbegin()
{
    struct node *temp,*current;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("Enter the node data : ");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if(root==NULL)
        root=temp;
    else
    {
        current=root;
        temp->link=root;
        while(current->link!=root)
            current=current->link;
        current->link=temp;
        root=temp;
    }
}

int length()
{
    struct node *current;
    int count=0;
    current=root;
    while(current->link!=root)
    {
        count++;
        current=current->link;
    }
    count++;
    return count ;
}

void display()
{
    struct node *current;
    current=root;
    if(current==NULL)
        printf("No nodes to display\n");
    else
    {
        while(current->link!=root)
        {
            printf("%d-->",current->data);
            current=current->link;
        }
        printf("%d\n",current->data);
    }
}

void addatafter()
{
    struct node *temp,*current;
    int loc,len,i=1;
    printf("Enter the location : ");
    scanf("%d",&loc);
    if(loc>length())
        printf("Invalid location\n");
    else
    {
        temp=(struct node *)malloc(sizeof(struct node));
        printf("Enter the node data : ");
        scanf("%d",&temp->data);
        temp->link=NULL;
        current=root;
        while(i<loc)
        {
            current=current->link;
            i++;
        }
        temp->link=current->link;
        current->link=temp;
    }
}

void delete()
{
    struct node *temp,*current;
    int loc;
    printf("Enter the location to delete : ");
    scanf("%d",&loc);
    if(loc>length())
        printf("Invalid location\n");
    else
    {
        struct node *q;
        current=root;
        int i=1;
        while(i<loc-1)
        {
            current=current->link;
            i++;
        }
        q=current->link;
        current->link=q->link;
        q->link=NULL;
        free(q);
    }
}

void del_begin()
{
    struct node *temp=root,*p=root;
    while(p->link!=root)
    {
        p=p->link;
    }
    root=temp->link;
    temp->link=NULL;
    p->link=root;
}


int main()
{
    int ch,len;
    while(1)
    {
        printf("\nCircular linked list operations\n");
        printf("1.Append\n");
        printf("2.Add at beginning\n");
        printf("3.Add at after\n");
        printf("4.Length\n");
        printf("5.Display\n");
        printf("6.Delete at beginning\n");
        printf("7.Delete at specific location\n");
        printf("8.Exit\n");

        printf("Enter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1 : append();
                        break;
            case 2 : addatbegin();
                        break;
            case 3 : addatafter();
                        break;
            case 4 : len = length();
                        printf("Length : %d\n",len);
                        break;
            case 5 : display();
                        break;
            case 6 : del_begin();
                        break;
            case 7 : delete();
                        break;
            case 8 : exit(0);
                        break;
            default : printf("Invalid choice\n");
        }
    }
    return 0;
}

