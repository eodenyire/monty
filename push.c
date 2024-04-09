#include "monty.h"

/**
 * f_push - Function to add a node to the stack.
 * @head: Pointer to the head of the stack.
 * @counter: Line number in the Monty byte code file.
 *
 * Return: No return value.
 */
void f_push(stack_t **head, unsigned int counter)
{
        int n, j = 0, flag = 0;

        /* Check if the argument is provided */
        if (bus.arg)
        {
                /* Handle negative numbers */
                if (bus.arg[0] == '-')
                        j++;

                /* Check if the argument is a valid integer */
                for (; bus.arg[j] != '\0'; j++)
                {
                        if (bus.arg[j] > 57 || bus.arg[j] < 48)
                                flag = 1;
                }

                /* Print error message if the argument is not an integer */
                if (flag == 1)
                {
                        fprintf(stderr, "L%d: usage: push integer\n", counter);
                        fclose(bus.file);
                        free(bus.content);
                        free_stack(*head);
                        exit(EXIT_FAILURE);
                }
        }
        else
        {
                /* Print error message if no argument is provided */
                fprintf(stderr, "L%d: usage: push integer\n", counter);
                fclose(bus.file);
                free(bus.content);
                free_stack(*head);
                exit(EXIT_FAILURE);
        }

        /* Convert the argument to an integer */
        n = atoi(bus.arg);

        /* Add node to the stack or queue based on lifo flag */
        if (bus.lifo == 0)
                addnode(head, n);
        else
                addqueue(head, n);
}

