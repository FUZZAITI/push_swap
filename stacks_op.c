#include "push_swap.h"


t_stack *init_stack(int *array, int size);
t_stack *stack_new(int value);
void stack_add_back(t_stack **stack, t_stack *new);
void free_stack(t_stack **stack);


t_stack *init_stack(int *array, int size)
{
    t_stack *a;
    int     i;

    a = NULL;
    i = 0;
    while (i < size)
    {
        stack_add_back(&a, stack_new(array[i]));
        i++;
    }
    return (a);
}


t_stack *stack_new(int value)
{
    t_stack *node;

    node = malloc(sizeof(t_stack));
    if (!node)
        return (NULL);
    node->value = value;
    node->next = NULL;
    return (node);
}

void stack_add_back(t_stack **stack, t_stack *new)
{
    t_stack *tmp;

    if (!stack || !new)
        return ;
    if (!*stack)
    {
        *stack = new;
        return ;
    }
    tmp = *stack;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
}

void free_stack(t_stack **stack)
{
    t_stack *tmp;

    if (!stack || !*stack)
        return ;
    while (*stack)
    {
        tmp = (*stack)->next;
        free(*stack);
        *stack = tmp;
    }
}