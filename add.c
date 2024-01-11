#include "monty.h"

/**
 * add - adds top two elements of stack and makes it top
 *
 * @stack: pointer to top of the stack
 * @line_number: line number of instruction
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		dprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}
