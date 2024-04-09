#include "monty.h"
/**
 * f_pall - Displays the contents of the stack
 * @head: Pointer to the head of the stack
 * @counter: Unused parameter
 *
 * Description:
 * This function prints all elements stored in the stack, starting from
 * the top of the stack. If the stack is empty, no output is generated.
 */
void f_pall(stack_t **head, unsigned int counter)
{
        stack_t *h;
        /* Suppress unused parameter warning */
        (void)counter;

        h = *head;
        if (h == NULL)
                return;
        while (h)
        {
                printf("%d\n", h->n);
                h = h->next;
        }
}

