#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
    int coeff;
    int pow;
    struct node *link;
};
struct node *poly1=NULL,*poly2=NULL,*poly=NULL;
void create(struct node *temp)
{
    char ch;
    do
    {
        printf("\nEnter the coefficient : ");
        scanf("%d",&temp->coeff);
        printf("Enter the power : ");
        scanf("%d",&temp->pow);
        temp->link=(struct node *)malloc(sizeof(struct node));
        temp=temp->link;
        temp->link=NULL;
        printf("Continue(y/n) : ");
        ch=getch();
    }while(ch=='Y'||ch=='y');
}

void show(struct node *temp)
{
    while(temp->link!=NULL)
    {
        printf("%dx^%d",temp->coeff,temp->pow);
        temp=temp->link;
        if(temp->link!=NULL)
            printf("+");
    }
}

void polyadd(struct node *poly1,struct node *poly2,struct node *poly)
{
    while(poly1->link&&poly2->link)
    {
        if(poly1->pow>poly2->pow)
        {
            poly->pow=poly1->pow;
            poly->coeff=poly1->coeff;
            poly1=poly1->link;
        }
        else if(poly1->pow<poly2->pow)
        {
            poly->pow=poly2->pow;
            poly->coeff=poly2->coeff;
            poly2=poly2->link;
        }
        else
        {
            poly->pow=poly1->pow;
            poly->coeff=poly1->coeff+poly2->coeff;
            poly1=poly1->link;
            poly2=poly2->link;
        }
    poly->link=(struct node *)malloc(sizeof(struct node));
    poly=poly->link;
    poly->link=NULL;
    }
    while(poly1->link||poly2->link)
    {
        if(poly1->link)
        {
            poly->pow=poly1->pow;
            poly->coeff=poly1->coeff;
            poly1=poly1->link;
        }
        if(poly2->link)
        {
            poly->pow=poly2->pow;
            poly->coeff=poly2->coeff;
            poly2=poly2->link;
        }
        poly->link=(struct node *)malloc(sizeof(struct node));
        poly=poly->link;
        poly->link=NULL;
    }
}
int main()
{
    char ch;
    do
    {
       poly1=(struct node *)malloc(sizeof(struct node));
       poly2=(struct node *)malloc(sizeof(struct node));
       poly=(struct node *)malloc(sizeof(struct node));
       printf("\nEnter the first polynomial : ");
       create(poly1);
       printf("\nEnter the second polynomial : ");
       create(poly2);
       printf("\nFirst polynomial : ");
       show(poly1);
       printf("\nSecond polynomial : ");
       show(poly2);
       polyadd(poly1,poly2,poly);
       printf("\nResult : ");
       show(poly);
       printf("\nAdd two more numbers : ");
       ch=getch();
    }while(ch=='Y'||ch=='y');
    return 0;
}
	
