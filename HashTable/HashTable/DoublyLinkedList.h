#pragma once
#include <iostream>
#define FAST_LIST
using namespace std;

const int CAN = 16516;
typedef char* type;

typedef struct node *link;
typedef struct node {
	#ifndef FAST_LIST
	int _can1;
	#endif
	type _data;
	link _next;
	link _prev;
	#ifndef FAST_LIST
	size_t _checksum;
	int _can2;
	#endif
	node(type data = 0):
	_data(data)
	{ 
		_next = _prev = NULL;
		#ifndef FAST_LIST
		_can1 = _can2 = CAN;
		#endif
	}
	size_t Checksum();
	void OK();
	~node()
	{
		_data = 0;
		_next = _prev = NULL;
	}
}item;

typedef struct list {
	link _head;
	link _tail;
	int _size;
	list():
	_size(0)
	{
		_head = _tail = new node();
	}
	void ListOK();
	void PrintList();
	void InsertAfter(int index, type data);
	void InsertBefore(int index, type data);
	void ArrayToList(type *Array, int size);
	void Delete(int index);
	link FindPtr(type data);
	int FindIndex(type data);
	void Swap(link ptr1, link ptr2);
	void BubbleSort();
	~list()
	{
		link tmp = _head;
		link next = NULL;
		while (tmp) {
			next = tmp->_next;
			tmp->_next = tmp->_prev = NULL;
			delete tmp;
			tmp = next;
		}
		_head = _tail = NULL;
		_size = 0;
	}
}list;