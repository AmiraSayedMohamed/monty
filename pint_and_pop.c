#include "main.h"
/**
 * m_pint - prints the top
 * @hd: stack head
 * @c: line_number
 * Return: no return
*/
void m_pint(stack_t **hd, unsigned int c)
{
	if (*hd == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", c);
		fclose(bus.file);
		free(bus.content);
		f_stack(*hd);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*hd)->n);
}

/**
 * m_pop - prints the top
 * @hd: stack head
 * @c: line_number
 * Return: no return
*/
void m_pop(stack_t **hd, unsigned int c)
{
	stack_t *h;

	if (*hd == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", c);
		fclose(bus.file);
		free(bus.content);
		f_stack(*hd);
		exit(EXIT_FAILURE);
	}
	h = *hd;
	*hd = h->next;
	free(h);
}
