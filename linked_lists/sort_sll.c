#include<stdio.h>
struct node
{
    int data;
    struct node* link;
};
struct node *root=NULL;
void create()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data : ");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if(root==NULL)
        root=temp;
    else
    {
        struct node *p;
        p=root;
        while(p->link!=NULL)
            p=p->link;
        p->link=temp;
    }
}

void sort()
{
    struct node *i,*j;
    int temp;
    for(i=root;i->link!=NULL;i=i->link)
    {
        for(j=i->link;j!=NULL;j=j->link)
        {
            if(i->data>j->data)
            {
                temp=i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void display()
{
    struct node *temp=root;
    if(temp==NULL)
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
    int ch,n,i;
    while(1)
    {
    printf("\n1.Create\n");
    printf("2.Sort\n");
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
        case 2 : sort();
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
