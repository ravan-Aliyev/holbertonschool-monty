#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 *
 * @stack: point stack
 * @line_number: line numb
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		printf("L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
