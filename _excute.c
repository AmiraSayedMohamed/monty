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
				{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
				{"pop", f_pop},
				{"swap", f_swap},
				{"add", f_add},
				{"nop", f_nop},
				{"sub", f_sub},
				{"div", f_div},
				{"mul", f_mul},
				{"mod", f_mod},
				{"pchar", f_pchar},
				{"pstr", f_pstr},
				{"rotl", f_rotl},
				{"rotr", f_rotr},
				{"queue", f_queue},
				{"stack", f_stack},
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
		{	opst[j].f(stack, c);
			return (0);
		}
		j++;
	}
	if (op_ && opst[j].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", c, op_);
		fclose(file);
		free(contnt);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
