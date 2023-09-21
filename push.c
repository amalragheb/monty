#include "monty.h"

/**
 * push - Pushes an element onto the stack.
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the current operation
 */
void push(stack_t **stack, unsigned int line_number)
{
	int n = 0;

	if (data.arg2)
	{
		if (is_int(data.arg2))
		{
			n = atoi(data.arg2);
			if (data.mod == STACK)
				add_dnodeint(stack, n);
			else
				add_dnodeint_end(stack, n);
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			clear();
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		clear();
		exit(EXIT_FAILURE);
	}
}

/**
 * is_int - Checks if a string represents a valid integer
 * @num: The string to check
 *
 * Return: 1 if the string is a valid integer, 0 otherwise
 */
int is_int(char *num)
{
	int x = 0;

	if (num[x] == '-')
		x++;

	while (num[x])
	{
		if (!(num[x] >= '0' && num[x] <= '9'))
			return (0); /* Not a number */
		x++;
	}

	return (1); /* It's a number */
}
/**
 * clear - .
 */
void clear(void)
{
	free_dlistint(data.stack);
	fclose(data.file);
	free(data.line);
}
