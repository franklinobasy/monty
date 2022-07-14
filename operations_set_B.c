#include "monty.h"

/**
 * _swap - swaps the top two elements of the stack.
 * @stack: Stack
 * @line_number: Number of the line
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int temp_val = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp_val = current->n;
	current->n = current->next->n;
	current->next->n = temp_val;
}