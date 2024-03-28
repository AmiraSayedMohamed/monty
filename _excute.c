#include "main.h"
/**
* _execute - executes the opcode
* @stk: head linked list - stack
* @c: line_counter
* @f: poiner to monty file
* @contnt: line content
* Return: no return
*/
int _execute(char *contnt, stack_t **stk, unsigned int c, FILE *f)
{
	instruction_t opst[] = {
				{"push", m_push}, {"pall", m_pall}, {"pint", m_pint},
				{"pop", m_pop},
				{"swap", m_swap},
				{"add", m_add},
				{"nop", m_nop},
				{"sub", m_sub},
				{"div", m_div},
				{"mul", m_mul},
				{"mod", m_mod},
				{"pchar", m_putchar},
				{"pstr", m_pstr},
				{"rotl", m_rotl},
				{"rotr", m_rotr},
				{"queue", m_queue},
				{"stack", m_stack},
				{NULL, NULL}
				};
	unsigned int j = 0;
	char *op_;

	op_ = strtok(contnt, " \n\t");
	if (op_ && op_[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[j].opcode && op_)
	{
		if (strcmp(op_, opst[j].opcode) == 0)
		{	opst[j].f(stk, c);
			return (0);
		}
		j++;
	}
	if (op_ && opst[j].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", c, op_);
		fclose(f);
		free(contnt);
		f_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
