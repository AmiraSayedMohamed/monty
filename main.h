#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;
extern bus_t bus;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* add.c */
void _add_(stack_t **hd, unsigned int c);
/* add_node */
void _add_node(stack_t **hd, int x);
/* _div.c */
void m_div(stack_t **hd, unsigned int c);
/* _excute.cm*/
int _execute(char *contnt, stack_t **stk, unsigned int c, FILE *f);
/* f_stack.c */
void f_stack(stack_t *hd);
/* _mod.c */
void m_mod(stack_t **hd, unsigned int c);
/* _mul.c */
void m_mul(stack_t **hd, unsigned int c);
/* _nop.c */
void m_nop(stack_t **hd, unsigned int c);
void m_pall(stack_t **hd, unsigned int c);
/* m_putchar.c */
void m_putchar(stack_t **hd, unsigned int c);
/* pint_and_pop.c */
void m_pop(stack_t **hd, unsigned int c);
void m_pint(stack_t **hd, unsigned int c);
/* pstr_and_push.c */
void m_push(stack_t **hd, unsigned int c);
void m_pstr(stack_t **hd, unsigned int c);
/* _queue.c */
void m_queue(stack_t **hd, unsigned int c);
void _add_queue(stack_t **hd, int n);
/* rotl_rotr_stack_sub_swap.c */
void m_rotl(stack_t **hd,  __attribute__((unused)) unsigned int c);
void m_rotr(stack_t **hd, __attribute__((unused)) unsigned int c);
void m_stack(stack_t **hd, unsigned int c);
void m_sub(stack_t **hd, unsigned int c);
void m_swap(stack_t **hd, unsigned int c);
#endif /* MAIN_H */
