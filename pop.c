#include "monty.h"

/**
 * f_pop - Removes the top element of the stack
 * @head: Pointer to the head of the stack
 * @counter: Line number
 * Return: No return value
 */
void f_pop(stack_t **head, unsigned int counter)
{
        stack_t *h;

        /* Check if the stack is empty */
        if (*head == NULL)
        {
                /* Print error message if stack is empty */
                fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
                fclose(bus.file);
                free(bus.content);
                free_stack(*head);
                exit(EXIT_FAILURE);
        }

        /* Remove the top element */
        h = *head;
        *head = h->next;
        free(h);
}

