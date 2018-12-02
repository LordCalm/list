#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const int CAN = 16516;
typedef int type;
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
void ListOK(list *L);
size_t Checksum(link el);
void OK(link el);

void MemoryError();
link CreateNode();

list* CreateList();

void printFloat(link cur);
void printInt(link cur);
void PrintList(list *list, void(*fun)(link));

void InsertFiled(type data);
void InsertAfter(list **List, int index, type data);
void InsertBefore(list **List, int index, type data);
list* ArrayToList(type *Array, int size);

void Delete(list **List, int index);
void DeleteList(list **List);

link FindPtr(list *list, type data);
int FindIndex(list *list, type data);

void Swap(link *ptr1, link *ptr2);
void BubbleSort(list **list);