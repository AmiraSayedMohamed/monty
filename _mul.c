#include "main.h"
/**
 * m_mul - multiplies the top two elements of the stack.
 * @hd: stack head
 * @c: line_number
 * Return: no return
*/
void m_mul(stack_t **hd, unsigned int c)
{
	stack_t *h;
	int ln = 0, ax;

	h = *hd;
	while (h)
	{
		h = h->next;
		ln++;
	}
	if (ln < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", c);
		fclose(bus.file);
		free(bus.content);
		f_stack(*hd);
		exit(EXIT_FAILURE);
	}
	h = *hd;
	ax = h->next->n * h->n;
	h->next->n = ax;
	*hd = h->next;
	free(h);
}
