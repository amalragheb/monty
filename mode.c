#include "monty.h"

/**
 * stack - .
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the current operation
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	data.mod = STACK;
}


/**
 * queue - .
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the current operation
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	data.mod = QUEUE;
}
