#include "monty.h"
/**
 * f_add - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_add(stack_t **head, unsigned int counter)
{
        stack_t *h;
        int len = 0, aux;

        /* Count the number of elements in the stack */
        h = *head;
        while (h)
        {
                h = h->next;
                len++;
        }

        /* Check if there are at least two elements in the stack */
        if (len < 2)
        {
                fprintf(stderr, "L%d: can't add, stack too short\n", counter);
                fclose(bus.file);
                free(bus.content);
                free_stack(*head);
                exit(EXIT_FAILURE);
        }

        /* Perform addition of the top two elements */
        h = *head;
        aux = h->n + h->next->n;
        h->next->n = aux;
        *head = h->next;

        /* Remove the previous top element from the stack */
        free(h);
}

