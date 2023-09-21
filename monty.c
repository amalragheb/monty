#include "monty.h"
data_t data = {0, NULL, NULL, NULL, NULL, NULL, STACK};
/**
 * main - Entry point for the Monty interpreter program
 * @argc: Number of arguments
 * @argv: Array of argument strings
 *
 * Return: 0 on success, -1 on failure
 */
int main(int argc, char **argv)
{
	FILE *file;
    char *file_name = argv[1];
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	
	if (argc != 2)
	{
        fprintf(stderr, "USAGE: monty file\n");
	    exit(EXIT_FAILURE);
    }
	
	file = fopen(file_name, "r");
	if (file == NULL)
	{
        fprintf(stderr, "Error: Can't open file %s\n", file_name);
	    exit(EXIT_FAILURE);
    }
	data.file = file;
	while ((read = getline(&line, &len, file)) != -1)
	{
		data.line_number++;
		data.line = line;
		if (is_line_empty(data.line) == 1)
			exe_line(data.line, data.line_number);
	}
	free_dlistint(data.stack);
	fclose(file);
	free(line);
	return (0);
}
