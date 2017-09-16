#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define max(x,y) ((x) > (y) ? x : y)
struct BstNode
{
	int data;
	struct BstNode* left;
	struct BstNode* right;
};
struct BstNode* getNewNode(int data)
{
	struct BstNode* newNode = (struct BstNode*)malloc(sizeof(struct BstNode));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
}
struct BstNode* insert(struct BstNode* root,int data)
{
	if(root==NULL)
	{
		root = getNewNode(data);
		return root;
	}
	else if(data <= root->data)
	{
		root->left = insert(root->left,data);
	}
	else
	{
		root->right = insert(root->right,data);
	}
	return root;
}
int search(struct BstNode* root, int data)
{
	if(root==NULL)
	{
		return 0;
	}
	else if(root->data == data)
	{
		return 1;
	}
	else if(data <= root->data)
	{
		return search(root->left,data);
	}
	else
	{
		return search(root->right,data);
	}
}
int findMin(struct BstNode* root)
{
	if(root == NULL)
	{
		printf("Tree Empty\n");
		return -1;
	}
	else if(root->left == NULL)
	{
		return root->data;
	}
	return findMin(root->left);
}
int findMax(struct BstNode* root)
{
	if(root == NULL)
	{
		printf("Tree Empty\n");
		return -1;
	}
	while(root->right != NULL)
	{
		root = root->right;
	}
	return root->data;
}
int findHeight(struct BstNode* root)
{
	if(root == NULL)
	{
		return -1;
	}
	return max(findHeight(root->left),findHeight(root->right))+1;
}
void inOrder(struct BstNode* root)
{
	inOrder(root->left);
	if(root == NULL)
	{
		printf("%d",root->data);
	}
	inOrder(root->right);
}
int main()
{
	struct BstNode* root = NULL;
	int num = 0;
	root = insert(root,15);
	root = insert(root,10);
	root = insert(root,20);
	root = insert(root,25);
	root = insert(root,8);
	root = insert(root,12);
	printf("Enter a number to be searched\n");
	scanf("%d",&num);
	if(search(root,num))
	{
		printf("Found\n");
	}
	else
	{
		printf("Not Found\n");
	}
	printf("Maximum=%d\n",findMax(root));
	printf("Minimum=%d\n",findMin(root));
	printf("Height of Tree=%d\n",findHeight(root));
	printf("Inorder = \n");
        inOrder(root);
	return 0;
}
