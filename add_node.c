#include "main.h"
/**
 * _add_node - add node to the head stack
 * @hd: head of the stack
 * @x: new_value
 * Return: no return
*/
void _add_node(stack_t **hd, int n)
{

	stack_t *n_node, *ax;

	ax = *hd;
	n_node = malloc(sizeof(stack_t));
	if (n_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (ax)
		ax->prev = n_node;
	n_node->n  = n;
	n_node->next = *hd;
	n_node->prev = NULL;
	*hd = n_node;
}
