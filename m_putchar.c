#include "main.h"
/**
 * m_putchar - prints the char at the top of the stack,
 * followed by a new line
 * @hd: stack head
 * @c: line_number
 * Return: no return
*/
void m_putchar(stack_t **hd, unsigned int c)
{
	stack_t *h;

	h = *hd;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", c);
		fclose(bus.file);
		free(bus.content);
		f_stack(*hd);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", c);
		fclose(bus.file);
		free(bus.content);
		f_stack(*hd);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}
