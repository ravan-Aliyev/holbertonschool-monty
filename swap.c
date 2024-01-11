#include "monty.h"

/**
 * swap - swap elements in stack
 * @stack: head of stack
 * @line_number: command occurred in file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);		
		exit(EXIT_FAILURE);
	}

	int tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}
