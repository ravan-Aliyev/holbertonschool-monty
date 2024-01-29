#include "monty.h"
/**
 * sub_list - subtracts the top element of the stack from the second top
 * @stack: pointer to the head of the list
 * @line_number: line number of instruction
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *next;

	if (!current || !current->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	next = current->next;
	next->n -= current->n;
	pop(stack, line_number);
}
