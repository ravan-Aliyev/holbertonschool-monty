#include "monty.h"
/**
 * check_num - checking number.
 * @opcode: string to check.
 * Return: 1 if true, 0 if false
 */
int check_num(char *opcode)
{
	unsigned int i = 0;

	if (opcode == NULL)
		return (0);

	while (opcode[i] != '\0')
	{
		if (opcode[0] == '-')
		{
			i++;
			continue;
		}
		if (!isdigit(opcode[i]))
			return (0);
		i++;
	}

	return (1);
}
/**
 * free_stack - freeeing stack.
 * @stack: stack.
 */
void free_stack(stack_t *stack)
{
	stack_t *cur;

	while (stack)
	{
		cur = stack->next;
		free(stack);
		stack = cur;
	}
}
