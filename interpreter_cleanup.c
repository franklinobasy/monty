#include "monty.h"

/**
 * free_stack - frees the stack on exit
 * @status: exit status
 * @arg: double pointer to the stack
 *
 * Return: void
 */
void free_stack(int status, void *arg)
{
	stack_t *current = NULL;

        (void)status;
        current = (stack_t *)arg;

        if (current != NULL)
	{
		free_dlistint(current->next);
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
void fs_close(int status, void *arg)
{
	FILE *fs;

	(void)status;

	fs = (FILE *) arg;
	fclose(fs);
}