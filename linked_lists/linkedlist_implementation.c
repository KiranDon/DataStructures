#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* link;
};
struct node* root = NULL;
int len;
void append()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter node data:");
	scanf("%d",&temp->data);
	temp->link=NULL;
	
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		struct node *p;
		p=root;
		while(p->link!=NULL)
		{
			p=p->link;
		}
		p->link=temp;
	}
}
int length()
{
	int count=0;
	struct node*temp;
	temp=root;
	while(temp!=NULL)
	{
		count++;
		temp=temp->link;
	}
	return count;
}
void display()
{
	struct node* temp;
	temp=root;
	if(temp==NULL)
		printf("No nodes to display\n");
	else
	{
		while(temp!=NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->link;
		}
	}
}
void addatbegin()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the node data : ");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		temp->link=root;
		root=temp;
	}
}
void addatafter()
{
	struct node *temp,*p;
	int loc,i=1;
	printf("Enter the location: ");
	scanf("%d",&loc);
	if(loc>length())
	{
		printf("No nodes are present at the given location\n");
	}
	else
	{
		p=root;
		while(i<loc)
		{
			p=p->link;
			i++;
		}
		temp = (struct node*)malloc(sizeof(struct node));
		printf("Enter the node data : ");
		scanf("%d",&temp->data);
		temp->link=NULL;
		temp->link=p->link;
		p->link=temp;
	}
}
void delete()
{
	struct node *temp;
	int loc;
	printf("Enter the location to delete : ");
	scanf("%d",&loc);
	if(loc>length())
	{
		printf("Invalid location\n");
	}
	else if(loc==1)
	{
		temp=root;
		root=temp->link;
		temp->link=NULL;
		free(temp);
	}
	else
	{
		int i=1;
		struct node *p=root,*q;
		while(i<loc-1)
		{
			p=p->link;
			i++;
		}
		q=p->link;
		p->link=q->link;
		q->link=NULL;
		free(q);
	}
}
int main()
{
	int ch;
	while(1)
	{
		printf("single linked list operations:\n");
		printf("1.Append\n");
		printf("2.Add at begin\n");
		printf("3.Add at after\n");
		printf("4.Length\n");
		printf("5.Display\n");
		printf("6.Delete\n");
		printf("7.Quit\n");
		
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: append();
					break;
			case 2: addatbegin();
					break;
			case 3: addatafter();
					break;
			case 4: len = length();
					printf("Length of the list : %d\n",len);
					break;
			case 5: display();
					break;
			case 6: delete();
					break;
			case 7: exit(1);
					break;
			default : printf("Invalid choice\n");
		}
	}
	return 0;
}

