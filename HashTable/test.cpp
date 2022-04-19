#include <iostream>
#include "HashTable.h"
#include "DoublyLinkedList.h"
#include "Random_cpp.h"
#include "HashFunc.h"


int main()
{
	try {
		char dma[] = "0419500515Dmitry";
		hash_table table(hfunc);
		table.Register(dma);
		table.SaveToFile();
		table.LoadFromFile();
		//table.hashed[(hfunc(dma) % 597)]->PrintList();
		/*for (size_t i = 0; i < 597; i++)
		{
			if (table.hashed[i]->_size != 0)
			{
				table.hashed[i]->PrintList();
			}
		}*/
		table.DumpToFile("result.txt");
		cout << "OK" << endl;
	}
	catch (...){
		cout << "Error" << endl;
	}
	return 0;
}

