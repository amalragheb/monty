#include "monty.h"

/**
 * pop - Removes the top element from the stack.
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the current operation
 * Return: Nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	/* Check if the stack or the top element is empty */
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		clear();
		exit(EXIT_FAILURE);
	}
	delete_top_node(stack);
}
