#include<stdio.h>
#include<stdlib.h>
struct node
{
    char name[50];
    int id;
    int rank;
    struct node* link;
};
struct node *root;

void create()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the student name : ");
    scanf("%s",&temp->name);
    printf("Enter the student id : ");
    scanf("%d",&temp->id);
    printf("Enter the student rank : ");
    scanf("%d",&temp->rank);
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

void check()
{
    struct node *temp=root;
    int count=0;
    printf("\nStudents who got first class are : \n");
    while(temp!=NULL)
    {
        if(temp->rank==1)
           {
               count++;
            printf("%s\n",temp->name);
           }
        temp=temp->link;
    }
    if(count==0)
        printf("None of the students got first class\n");

}

int main()
{
    int n,i;
    printf("How many student details u want to enter : ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        create();
    check();
    return 0;
}
