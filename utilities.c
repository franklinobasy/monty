#include "monty.h"

/**
 * NewNode - Create a new node for the stack
 *
 * @value: value to be assigned to the node
 *
 * Return: new node created
 */

stack_t *NewNode(int value)
{
        stack_t *new_node = NULL;

        new_node = (stack_t *)malloc(sizeof(stack_t));
        if (!new_node)
        {
                dprintf(STDERR_FILENO, "Error: malloc operation failed :(.\n");
                exit(EXIT_FAILURE);
        }

        new_node->n = value;
        new_node->next = NULL;
        new_node->next = NULL;

        return (new_node);
}

/**
 * isEMpty - checks if a stack is empty
 *
 * @stack: stack to check
 *
 * Return: 1 if true else 0
 */

int isEmpty(stack_t **stack)
{
        if (!(*stack))
                return (1);
        return (0);
}

/**
 * check_for_digit - checks that a string only contains digits
 * @arg: char to check
 *
 * Return: 0 if only digits, else 1
 */
int check_for_digit(char *arg)
{
	int i;

	for (i = 0; arg[i]; i++)
	{
		if (arg[i] == '-' && i == 0)
			continue;
		if (isdigit(arg[i]) == 0)
			return (1);
	}
	return (0);
}
