#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)
void push(int b, int* p, int n, int* ptop);
int pop(int* p, int n, int* ptop);
int main()
{
	int stack[10], top = 0;
	push(8, stack, 10, &top);
	push(12, stack, 10, &top);
	push(5, stack, 10, &top);
	push(217, stack, 10, &top);
	printf("%i\n", pop(stack, 10, &top));
	printf("%i\n", pop(stack, 10, &top));
	return 0;
}
void push(int b, int* p, int n, int* ptop)
{
	if (*ptop >= n) {
		printf("Stack is full\n");
		exit(1);
	}
	p[(*ptop)++] = b;
}
int pop(int* p, int n, int* ptop)
{
	if (ptop == 0)
	{
		printf("Stack is empty\n");
		exit(1);
	}
	return p[--(*ptop)];
}
