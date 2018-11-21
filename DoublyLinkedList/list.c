#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
typedef struct node *link;
typedef struct node {
	int data;
	link next;
	link prev;
}item;
typedef struct list {
	link head;
	link tail;
	int size;
}list;
list* ArrayToList(int *Array, int size);

void printInt(int value);
void PrintList(list *list, void(*fun)(void*));

void InsertAfter(list *List, int index, int data);
void insertBefore(list *List, int index, int data);

void Delete(list **List, int index);
void DeleteList(list **List);

link FindPtr(list *list, int data);
link FindIndex(list *list, int data);

int main()
{
	int M[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int size_M = sizeof(M) / sizeof(*M);
	list *L = ArrayToList(M, size_M);
	InsertAfter(L, 0, 20);
	insertBefore(L, 3, 100);
	Delete(&L, 1);
	//DeleteList(&L);
	printf("%i\n", FindIndex(L, 100));
	PrintList(L, printInt);
	system("pause");
	return 0;
}
list* CreateList()
{
	list *tmp = (list*)malloc(sizeof(list));
	tmp->size = 0;
	tmp->head = tmp->tail = NULL;
	return tmp;
}
list* ArrayToList(int *Array, int size)
{
	item *cur = (item*)calloc(1, sizeof(item));
	list *List = (list*)calloc(1, sizeof(list));
	List->head = cur;
	List->size = size;
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
	List->tail = cur;
	return List;
}

void printInt(int value)
{
	printf("%i ", value);
}
void PrintList(list *list, void (*fun)(void*))
{
	link cur = list->head;
	while (cur) 
	{
		fun(cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void InsertAfter(list *List, int index, int data)
{
	(List->size)++;
	link cur = List->head;
	for (int i = 1; i < index; i++)
	{
		cur = cur->next;
	}
	link el = (item*)calloc(1, sizeof(item));
	el->data = data;
	el->next = cur->next;
	el->prev = cur;
	cur->next = el;
	(el->next)->prev = el;
}
void insertBefore(list *List, int index, int data)
{
	(List->size)++;
	link cur = List->head;
	for (int i = 1; i < index; i++)
	{
		cur = cur->next;
	}
	link el = (item*)calloc(1, sizeof(item));
	el->data = data;
	el->next = cur;
	el->prev = cur->prev;
	cur->prev->next = el;
	cur->prev = el;
}

void Delete(list **List, int index)
{
	((*List)->size)--;
	link cur = (*List)->head;
	int i = 1;
	while(i < index)
	{
		cur = cur->next;
		i++;
	}
	if (i != 1) cur->prev->next = cur->next;
	else (*List)->head = cur->next;
	if (cur->next != NULL) cur->next->prev = cur->prev;
	free(cur);
}
void DeleteList(list **List)
{
	link tmp = (*List)->head;
	link next = NULL;
	while (tmp) {
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(*List);
	(*List) = NULL;
}

link FindPtr(list *list, int data)
{
	link cur = list->head;
	while (cur->data != data)
	{
		cur = cur->next;
	}
	return cur;
}
link FindIndex(list *list, int data)
{
	link cur = list->head;
	int i = 1;
	while (cur->data != data)
	{
		cur = cur->next;
		i++;
	}
	return i;
}

