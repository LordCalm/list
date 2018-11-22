#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)
typedef struct node {
	int data;
	struct node* next;
}item;
void push(int data, item** pptr);
int pop(item** pptr);
int main()
{
	item* stack_ptr = NULL;
	push(10, &stack_ptr);
	push(20, &stack_ptr);
	push(30, &stack_ptr);
	push(40, &stack_ptr);
	printf("%i\n", pop(&stack_ptr));
	printf("%i\n", pop(&stack_ptr));
	printf("%i\n", pop(&stack_ptr));
	printf("%i\n", pop(&stack_ptr));
	printf("%i\n", pop(&stack_ptr));
	return 0;
}
void push(int data, item** pptr)
{
	item* ptr = (item*)calloc(1, sizeof(item));
	if (ptr == NULL)
	{
		printf("No empty\n");
		exit(1);
	}
	ptr->data = data;
	ptr->next = *pptr;
	*pptr = ptr;
}
int pop(item** pptr)
{
	item* tmp;
	int x;
	if (*pptr == NULL)
	{
		printf("Stack is empty\n");
		exit(1);
	}
	tmp = *pptr;
	x = tmp->data;
	*pptr = tmp->next;
	free(tmp);
	return x;
}

