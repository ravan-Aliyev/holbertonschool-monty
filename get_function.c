#include "monty.h"
/**
 * get_function - get function according to the opcode.
 * @opcode: operation code.
 * @count: show us which line we are.
 * @stack: stack.
 */
void get_function(char *opcode, int count, stack_t **stack)
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
		monty_push(value, stack, count);
	}
	else
	{
		while (opcodes[i].opcode != NULL)
		{
			if (strcmp(opcodes[i].opcode, opcode) == 0)
			{
				opcodes[i].f(stack, count);
				return;
			}
			i++;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", count, opcode);
	exit(EXIT_FAILURE);
}
