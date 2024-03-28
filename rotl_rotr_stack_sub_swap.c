#include "main.h"
/**
  *m_rotl- rotates the stack to the top
  *@hd: stack head
  *@c: line_number
  *Return: no return
 */
void m_rotl(stack_t **hd,  __attribute__((unused)) unsigned int c)
{
	stack_t *tmp = *hd, *ax;

	if (*hd == NULL || (*hd)->next == NULL)
	{
		return;
	}
	ax = (*hd)->next;
	ax->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *hd;
	(*hd)->next = NULL;
	(*hd)->prev = tmp;
	(*hd) = ax;
}

/**
  *m_rotr- rotates the stack to the bottom
  *@hd: stack head
  *@c: line_number
  *Return: no return
 */
void m_rotr(stack_t **hd, __attribute__((unused)) unsigned int c)
{
	stack_t *copy;

	copy = *hd;
	if (*hd == NULL || (*hd)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *hd;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*hd)->prev = copy;
	(*hd) = copy;
}

/**
 * m_stack - prints the top
 * @hd: stack head
 * @c: line_number
 * Return: no return
*/
void m_stack(stack_t **hd, unsigned int c)
{
	(void)hd;
	(void)c;
	bus.lifi = 0;
}

/**
  *m_sub- sustration
  *@hd: stack head
  *@c: line_number
  *Return: no return
 */
void m_sub(stack_t **hd, unsigned int c)
{
	stack_t *ax;
	int sus, nodes;

	ax = *hd;
	for (nodes = 0; ax != NULL; nodes++)
		ax = ax->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", c);
		fclose(bus.file);
		free(bus.content);
		f_stack(*hd);
		exit(EXIT_FAILURE);
	}
	ax = *hd;
	sus = ax->next->n - ax->n;
	ax->next->n = sus;
	*hd = ax->next;
	free(ax);
}
/**
 * m_swap - adds the top two elements of the stack.
 * @hd: stack head
 * @c: line_number
 * Return: no return
*/
void m_swap(stack_t **hd, unsigned int c)
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
		fprintf(stderr, "L%d: can't swap, stack too short\n", c);
		fclose(bus.file);
		free(bus.content);
		f_stack(*hd);
		exit(EXIT_FAILURE);
	}
	h = *hd;
	ax = h->n;
	h->n = h->next->n;
	h->next->n = ax;
}
