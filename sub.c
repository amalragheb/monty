#include "monty.h"
/**
 * sub - .
 * @stack: Pointer to the stack
 * @line_number: Line number of the current operation
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
	fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
	clear();
	exit(EXIT_FAILURE);
	}

	if ((*stack)->next)
	{
		(*stack)->next->n -= (*stack)->n;
		delete_top_node(stack);
	}
	else
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		clear();
		exit(EXIT_FAILURE);
	}
}
