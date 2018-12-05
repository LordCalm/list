#include <iostream>
#include <fstream>
//#include "List_cpp.h"
#include "DoublyLinkedList.h"
#include "Random_cpp.h"
using namespace std;
const int table_size = 597;
typedef struct hash_table
{
	hash_table(size_t(*hash_funk)(char*))
	{
		hash_f = hash_funk;
		for (int i = 0; i < table_size; i++)
		{
			hashed[i] = new list;
		}
	}
	list *hashed[table_size];
	size_t(*hash_f)(char*);
	void Register(char* data)
	{
		int x = hash_f(data) % table_size;
		//InsertAfter(hashed[x], 1, data);
		hashed[x]->InsertAfter(1, data);
		cout << data << "\n";
	}
	void Remove(char* data)
	{
		int x = hash_f(data) % table_size;
		//Delete(hashed[x], FindIndex(hashed[x], data));
	}
	void DumpToFile(const char *file)
	{
		ofstream f;
		f.open(file, ios::out);
		for (int i = 0; i < table_size; i++)
		{
			f << (int)hashed[i]->_size << "\n";
		}
		f.close();
	}
	~hash_table()
	{
		for (int i = 0; i < table_size; i++)
		{
			delete hashed[i];
		}
	}
}hash_table;
size_t h1(char *data)
{

	unsigned int hash = 2139062143;

	for (; *data; data++)
		hash = 37 * hash + *data;

	return hash;

}
size_t h2(char *data)
{
	int i = 0;
	int x = 10;
	while (data[i])
	{
		 x += data[i];
		 i++;
	}
	return x * x * x * 5195152;
}
size_t h3(char *data)
{
	unsigned int seed = 131313;
	unsigned int hash = 0;
	unsigned int i = 0;

	for (i = 0; i < 11; data++, i++)
	{
		hash = (hash * seed) + *data + i;
	}
	return hash;
}
int main()
{
	hash_table table(h3);
	char data[1000][128];
	unsigned long long r = 0;
	for (int i = 0; i < 1000; i++)
	{
		r = Random(89000000000, 89999999999);
		sprintf(data[i], "%llu", r);
		table.Register(data[i]);
	}
	table.DumpToFile("result.txt");
	return 0;
}