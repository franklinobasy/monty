#include "monty.h"

/**
 * push_error - handle push error
 *
 * @fd: is a file desciptor
 * @line: is a buffer
 * @stack: is a stack or queue
 * @count: is a line command
 *
 * Return: void
 */
void push_failure(FILE *fd, char *line, stack_t *stack, int count)
{
	dprintf(STDERR_FILENO, "L%u: usage: push integer\n", count);
	fclose(fd);
	free(line);
	free_stack(stack);
	exit(EXIT_FAILURE);
}

/**
 * unknown_command - Error handler
 * @fd: is a file descriptor
 * @line: is a buffer
 * @stack: is a stack or queue
 * @count: is a line command
 * @item: number
 */
void unknown_command(FILE *fd, char *line, stack_t *stack, char *count, int item)
{
	dprintf(STDERR_FILENO, "L%u: unknown command %s\n", item, count);
	fclose(fd);
	free(line);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
