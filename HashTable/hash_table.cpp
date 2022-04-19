#include <iostream>
#include <fstream>
#include "HashTable.h"
#include "HashFunc.h"
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
		f << i << " " << hashed[i]->_size << "\n";
	}
	f.close();
}

void hash_table::SaveToFile()
{
    /* пишем в файл целым классом как одним блоком */
    ofstream out("base.txt", ios::trunc);
    for (size_t i = 0; i < table_size; i++)
    {
        if (hashed[i]->_size != 0)
        {
            link cur = hashed[i]->_head;
            while (cur)
            {
                if (cur != NULL) cur->OK();
                out << *cur;
                cur = cur->_next;
            }
        }
        else
        {
            out << '\n';
        }
    }


    out.close();
}



void hash_table::LoadFromFile()
{
    ifstream in("base.txt");

    if (!in) // проверка - существует ли такой файл
        throw("File does not exist!");
    else
    {
        /*hash_table::~hash_table();
        hash_table::hash_table(hfunc);*/
        /* пишем в наш вектор с файла целым классом */
        char ch = '\0';
        while (true)
        {
            //do
            //{
            //    ch = in.get();
            //    if (in.eof() || in.fail()) break;
            //    i++;
            //} while (ch != ' ');
            //for (size_t j = 0; j < 11; j++)
            //{
            //    ch = in.get();
            //    snprintf(buf, sizeof buf + 1, "%s%s", buf, &ch);
            //}
            //in.seekg(-(11+i), ios::cur);
            ch = in.get();
            if (in.eof() || in.fail()) break;
            else if (ch != '\n') {
                in.putback(ch);
                link nodeOK = new node();
                in >> *nodeOK;
                nodeOK->OK();
                Register(nodeOK->_data);
                delete nodeOK;
            }
            
        }

        in.close();
    }
}