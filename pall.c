#include "monty.h"

/**
 * pall - Prints all elements in the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the current operation
 */
void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	print_dlistint(*stack);
}
