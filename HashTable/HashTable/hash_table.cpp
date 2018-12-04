#include <iostream>
#include <fstream>
#include "List_cpp.h"
#include "Random_cpp.h"
using namespace std;
const int table_size = 597;
typedef struct hash_table
{
	hash_table()
	{
		for (int i = 0; i < table_size; i++)
		{
			hashed[i] = CreateList();
		}
	}
	list *hashed[table_size];
	size_t(*hash_f)(char*);
	void Register(char* data)
	{
		int x = hash_f(data) % table_size;
		InsertAfter(&(hashed[x]), 1, data);
		cout << data << "\n";
	}
	void DumpToFile(const char *file)
	{
		ofstream f;
		f.open(file, ios::out);
		f << "Distribution:\n";
		for (int i = 0; i < table_size; i++)
		{
			f << (int)hashed[i]->size << "\n";
		}
		f.close();
	}
	~hash_table()
	{
		for (int i = 0; i < table_size; i++)
		{
			DeleteList(&hashed[i]);
		}
	}
}hash_table;
size_t h1(char* data)
{
	return data[5];
}
int main()
{
	hash_table table = {};
	table.hash_f = h1;
	char data[1000][128];
	unsigned long long r;
	for (int i = 0; i < 1000; i++)
	{
		r = Random(89000000000, 89999999999);
		sprintf(data[i], "%llu", r);
		table.Register(data[i]);
	}
	table.DumpToFile("result.txt");
	return 0;
}