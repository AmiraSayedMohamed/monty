#include "main.h"
/**
 * m_div - divides the top two elements of the stack.
 * @hd: stack head
 * @c: line_number
 * Return: no return
*/
void m_div(stack_t **hd, unsigned int c)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", c);
		fclose(bus.file);
		free(bus.content);
		free_stack(*hd);
		exit(EXIT_FAILURE);
	}
	h = *hd;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", c);
		fclose(bus.file);
		free(bus.content);
		free_stack(*hd);
		exit(EXIT_FAILURE);
	}
	ax = h->next->n / h->n;
	h->next->n = ax;
	*hd = h->next;
	free(h);
}
