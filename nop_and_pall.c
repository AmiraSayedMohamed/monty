#include "main.h"
/**
  *m_nop- nothing
  *@hd: stack head
  *@c: line_number
  *Return: no return
 */
void m_nop(stack_t **hd, unsigned int c)
{
	(void) counter;
	(void) head;
}

/**
 * m_pall - prints the stack
 * @hd: stack head
 * @c: no used
 * Return: no return
*/
void m_pall(stack_t **hd, unsigned int c)
{
	stack_t *h;
	(void)c;

	h = *hd;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
