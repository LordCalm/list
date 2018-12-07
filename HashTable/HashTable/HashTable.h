#pragma once
#include <iostream>
#include <fstream>
#include "DoublyLinkedList.h"
using namespace std;
const int table_size = 597;
typedef class hash_table
{
private:
	list *hashed[table_size];
	size_t(*hash_f)(char*);
public:
	hash_table(size_t(*hash_funk)(char*)) :
		hash_f(hash_funk)
	{
		for (int i = 0; i < table_size; i++)
		{
			hashed[i] = new list;
		}
	}
	void Register(char* data);
	void Remove(char* data);
	void DumpToFile(const char *file);
	~hash_table()
	{
		for (int i = 0; i < table_size; i++)
		{
			delete hashed[i];
		}
	}
}hash_table;
