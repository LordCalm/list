size_t hfunc(char* data)
{
	unsigned int seed = 131313;
	unsigned int hash = 0;
	unsigned int i = 0;

	for (i = 0; i < 9; data++, i++)
	{
		hash = (hash * seed) + *data + i;
	}
	return hash;
}

size_t hf(char* data)
{
	char buf[11];
	for (size_t i = 0; i < sizeof(buf); i++)
	{
		buf[i] = data[i];
	}
	return (size_t)(buf - '0');
}

size_t h1(char* data)
{

	unsigned int hash = 2139062143;

	for (; *data; data++)
		hash = 37 * hash + *data;

	return hash;
}
size_t h2(char* data)
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

size_t h3(char* data)
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


//void func(hash_table* table)
//{
//	char data[10000][12];
//	unsigned long long r = 0;
//	for (int i = 0; i < 10000; i++)
//	{
//		r = Random(89000000000, 89999999999);
//		///r = 5191591951;
//		sprintf(data[i], "%llu", r);
//		table->Register(data[i]);
//	}
//}