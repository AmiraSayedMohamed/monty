#include "main.h"
/**
* f_stack - frees a doubly linked list
* @hd: head of the stack
*/
void f_stack(stack_t *hd)
{
	stack_t *ax;

	ax = hd;
	while (head)
	{
		ax = hd->next;
		free(hd);
		hd = ax;
	}
}
