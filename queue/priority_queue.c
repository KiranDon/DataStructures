#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    int priority;
    struct node *link;
};

struct node *front=NULL,*rear=NULL;

void create()
{
    struct node *temp,*q;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("Enter the node data : ");
    scanf("%d",&temp->data);
    printf("Enter the node priority : ");
    scanf("%d",&temp->priority);
    temp->link=NULL;
    if(front==NULL || temp->priority<front->priority)
    {
        temp->link=front;
        front=temp;
    }
    else
    {
        q=front;
        while(q->link!=NULL && q->link->priority<=temp->priority)
        {
        
            q=q->link;
   }
        temp->link=q->link;
        q->link=temp;
    }
}

void del()
{
	struct node *tmp;
	if(front == NULL)
		printf("Queue Underflow\n");
	else
	{
		tmp = front;
		printf("Deleted item is %d\n",tmp->data);
		front = front->link;
		free(tmp);
	}
}

void display()
{
    struct node *q = front;
    if(front==NULL && rear ==NULL)
        printf("No nodes to display\n");
    else
    {
        while(q!=NULL)
        {
            printf("%d\t",q->data);
            printf("%d\n",q->priority);
            q=q->link;
        }
    }
}

int main()
{
        int ch,n,i;
        while(1){
		printf("\n1.Insert\n");
		printf("2.Delete\n");
		printf("3.Display\n");
		printf("4.Quit\n");
		printf("Enter your choice : ");
		scanf("%d", &ch);
		switch(ch)
		{
		    case 1 : printf("How many nodes u want to create : ");
                         scanf("%d",&n);
                         for(i=1;i<=n;i++)
                            create();
                         break;
            case 2 : del();
                         break;
            case 3 : display();
                         break;
            case 4 : exit(0);
                         break;
		}
        }
    return 0;
}
