#include "monty.h"

/**
 * get_op - check op against accepted opcodes
 * @stack: double pointer to the beginnig of the stack
 * @op: op to check
 * @line_number: script line number
 *
 * Return: void
 */

void get_op(stack_t **stack, char *op, unsigned int line_number)
{
        size_t idx;
        instruction_t opcodes[] = {
                {"push", _push},
                {"pall", _pall},
                {NULL, NULL}
        };

        while (opcodes[idx].opcode != NULL)
        {
                if (strcmp(opcodes[idx].opcode, op) == 0)
                {
                        opcodes[idx].f(stack, line_number);
                        return;
                }
                idx++;
        }

        dprintf(STDOUT_FILENO,
		"L%u: unknown instruction %s\n",
		line_number, op);
	exit(EXIT_FAILURE);
}
