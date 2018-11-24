#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
typedef struct node *link;
typedef struct node {
	int can1;
	int data;
	link next;
	link prev;
	int checksum;
	int can2;
}item;
typedef struct list {
	link head;
	link tail;
	int size;
}list;

const int CAN = 16516;

void MemoryError();
link CreateNode();

list* CreateList();

void printInt(int value);
void PrintList(list *list, void(*fun)(void*));

void InsertFiled(int data);
void InsertAfter(list **List, int index, int data);
void InsertBefore(list **List, int index, int data);
list* ArrayToList(int *Array, int size);

void Delete(list **List, int index);
void DeleteList(list **List);

link FindPtr(list *list, int data);
link FindIndex(list *list, int data);

void Swap(link **ptr1, link **ptr2);
void BubbleSort(list **list);

int main()
{
	int M[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int size_M = sizeof(M) / sizeof(*M);
	//list *L = CreateList();
	list *L = ArrayToList(M, size_M);
	//InsertAfter(&L, 0, 1);
	//InsertAfter(&L, 1, 20);
	//InsertAfter(&L, 2, 20);
	//InsertBefore(&L, 3, 100);
	//Delete(&L, 1);
	//DeleteList(&L);
	//printf("%i\n", FindIndex(L, 100));
	//BubbleSort(&L);
	//printf("%i\n", (L->head)->checksum);
	PrintList(L, printInt);
	system("pause");
	return 0;
}

void MemoryError()
{
	printf("No memory\n");
	exit(1);
}
link CreateNode()
{
	link el = (item*)calloc(1, sizeof(item));
	if (el == NULL) MemoryError();
	el->can1 = el->can2 = CAN;
	return el;
}

size_t Checksum(link el)
{
	if (el != NULL)
	{
		if (el->next != NULL && el->prev != NULL)
		{
			size_t a = (size_t)el->next, b = (size_t)el->prev;
			return ((a * b) / (a - b)) + 21442;
		}
		else if (el->next != NULL)
		{
			size_t c = (size_t)el->next;
			return ((c * c) / (c - 15616)) + 21442;
		}
		else if (el->prev != NULL)
		{
			size_t d = (size_t)el->prev;
			return ((d * d) / (d - 15616)) + 21442;
		}
	}
}
void OK(link el)
{
	if (el != NULL)
	{
		if ((el->can1 != CAN && el->can2 != CAN) || (Checksum(el) != el->checksum))
		{
			printf("Error\n");
			system("pause");
			exit(1);
		}
	}
}

list* CreateList()
{
	list *tmp = CreateNode();
	tmp->size = 0;
	tmp->head = tmp->tail = NULL;
	return tmp;
}

void printInt(int value)
{
	printf("%i ", value);
}
void PrintList(list *list, void(*fun)(void*))
{
	link cur = list->head;
	while (cur)
	{
		fun(cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void InsertFiled(int data)
{
	printf("%i is not inserted.\n", data);
	system("pause");
	exit(1);
}
void InsertAfter(list **List, int index, int data)
{
	if (data)
	{
		if ((*List)->head != NULL)
		{
			if (0 < index && index <= (*List)->size)
			{
				((*List)->size)++;
				link cur = (*List)->head;
				for (int i = 1; i < index; i++)
				{
					//OK(cur);
					cur = cur->next;
				}
				link el = CreateNode();
				el->data = data;
				el->next = cur->next;
				el->prev = cur;
				cur->next = el;
				if (el->next != NULL)
				{
					(el->next)->prev = el;
					//el->next->checksum = Checksum(el->next);
				}
				/*
				el->checksum = Checksum(el);
				el->prev->checksum = Checksum(el->prev);
				*/
			}
			else InsertFiled(data);
		}
		else
		{
			if (0 <= index)
			{
				((*List)->size)++;
				link el = CreateNode();
				el->data = data;
				//el->checksum = Checksum(el);
				(*List)->head = el;
				(*List)->tail = el;
			}
			else InsertFiled(data);
		}
	}
	else InsertFiled(data);

}
void InsertBefore(list **List, int index, int data)
{
	if (data)
	{
		if ((*List)->head != NULL)
		{
			if (index == 1)
			{
				((*List)->size)++;
				link cur = (*List)->head;
				link el = CreateNode();
				el->data = data;
				el->next = cur;
				cur->prev = el;
				(*List)->head = el;
			}
			else if (1 < index && index <= (*List)->size)
			{
				((*List)->size)++;
				link cur = (*List)->head;
				for (int i = 1; i < index; i++)
				{
					cur = cur->next;
				}
				link el = CreateNode();
				el->data = data;
				el->next = cur;
				el->prev = cur->prev;
				cur->prev->next = el;
				cur->prev = el;
			}
			else InsertFiled(data);
		}
		else InsertFiled(data);
	}
	else InsertFiled(data);
}
list* ArrayToList(int *Array, int size)
{
	if (Array != NULL)
	{
		list *L = CreateList();
		for (int i = 0; i < size; i++)
		{
			InsertAfter(&L, i, Array[i]);
		}
		return L;
	}
	else
	{
		printf("Array is empty.\n");
		system("pause");
		exit(1);
	}
}

void Delete(list **List, int index)
{
	((*List)->size)--;
	link cur = (*List)->head;
	int i = 1;
	while (i < index)
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
void Swap(link **ptr1, link **ptr2)
{
	link *buf = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = buf;
}
void BubbleSort(list **list)
{
	if (list != NULL)
	{
		link cur = (*list)->head;
		int check = 1;
		while (check != 0)
		{
			int check1 = 0;
			while (cur->next != NULL)
			{
				if (cur->data > (cur->next)->data)
				{
					Swap(cur, cur->next);
					check1++;
				}
				cur = cur->next;
			}
			if (check1 == 0) check = 0;
			cur = (*list)->head;
		}
		(*list)->head = cur;
	}
	else
	{
		printf("BubbleSort is not performed.\n");
		system("pause");
		exit(1);
	}
}