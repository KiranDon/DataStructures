#include <stdio.h>
#include <stdlib.h>
struct node * insert();
void preorder(struct node *root);
void inorder(struct node *root);
void postoder(struct node *root);
void traverse();
struct node * smallest(struct node * root);
void largest(struct node * root);
struct node * deleteNode(struct node *root, int ele);
void count(struct node *root);
int c = 0;
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
	while(choice!=7)
	{
		
		printf("Enter:\n1 for Insertion\n2 for Traversing\n3 for Smallest element\n4 for Largest element\n5 for Deletion\n6 for Total Nodes\n7 for Exit\n");
		printf("Enter choice: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				root = insert();
				break;
			case 2:
				traverse();
				break;
			case 3:
				smallest(root);
				break;
			case 4:
				largest(root);
				break;
			case 5:
				printf("Enter element to delete from BST: ");
				scanf("%d", &ele);
				root = deleteNode(root, ele);
				break;
			case 6:
				count(root);
				printf("\nTotal nodes: %d", c);
			case 7:
				exit(0);
			default: 
			printf("INVALD CHOICE.");
		}
	}
	return 0;
}
struct node * insert()
{
	int ele;
	while(ele!=-1)
	{
		printf("Enter an element to insert: (press -1 to stop entering values.)");
		scanf("%d", &ele);
		if(ele==-1)
		{
			continue;
		}
		else
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

struct node * smallest(struct node * root)
{
	struct node *p=root, *temp;
	if(p==NULL)
	{
		printf("No elements are present in the BST.");
	}
	else
	{
		while(p!=NULL)
		{
			temp = p;
			p=p->left;
		}
		printf("\nSmallest element in the BST is %d \n", temp->data);
		return temp;
	}
}
void largest(struct node * root)
{
	struct node *p=root, *temp;
	if(temp==NULL)
	{
		printf("No elements are present in the BST.");
	}
	else
	{
		while(p!=NULL)
		{
			temp = p;
			p=p->right;
		}
		printf("Largest element in the BST is %d", temp->data);
	}
}
struct node * deleteNode(struct node *root, int ele)
{
	if(root==NULL)
	{
		return root;
	}
	if(ele < root->data)
	{
		root->left = deleteNode(root->left, ele);
	}
	else if(ele > root->data)
	{
		root->right = deleteNode(root->right, ele);
	}
	else
	{
		if(root->left==NULL)
		{
			struct node *temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL)
		{
			struct node *temp = root->left;
			free(root);
			return temp;
		}
		
		//finding inorder successor....smallest element in the right sub tree
		struct node *temp = smallest(root->right);
		
		//copy small inorder successor to root
		root->data = temp->data;
		
		//delete successor
		root->right = deleteNode(root->right, temp->data);
	}
	return root;
}
void count(struct node *root)
{
	if(root!=NULL)
	{
		count(root->left);
		count(root->right);
		c++;
	}
}

