#include "main.h"
/**
 * m_queue - prints the top
 * @hd: stack head
 * @c: line_number
 * Return: no return
*/
void m_queue(stack_t **hd, unsigned int c)
{
	(void)hd;
	(void)c;
	bus.lifi = 1;
}

/**
 * _add_queue - add node to the tail stack
 * @n: new_value
 * @hd: head of the stack
 * Return: no return
*/
void _add_queue(stack_t **hd, int n)
{
	stack_t *n_node, *ax;

	ax = *hd;
	n_node = malloc(sizeof(stack_t));
	if (n_node == NULL)
	{
		printf("Error\n");
	}
	n_node->n = n;
	n_node->next = NULL;
	if (ax)
	{
		while (ax->next)
			ax = ax->next;
	}
	if (!ax)
	{
		*hd = n_node;
		n_node->prev = NULL;
	}
	else
	{
		ax->next = n_node;
		n_node->prev = ax;
	}
}
