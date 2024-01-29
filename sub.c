#include "monty.h"


/**
 * sub - subtracts the top element of the stack from the second top element
 * @stack: double pointer to the head of the stack
 * @line_number: line number being executed from script file
 *
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int sub = 0;

	if (!temp || !temp->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sub = temp->next->n - temp->n;
	pop(stack, line_number);
	(*stack)->n = sub;
}
