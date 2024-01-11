#include "monty.h"
/**
 * monty_push - execute monty push function.
 * @opcode: operation code.
 * @stack: satck.
 * @line_number: number of line.
 */
void monty_push(char *opcode, stack_t **stack, unsigned int line_number)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (opcode != NULL && check_num(opcode) == 1)
	{
		new->n = atoi(opcode);
		new->next = *stack;
		new->prev = NULL;

		if (*stack != NULL)
			(*stack)->prev = new;
		*stack = new;
	}
	else
	{
		fprintf(stderr, "L%d: usege: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * monty_pall - execute monty pull function.
 * @stack: stack.
 * @line_number: number of line
 */
void monty_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *cur = *stack;

	(void)line_number;
	while (cur)
	{
		printf("%d\n", cur->n);
		cur = cur->next;
	}
}
