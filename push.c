#include "monty.h"

/**
 * f_push - Adds a node to the stack or queue.
 * @head: Pointer to the head of the stack or queue.
 * @counter: Line number in the Monty bytecode file.
 */
void f_push(stack_t **head, unsigned int counter)
{
    int n, j = 0;
    char *arg = bus.arg;

    if (arg == NULL)
    {
        fprintf(stderr, "L%d: usage: push integer\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    if (arg[0] == '-')
        j++;

    for (; arg[j] != '\0'; j++)
    {
        if (arg[j] < '0' || arg[j] > '9')
        {
            fprintf(stderr, "L%d: usage: push integer\n", counter);
            fclose(bus.file);
            free(bus.content);
            free_stack(*head);
            exit(EXIT_FAILURE);
        }
    }

    n = atoi(arg);

    if (bus.lifi == 0)
        addnode(head, n);
    else
        addqueue(head, n);
}
