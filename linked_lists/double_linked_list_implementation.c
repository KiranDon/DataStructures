#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *right;
    struct node *left;
};
struct node *root=NULL;

void append()
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("Enter the node data : ");
    scanf("%d",&temp->data);
    temp->right=NULL;
    temp->left=NULL;
    if(root==NULL)
        root=temp;
    else
    {
        struct node *p;
        p=root;
        while(p->right!=NULL)
            p=p->right;
        p->right=temp;
        temp->left=p;
    }
}
void addatbegin()
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("Enter the node data : ");
    scanf("%d",&temp->data);
    temp->right=NULL;
    temp->left=NULL;
    if(root==NULL)
        root=temp;
     else
    {
        temp->right=root;
        root->left=temp;
        root=temp;
    }
}

int length()
{
    struct node *temp=root;
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->right;
    }
    return count;
}

void display()
{
    struct node *temp =root;
    if (temp==NULL)
        printf("List is empty\n");
    else{
    while(temp!=NULL)
    {
        printf("%d-->",temp->data);
        temp=temp->right;
    }
    }
}
void addatafter()
{
    struct node *temp,*p=root;
    int loc,i=1;
    printf("Enter the location : ");
    scanf("%d",&loc);
    if(loc>length())
        printf("Invalid location\n");
    else
    {
        temp=(struct node*)malloc(sizeof(struct node));
        printf("Enter the node data : ");
        scanf("%d",&temp->data);
        temp->right=NULL;
        temp->left=NULL;
        while(i<loc)
        {
            p=p->right;
            i++;
        }
        temp->right=p->right;
        p->right->left=temp;
        temp->left=p;
        p->right=temp;
    }
}
void delete()
{
    struct node *temp;
    int loc;
    printf("Enter the location : ");
    scanf("%d",&loc);
    if(loc>length())
        printf("No nodes to delete\n");
    else if(loc==1)
    {
        temp=root;
        root=temp->right;
        root->left=NULL;
        free(temp);
    }
    else if(loc==length())
    {
        temp=root;
        while(temp->right!=NULL)
        {
            temp=temp->right;
        }
        temp->left->right=NULL;
        temp->left=NULL;
        free(temp);
    }
    else
    {
        struct node *p=root,*q;
        int i=1;
        while(i<loc-1)
        {
            p=p->right;
            i++;
        }
        q=p->right;
        p->right=q->right;
        q->right->left=p;
        free(q);
    }
}
int main()
{
    int ch,len;
    while(1)
    {
        printf("\n1.Append\n");
        printf("2.Add at beginning \n");
        printf("3.Add at after\n");
        printf("4.Length\n");
        printf("5.Display\n");
        printf("6.Delete\n");
        printf("7.Quit\n");

        printf("Enter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: append();
            break;
            case 2:addatbegin();
            break;
            case 3: addatafter();
            break;
            case 4:len=length();
            printf("Length : %d\n",len);
            break;
            case 5: display();
            break;
            case 6: delete();
            break;
            case 7:exit(0);
            break;
            default : printf("Invalid choice\n");
        }
    }
    return 0;
}
