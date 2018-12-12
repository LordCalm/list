#include <iostream>
#include "HashTable.h"
#include "DoublyLinkedList.h"
#include "Random_cpp.h"

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
void func(hash_table *table)
{
	char data[10000][12];
	unsigned long long r = 0;
	for (int i = 0; i < 10000; i++)
	{
		r = Random(89000000000, 89999999999);
		///r = 5191591951;
		sprintf(data[i], "%llu", r);
		table->Register(data[i]);
	}
}
int main()
{
	try {
		hash_table table(h3);
		func(&table);
		table.DumpToFile("result.txt");
		table.hashed[0]->PrintList();
	}
	catch (...){
		cout << "Error\n";
	}
	return 0;
}