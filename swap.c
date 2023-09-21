#include "monty.h"
/**
 * swap - Swaps the positions of the top two elements in the stack.
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the current operation
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int tp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		clear();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next)
	{
		tp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = tp;
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		clear();
		exit(EXIT_FAILURE);
	}
}
