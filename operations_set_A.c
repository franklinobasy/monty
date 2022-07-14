#include "monty.h"

int value;

/**
 * _push - inserts a node to a top of stack
 *
 * @stack: head of stack
 * @line_number: current line number
 * Return: void
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL;

	(void)line_number;
	new_node = NewNode(value);

	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * _pall - prints all element in a stack
 *
 * @stack: head of stack
 * @line_number: a value
 *
 * Return: void
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = (stack_t *)malloc(sizeof(stack_t));

	(void)line_number;
	if (!current)
	{
		dprintf(STDOUT_FILENO, "Error: malloc operation failed :(.\n");
		exit(EXIT_FAILURE);
	}

	current = *stack;
	while (current != NULL)
	{
		dprintf(STDOUT_FILENO, "%d\n", current->n);
		current = current->next;
	}
}
