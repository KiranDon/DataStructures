#include <stdio.h>
struct node
{
	int data;
	struct node * left, * right;
};
struct node * create()
{
	int x;
	struct node * newnode;
	newnode = (struct node *) malloc(sizeof(struct node));
	printf("\nEnter data (enter -1 for no Node): ");
	scanf("%d", &x);
	if(x==-1)
	{
		return 0;
	}
	else
	{
		newnode->data = x;
		printf("\nenter left child of %d: ", x);
		newnode->left = create();
		printf("\nenter right child of %d: ", x);
		newnode->right = create();
		return newnode;
	}
}
void main()
{
	printf("\n____________________________Binary tree implementation____________________________\n");
	struct node * root = create();
	
}

////PREORDER TRAVERSAL
//#include <stdio.h>
//void preorder(struct node * root)
//{
//	if(root == NULL)
//	{
//		return;
//	}
//	else
//	{
//		printf("%d ", root->data);
//		preorder(root->left);
//		preorder(root->right);
//	}
//}
//void main()
//{
//	printf("PreOrder is : ");
//	struct node * root;
//	preorder(root);
//}

////INORDER TRAVERSAL
//#include <stdio.h>
//void inorder(struct node * root)
//{
//	if(root == NULL)
//	{
//		return;
//	}
//	else
//	{
//		inorder(root->left);
//		printf("%d ", root->data);
//		inorder(root->right);
//	}
//}
//void main()
//{
//	printf("Inorder is : ");
//	struct node * root;
//	inorder(root);
//}

////POSTORDER TRAVERSAL
//#include <stdio.h>
//void postorder(struct node * root)
//{
//	if(root == NULL)
//	{
//		return;
//	}
//	else
//	{
//		postorder(root->left);
//		postorder(root->right);
//		printf("%d ", root->data);
//	}
//}
//void main()
//{
//	printf("Postorder is : ");
//	struct node * root;
//	postorder(root);
//}
