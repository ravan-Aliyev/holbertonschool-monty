#include "monty.h"
/**
 * main - execute monty code.
 * @ac: argument counter.
 * @av: argument vector.
 *
 * Return: 0.
 */
int main(int ac, char **av)
{
	FILE *fd;
	stack_t *stack = NULL;
	char *line = NULL, *opcode;
	size_t n = 0;
	int count = 0;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(av[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &n, fd) != -1)
	{
		count++;
		opcode = strtok(line, " \n\t");
		if (opcode == NULL)
			continue;
		get_function(fd, opcode, count, &stack);
	}

	fclose(fd);
	free_stack(stack);
	free(line);
	return (0);
}
