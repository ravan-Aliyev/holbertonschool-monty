#include "monty.h"
/**
 * get_function - get function according to the opcode.
 * @opcode: operation code.
 * @count: show us which line we are.
 * @fd: file direction.
 * @line: line.
 * @stack: stack.
 */
void get_function(FILE *fd, char *opcode, int count,
		stack_t **stack, char *line)
{
	int i = 0;
	char *value = NULL;
	instruction_t opcodes[] = {
		{"pall", monty_pall},
		{NULL, NULL},
	};

	if (strcmp(opcode, "push") == 0)
	{
		value = strtok(NULL, " \n\t\r");
		if (value == NULL
		    || check_num(value) != 0)
		{
			fclose(fd);
			free_stack(*stack);
			free(line);
			fprintf(stderr, "L%d usage: push integer", count);
			exit(EXIT_FAILURE);
		}
		monty_push(value, stack, count);
	}
	else
	{
		while (opcodes[i].opcode != NULL)
		{
			if (strcmp(opcodes[i].opcode, opcode) == 0)
			{
				opcodes[i].f(stack, count);
				break;
			}
			i++;
		}
	}
	if (opcodes[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", count, opcode);
		free_stack(*stack);
		free(line);
		fclose(fd);
		exit(EXIT_FAILURE);
	}
}
