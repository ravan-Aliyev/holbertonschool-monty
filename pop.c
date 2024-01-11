#include "monty.h"

/**
 * pop - remove an element from the stack
 *
 * @stack: pointer to the stack
 * @line_number: line number of the file
 *
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	free(temp);

	if (*stack)
		(*stack)->prev = NULL;
}
