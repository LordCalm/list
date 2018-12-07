#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;

size_t node::Checksum()
{
	if (_next != NULL && _prev != NULL)
	{
		size_t a = (size_t)_next, b = (size_t)_prev;
		return ((a * b) / (a + b)) + 21442;
	}
	else if (_next != NULL)
	{
		size_t c = (size_t)_next;
		return ((c * c) / (c + 15616)) + 21442;
	}
	else if (_prev != NULL)
	{
		size_t d = (size_t)_prev;
		return ((d * d) / (d + 15616)) + 21442;
	}
	return 0;
}
void node::OK()
{
	if (_can1 != CAN || _can2 != CAN || Checksum() != _checksum)
	{
		cout << "Error\n";
		exit(1);
	}
	return;
}


void list::ListOK()
{
	if (_head != NULL && _tail != NULL)
		return;
	cout << "List not found.\n";
	exit(1);
}
void list::PrintList()
{
	link cur = _head;
	while (cur)
	{
		if (cur != NULL) cur->OK();
		cout << cur;
		cur = cur->_next;
	}
	cout << "\n";
}
void list::InsertAfter(int index, type data)
{
	ListOK();
	if (_head->_data)
	{
		if (0 < index && index <= _size)
		{
			_size++;
			if (_head != NULL) _head->OK();
			link cur = _head;
			for (int i = 1; i < index; i++)
			{
				cur = cur->_next;
			}
			if (cur != NULL) cur->OK();
			if (cur->_next != NULL) (cur->_next)->OK();
			link el = new node(data);
			el->_next = cur->_next;
			el->_prev = cur;
			cur->_next = el;
			if (el->_next != NULL)
			{
				(el->_next)->_prev = el;
				el->_next->_checksum = el->_next->Checksum();
			}
			el->_checksum = el->Checksum();
			el->_prev->_checksum = el->_prev->Checksum();
			if (el != NULL) el->OK();
			return;
		}
	}
	else
	{
		if (0 <= index)
		{
			(_size)++;
			link el = new node(data);
			el->_checksum = el->Checksum();
			_head = el;
			_tail = el;
			return;
		}
	}
	cout << data << " is not inserted.\n";
	exit(1);
}
void list::InsertBefore(int index, type data)
{
	ListOK();
	if (index == 1)
	{
		_size++;
		if (_head != NULL) _head->OK();
		link cur = _head;
		link el = new node(data);
		el->_next = cur;
		cur->_prev = el;
		_head = el;
		cur->_checksum = cur->Checksum();
		el->_checksum = el->Checksum();
		if (el != NULL) el->OK();
		return;
	}
	else if (1 < index && index <= _size)
	{
		_size++;
		if (_head != NULL) _head->OK();
		link cur = _head;
		for (int i = 1; i < index; i++)
		{
			cur = cur->_next;
		}
		if (cur != NULL) cur->OK();
		if (cur->_prev != NULL) (cur->_prev)->OK();
		link el = new node(data);
		el->_next = cur;
		el->_prev = cur->_prev;
		cur->_prev->_next = el;
		cur->_prev = el;
		cur->_checksum = cur->Checksum();
		cur->_prev->_checksum = cur->_prev->Checksum();
		el->_checksum = el->Checksum();
		if (el != NULL) el->OK();
		return;
	}
	cout << data << " is not inserted.\n";
	exit(1);
}
void list::ArrayToList(type *Array, int size)
{
	if (Array != NULL)
	{
		for (int i = 0; i < size; i++)
		{
			InsertAfter(i, Array[i]);
		}
	}
	else
	{
		cout << "Array is empty.\n";
		exit(1);
	}
}
void list::Delete(int index)
{
	ListOK();
	if (0 < index && index <= _size)
	{
		_size--;
		if (_head != NULL) _head->OK();
		link cur = _head;
		int i = 1;
		while (i < index)
		{
			cur = cur->_next;
			i++;
		}
		if (cur != NULL) cur->OK();
		if (index != 1)
		{
			if (cur->_prev != NULL) (cur->_prev)->OK();
			if (cur->_next != NULL) cur->_prev->_next = cur->_next;
			cur->_prev->_checksum = cur->_prev->Checksum();
		}
		else
		{
			if (cur->_next != NULL) (cur->_next)->OK();
			_head = cur->_next;
			_head->_checksum = _head->Checksum();
			if (cur->_next != NULL)
			{
				cur->_next->_prev = cur->_prev;
				cur->_next->_checksum = cur->_next->Checksum();
			}
		}
		delete cur;
		return;
	}
	cout << index << " is not deleted.\n";
	exit(1);
}
link list::FindPtr(type data)
{
	link cur = _head;
	while (cur->_data != data)
	{
		cur = cur->_next;
	}
	return cur;
}
int list::FindIndex(type data)
{
	link cur = _head;
	int i = 1;
	while (cur->_data != data)
	{
		cur = cur->_next;
		i++;
	}
	return i;
}
void list::Swap(link ptr1, link ptr2)
{
	type buf = ptr1->_data;
	ptr1->_data = ptr2->_data;
	ptr2->_data = buf;
}
void list::BubbleSort()
{
	link cur = _head;
	int check = 1;
	while (check != 0)
	{
		int check1 = 0;
		while (cur->_next != NULL)
		{
			if (cur->_data > (cur->_next)->_data)
			{
				Swap(cur, cur->_next);
				check1++;
			}
			cur = cur->_next;
		}
		if (check1 == 0) check = 0;
		cur = _head;
	}
	_head = cur;
	cout << "BubbleSort is not performed.\n";
	exit(1);
}