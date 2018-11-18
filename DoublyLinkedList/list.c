#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
typedef struct node *link;
typedef struct node {
	int data;
	link next;
	link prev;
}item;
item* ArrayToList(int *Array, int size);
void PrintList(item *List);
void InsertAfter(item *List, int number, int data);
void insertBefore(item *List, int number, int data);
void Delete(item *List, int number)
{
	link cur = List;
	for (int i = 1; i < number; i++)
	{
		cur = cur->next;
	}
	cur->prev->next = cur->next;
	cur->next->prev = cur->prev;
	free(cur);
}
int main()
{
	int M[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int size_M = sizeof(M) / sizeof(*M);
	item* L = ArrayToList(M, size_M);
	InsertAfter(L, 3, 20);
	insertBefore(L, 5, 100);
	Delete(L, 3);
	PrintList(L);
	system("pause");
	return 0;
}
item* ArrayToList(int *Array, int size)
{
	item *cur = (item*)calloc(1, sizeof(item));
	item *List = cur;
	for (int i = 0; i < size; i++)
	{
		cur->data = Array[i];
		if (i < size - 1)
		{
			cur->next = (item*)calloc(1, sizeof(item));
			cur->next->prev = cur;
		}
		else cur->next = NULL;
		cur = cur->next;
	}
	return List;
}
void InsertAfter(item *List, int number, int data)
{
	link cur = List;
	for (int i = 1; i < number; i++)
	{
		cur = cur->next;
	}
	item *el = (item*)calloc(1, sizeof(item));
	el->data = data;
	el->next = cur->next;
	el->prev = cur;
	cur->next = el;
	(el->next)->prev = el;
}
void insertBefore(item *List, int number, int data)
{
	link cur = List;
	for (int i = 1; i < number; i++)
	{
		cur = cur->next;
	}
	item *el = (item*)calloc(1, sizeof(item));
	el->data = data;
	el->next = cur;
	el->prev = cur->prev;
	cur->prev->next = el;
	cur->prev = el;
}
void PrintList(item *List)
{
	link cur = List;
	do
	{
		printf("%i\n", cur->data);
		cur = cur->next;
	} while (cur != NULL);
}