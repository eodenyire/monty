#include "monty.h"
/**
 * f_swap - swaps the top two elements of the stack
 * @head: pointer to the stack head
 * @counter: line_number
 * Description: The function swaps the values of the top two elements of
 * the stack. If the stack contains less than two elements, it prints an
 * error message and exits with EXIT_FAILURE.
 * Return: no return
 */
void f_swap(stack_t **head, unsigned int counter)
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

        /* Check if the stack contains less than two elements */
        if (len < 2)
        {
                fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
                fclose(bus.file);
                free(bus.content);
                free_stack(*head);
                exit(EXIT_FAILURE);
        }

        /* Swap the values of the top two elements */
        h = *head;
        aux = h->n;
        h->n = h->next->n;
        h->next->n = aux;
}
