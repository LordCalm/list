#include <iostream>
#include <fstream>
#include "HashTable.h"
using namespace std;

void hash_table::Register(char* data)
{
	int x = hash_f(data) % table_size;
	if(hashed[x]->FindString(data) == 0) hashed[x]->InsertAfter(1, data);
	cout << data << "\n";
}
void hash_table::Remove(char* data)
{
	int x = hash_f(data) % table_size;
	if (hashed[x]->FindString(data) != 0) hashed[x]->Delete(hashed[x]->FindIndex(data));
}
void hash_table::DumpToFile(const char *file)
{
	ofstream f;
	f.open(file, ios::out);
	for (int i = 0; i < table_size; i++)
	{
		f << hashed[i]->_size << "\n";
	}
	f.close();
}