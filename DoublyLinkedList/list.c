#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"
#pragma warning(disable : 4996)
int main()
{
	int M[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int size_M = sizeof(M) / sizeof(*M);
	//list *L = CreateList();
	list *L = ArrayToList(M, size_M);
	InsertAfter(&L, 1, 1);
	InsertAfter(&L, 1, 20);
	InsertAfter(&L, 2, 20);
	InsertBefore(&L, 1, 100);
	Delete(&L, 1);
	//DeleteList(&L);
	//printf("%i\n", FindIndex(L, 100));
	BubbleSort(&L);
	//printf("%i\n", (L->head)->checksum);
	PrintList(L, printInt);
	system("pause");
	return 0;
}
