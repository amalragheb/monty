#include "monty.h"
/**
 * exe_line - Executes a single line of operation
 * @line: Line of operation
 * @line_number: Line number of the current operation
 */
void exe_line(char *line, int line_number)
{
	int x;
	int is_instruction = -1;
	instruction_t ops[] = {
		{"push", push},
		{"pop", pop},
		{"pall", pall},
		{"pint", pint},
		{"swap", swap},
		{"nop", nop},
		{"sub", sub},
		{"div", div_},
		{"add", add},
		{"mul", mul},
		{"mod", mod},
		{"stack", stack},
		{"queue", queue},
	};
	data.arg1 = strtok(line, " \n");
	data.arg2 = strtok(NULL, " \n");
	if (data.arg1[0] == '#')
	{
		nop(&data.stack, line_number);
		return;
	}
	for (x = 0; x < INSTRUCTIONS_COUNT; x++)
		if (strcmp(data.arg1, ops[x].opcode) == 0)
		{

			is_instruction = x;
			break;
		}
	if (is_instruction != -1)
		ops[x].f(&data.stack, line_number);
	else
		{
	fprintf(stderr, "L%d: unknown instruction %s\n",
							line_number, data.arg1);
	clear();
	exit(EXIT_FAILURE);
		}
}
/**
 * is_line_empty - .
 * @line: Line to check
 *
 * Return: 1 if the line is empty, 0 otherwise
 */
int is_line_empty(char *line)
{
	int x;
	int len = strlen(line);

	if (len > 0)
	{
		if (line[len - 1] == '\n')
		{
			/*Check if the line contains any characters before '\n'*/
			for (x = 0; x < len - 1; x++)
			{
				if (line[x] != ' ')
					return (1);
			}
			return (0);
		}
	}

	return (0);
}
