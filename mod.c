#include "monty.h"

/**
 * mod - .
 * @stack: Pointer to the stack
 * @line_number: Line number of the current operation
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		clear();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->next)
	{
		if ((*stack)->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			clear();
			exit(EXIT_FAILURE);
		}

		(*stack)->next->n %= (*stack)->n;
		delete_top_node(stack);
	}
	else
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		clear();
		exit(EXIT_FAILURE);
	}
}
