#include "main.h"
/**
 * get_function - get function according to the opcode.
 * @opcode: operation code.
 * @count: show us which line we are.
 * @stack: stack.
 */
void get_function(char *opcode, int count, stack_t **stack)
{
	int i = 0;
	instruction_t opcodes[] = {
		{"pall", monty_pall},
		{NULL, NULL},
	};

	if (strcmp(opcode, "push") == 0)
		monty_push(strtok(NULL, " \n\t\r"), stack, count);
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
		exit(EXIT_FAILURE);
	}
}
