#include "main.h"
/**
 * m_pstr - prints the string starting at the top of the stack,
 * followed by a new
 * @hd: stack head
 * @c: line_number
 * Return: no return
*/
void m_pstr(stack_t **hd, unsigned int c)
{
	stack_t *h;
	(void)c;

	h = *hd;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}

/**
 * m_push - add node to the stack
 * @hd: stack head
 * @c: line_number
 * Return: no return
*/
void m_push(stack_t **hd, unsigned int c)
{
	int x, i = 0, flg = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			i++;
		for (; bus.arg[i] != '\0'; i++)
		{
			if (bus.arg[i] > 57 || bus.arg[i] < 48)
				flg = 1; }
		if (flg == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", c);
			fclose(bus.file);
			free(bus.content);
			f_stack(*hd);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", c);
		fclose(bus.file);
		free(bus.content);
		f_stack(*hd);
		exit(EXIT_FAILURE); }
	x = atoi(bus.arg);
	if (bus.lifi == 0)
		_add_node(hd, x);
	else
		_add_queue(hd, x);
}
