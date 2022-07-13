#include "monty.h"

/**
 * main - Start interpreter
 *
 * @argc: args counter
 * @argv: args variable
 *
 * Return: int
 */

int main(int argc, char *argv[])
{
        stack_t *stack = NULL;
        unsigned int line_number = 0;
        FILE *fs = NULL;
        char *lineptr = NULL, *op = NULL;
        size_t n = 0;

        if (argc != 2)
        {
                dprintf(STDOUT_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
        fs = fopen(argv[1], "r");
        if (!fs)
        {
                dprintf(STDOUT_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
        }
        on_exit(free_lineptr, &lineptr);
        on_exit(free_stack, &stack);
        on_exit(fs_close, fs);

        while (getline(&lineptr, &n, fs) != -1)
        {
                line_number++;
                op = strtok(lineptr, "\n\t\r ");
                if (op != NULL && op[0] != '#')
                {
                        get_op(&stack, op, line_number);
                }
        }
        exit(EXIT_SUCCESS);
}