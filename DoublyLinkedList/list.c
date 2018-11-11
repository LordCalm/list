#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
typedef struct node *link;
typedef struct node {
	int data;
	link next;
	link prev;
}item;
item* ConvertToList(int* A, int size)
{
	int i = 0;
	item* B;
	B = (item*)calloc(size, sizeof(item));
	if (B == NULL)
	{
		printf("No memory\n");
		exit(1);
	}
	while (i < size) {
		B[i].data = A[i];
		if (i == size - 1) (B + i)->next = NULL;
		else (B + i)->next = B + i + 1;
		if (i == 0) (B + i)->prev = NULL;
		else (B + i)->prev = B + i - 1;
		i++;
	}
	return B;
}
int main()
{
	int M[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int size_M = sizeof(M) / sizeof(*M);
	item* L = ConvertToList(M, size_M);
	for (int i = 0; i < 10; i++)
	{
		printf("%i\n", (L + i)->data);
	}
	return 0;
}