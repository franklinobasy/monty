#include "monty.h"

stack_t *stack_top = NULL;
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

        new_node = NewNode(value);

        if (isEmpty(stack) == 1)
        {
                *stack = new_node;
                stack_top = *stack;
        }
        else
        {
                new_node->prev = stack_top;
                stack_top->next = new_node;
                stack_top = new_node;
        }
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
                dprintf(STDERR_FILENO, "Error: malloc operation failed :(.\n");
                exit(EXIT_FAILURE);
        }

        current = *stack;
        while (current != NULL)
        {
                dprintf(STDOUT_FILENO, "%d\n", current->n);
		current = current->next;
	}
}
