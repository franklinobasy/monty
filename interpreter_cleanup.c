#include "monty.h"

/**
 * free_stack - frees the stack on exit
 * @status: exit status
 * @arg: double pointer to the stack
 *
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *current = NULL;

	current = stack;

	if (current != NULL)
	{
		free_stack(current->next);
		free(current);
	}
}

/**
 * fs_close - close file stream
 * @status: status passed to exit
 * @arg: pointer to file stream
 *
 * Return: void
 */
void fs_close(void *arg)
{
	FILE *fs;


	fs = (FILE *) arg;
	fclose(fs);
}

/**
 * free_lineptr - free line pointer returned by getline
 * @status: exit status
 * @arg: pointer to line
 *
 * Return: void
 */
void free_lineptr(void *arg)
{
	char **lineptr = arg;

	if (*lineptr != NULL)
		free(*lineptr);
}