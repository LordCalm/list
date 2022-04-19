#pragma once
#include <iostream>
using namespace std;

const int CAN = 16516;
typedef char* type;
typedef struct node *link;
typedef struct node {
	int can1;
	type data;
	link next;
	link prev;
	size_t checksum;
	int can2;
}item;
typedef struct list {
	link head;
	link tail;
	int size;
}list;
void MemoryError()
{
	cout << "No memory\n";
	exit(1);
}
link CreateNode()
{
	link el = new item();
	if (el == NULL) MemoryError();
	el->can1 = el->can2 = CAN;
	return el;
}
void ListOK(list *L)
{
	if (L != NULL)
		if (L->head != NULL && L->tail != NULL)
			return;
	cout << "List not found.\n";
	exit(1);
}
size_t Checksum(link el)
{
	if (el != NULL)
	{
		if (el->next != NULL && el->prev != NULL)
		{
			size_t a = (size_t)el->next, b = (size_t)el->prev;
			return ((a * b) / (a + b)) + 21442;
		}
		else if (el->next != NULL)
		{
			size_t c = (size_t)el->next;
			return ((c * c) / (c + 15616)) + 21442;
		}
		else if (el->prev != NULL)
		{
			size_t d = (size_t)el->prev;
			return ((d * d) / (d + 15616)) + 21442;
		}
	}
	return 0;
}
void OK(link el)
{
	if (el != NULL)
	{
		if (el->can1 != CAN || el->can2 != CAN || Checksum(el) != el->checksum)
		{
			cout << "Error\n";
			exit(1);
		}
	}
	return;
}

list* CreateList()
{
	list *tmp = new list();
	tmp->size = 0;
	tmp->head = tmp->tail = CreateNode();
	return tmp;
}

void PrintList(list *list)
{
	link cur = list->head;
	while (cur)
	{
		OK(cur);
		cout << cur;
		cur = cur->next;
	}
	cout << "\n";
}

void InsertFiled(type data)
{
	cout << data << " is not inserted.\n";
	exit(1);
}
void InsertAfter(list *List, int index, type data)
{
	ListOK(List);
	if ((List)->head->data)
	{
		if (0 < index && index <= (List)->size)
		{
			(List)->size++;
			OK((List)->head);
			link cur = (List)->head;
			for (int i = 1; i < index; i++)
			{
				cur = cur->next;
			}
			OK(cur);
			OK(cur->next);
			link el = CreateNode();
			el->data = data;
			el->next = cur->next;
			el->prev = cur;
			cur->next = el;
			if (el->next != NULL)
			{
				(el->next)->prev = el;
				el->next->checksum = Checksum(el->next);
			}
			el->checksum = Checksum(el);
			el->prev->checksum = Checksum(el->prev);
			OK(el);
			return;
		}
	}
	else
	{
		if (0 <= index)
		{
			((List)->size)++;
			link el = CreateNode();
			el->data = data;
			el->checksum = Checksum(el);
			(List)->head = el;
			(List)->tail = el;
			return;
		}
	}
	InsertFiled(data);

}
void InsertBefore(list *List, int index, type data)
{
	ListOK(List);
	if (index == 1)
	{
		((List)->size)++;
		OK((List)->head);
		link cur = (List)->head;
		link el = CreateNode();
		el->data = data;
		el->next = cur;
		cur->prev = el;
		(List)->head = el;
		cur->checksum = Checksum(cur);
		el->checksum = Checksum(el);
		OK(el);
		return;
	}
	else if (1 < index && index <= (List)->size)
	{
		((List)->size)++;
		OK((List)->head);
		link cur = (List)->head;
		for (int i = 1; i < index; i++)
		{
			cur = cur->next;
		}
		OK(cur);
		OK(cur->prev);
		link el = CreateNode();
		el->data = data;
		el->next = cur;
		el->prev = cur->prev;
		cur->prev->next = el;
		cur->prev = el;
		cur->checksum = Checksum(cur);
		cur->prev->checksum = Checksum(cur->prev);
		el->checksum = Checksum(el);
		OK(el);
		return;
	}
	InsertFiled(data);
}
list* ArrayToList(type *Array, int size)
{
	if (Array != NULL)
	{
		list *L = CreateList();
		for (int i = 0; i < size; i++)
		{
			InsertAfter(L, i, Array[i]);
		}
		return L;
	}
	else
	{
		cout << "Array is empty.\n";
		exit(1);
	}
}

void Delete(list *List, int index)
{
	ListOK(List);
	if (0 < index && index <= (List)->size)
	{
		((List)->size)--;
		OK((List)->head);
		link cur = (List)->head;
		int i = 1;
		while (i < index)
		{
			cur = cur->next;
			i++;
		}
		OK(cur);
		if (index != 1)
		{
			OK(cur->prev);
			if (cur->next != NULL) cur->prev->next = cur->next;
			cur->prev->checksum = Checksum(cur->prev);
		}
		else
		{
			OK(cur->next);
			(List)->head = cur->next;
			(List)->head->checksum = Checksum((List)->head);
			if (cur->next != NULL)
			{
				cur->next->prev = cur->prev;
				cur->next->checksum = Checksum(cur->next);
			}
		}
		cur->next = cur->prev = NULL;
		delete cur;
		return;
	}
	cout << index << " is not deleted.\n";
	exit(1);
}
void DeleteList(list *List)
{
	if ((List)->head != NULL)
	{
		link tmp = (List)->head;
		link next = NULL;
		while (tmp) {
			next = tmp->next;
			tmp->next = tmp->prev = NULL;
			delete tmp;
			tmp = next;
		}
		delete List;
		(List) = NULL;
	}
}

link FindPtr(list *list, type data)
{
	link cur = list->head;
	while (cur->data != data)
	{
		cur = cur->next;
	}
	return cur;
}
int FindIndex(list *list, type data)
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
void Swap(link *ptr1, link *ptr2)
{
	type buf = (*ptr1)->data;
	(*ptr1)->data = (*ptr2)->data;
	(*ptr2)->data = buf;
}
void BubbleSort(list *list)
{
	if (list != NULL)
	{
		link cur = (list)->head;
		int check = 1;
		while (check != 0)
		{
			int check1 = 0;
			while (cur->next != NULL)
			{
				if (cur->data > (cur->next)->data)
				{
					Swap(&(cur), &(cur->next));
					check1++;
				}
				cur = cur->next;
			}
			if (check1 == 0) check = 0;
			cur = (list)->head;
		}
		(list)->head = cur;
	}
	else
	{
		cout << "BubbleSort is not performed.\n";
		exit(1);
	}
}