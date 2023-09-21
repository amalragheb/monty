#include "monty.h"

/**
 * pint - Prints the value of the top element in the stack.
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the current operation
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		clear();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
