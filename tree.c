#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

typedef struct Node {
	int data;
	struct node *left_ptr;
	struct node *right_ptr;
}node;

void Insert(node **root_ptr, int value);
void Traverse(node *root_ptr);
node* Find(node *root_ptr, int value);
node* Minimum(node *x);
node* Remove(node **root_ptr, int value);

int main()
{
	node *root_ptr = NULL;
	Insert(&root_ptr, 10);
	Insert(&root_ptr, 5);
	Insert(&root_ptr, 15);
	Insert(&root_ptr, 3);
	Insert(&root_ptr, 11);
	Traverse(root_ptr);
	//printf("%i\n", (Find(root_ptr, 3))->data);
	Remove(&root_ptr, 10);
	printf("\n");
	Traverse(root_ptr);
	return 0;
}

void Insert(node **root_ptr, int value)
{
	if (*root_ptr == NULL)
	{
		*root_ptr = (node*)calloc(1, sizeof(node));
		if (*root_ptr != NULL)
		{
			(*root_ptr)->data = value;
			(*root_ptr)->left_ptr = (*root_ptr)->left_ptr = NULL;
		}
		else
		{
			printf("No memory aviable\n");
			exit(1);
		}
	}
	else if (value < (*root_ptr)->data) Insert(&(*root_ptr)->left_ptr, value);
	else if (value > (*root_ptr)->data) Insert(&(*root_ptr)->right_ptr, value);
	else printf("Dup\n");
}

void Traverse(node *root_ptr)
{
	if (root_ptr != NULL)
	{
		Traverse(root_ptr->left_ptr);
		printf("%i ", root_ptr->data);
		Traverse(root_ptr->right_ptr);
	}
}

node* Find(node *root_ptr, int value)
{
	if (root_ptr == NULL)
	{
		printf("NO\n");
		exit(1);
	}
	else if (root_ptr->data == value) return root_ptr;
	else if (value < root_ptr->data) Find(root_ptr->left_ptr, value);
	else if (value > root_ptr->data) Find(root_ptr->right_ptr, value);
	else printf("Dup\n");
}

node* Minimum(node *x)
{
	if (x->left_ptr == NULL)
		return x;
	else
		return Minimum(x->left_ptr);
}
node* Remove(node **root_ptr, int value)
{
	if (*root_ptr == NULL)
		return *root_ptr;
	else if (value < (*root_ptr)->data)
		(*root_ptr)->left_ptr = Remove(&(*root_ptr)->left_ptr, value);
	else if (value > (*root_ptr)->data)
		(*root_ptr)->right_ptr = Remove(&(*root_ptr)->right_ptr, value);
	else if ((*root_ptr)->left_ptr != NULL && (*root_ptr)->right_ptr != NULL)
	{
		(*root_ptr)->data = (Minimum((*root_ptr)->right_ptr))->data;
		(*root_ptr)->right_ptr = Remove(&(*root_ptr)->right_ptr, (*root_ptr)->data);
	}
	else 
		if ((*root_ptr)->left_ptr != NULL)
			*root_ptr = (*root_ptr)->left_ptr;
		else
			*root_ptr = (*root_ptr)->right_ptr;
	return *root_ptr;
}
