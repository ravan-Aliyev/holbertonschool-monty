#include "main.h"
/**
 * main - execute monty code.
 * @ac: argument counter.
 * @av: argument vector.
 *
 * Return: 0.
 */
int main(int ac, char **av)
{
	char *line, *opcode;
	size_t n;
	int count = 0;

	if (ac != 2)
	{
		fprintf(sterr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(av[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, Can't open file %s, av[1]);
		exit(EXIT_FALIURE);
	}
	while (getline(&line, &n, fd) != -1)
	{
		count++;
		opcode = strtok(line, " \n\t");
		if (opcode == NULL)
			continue;
		get_function(opcode, count, line);
	}

	fclose(fd);
	free(line);
	return (0);
}
