#pragma once
#include <iostream>
using namespace std;

const int CAN = 16516;
typedef char* type;

typedef struct node *link;
typedef struct node {
	int _can1;
	type _data;
	link _next;
	link _prev;
	size_t _checksum;
	int _can2;
	node(type data = 0):
	_data(data)
	{ 
		_next = _prev = NULL;
		_can1 = _can2 = CAN;
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