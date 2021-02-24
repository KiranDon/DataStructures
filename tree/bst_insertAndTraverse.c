#include <stdio.h>
#include <stdlib.h>
struct node * insert(struct node * root, int ele);
void preorder(struct node *root);
void inorder(struct node *root);
void postoder(struct node *root);
void traverse();
struct node 
{
	int data;
	struct node * left;
	struct node * right;
};
struct node * root = NULL;


int main()
{
	int choice, ele;
	while(choice!=3)
	{
		
		printf("Enter:\n1 for Insertion\n2 for Traversing\n3 for Exit\n");
		printf("Enter choice: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Enter an element to insert: ");
				scanf("%d", &ele);
				root = insert(root, ele);
				break;
			case 2:
				traverse();
				break;
			case 3:
				exit(0);
			default: 
			printf("INVALD CHOICE.");
		}
	}
	return 0;
}
struct node * insert(struct node * root, int ele)
{
	struct node *temp, *newNode, *p;
	newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = ele;
	newNode->left = NULL;
	newNode->right = NULL;
	if(root==NULL)
	{
		root = newNode;
		root->left = NULL;
		root->right = NULL;
	}
	else
	{
		p = root;
		temp = NULL;
		while(p!=NULL)
		{
			temp = p;
			if(ele<p->data)
			{
				p = p->left;
			}
			else
			{
				p = p->right;
			}
		}
		if(ele<temp->data)
		{
			temp->left = newNode;
		}
		else
		{
			temp->right = newNode;
		}
	}
	return root;
}


void preorder(struct node *root)
{
	if(root!=NULL)
	{
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(struct node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}
void postorder(struct node *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->data);
	}
}

void traverse()
{
	int choice;
	while(choice!=4)
	{
		
		printf("Enter:\n1 for PreOrder traversal\n2 for Inorder traversal\n3 for Postorder traversal\n4 for EXIT\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				preorder(root);
				break;
			case 2:
				inorder(root);
				break;
			case 3:
				postorder(root);
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("INVALID CHOICE");
		}
	}
}
