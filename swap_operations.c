#include "push_swap.h"

void sa(t_stack **a);
void sb(t_stack **b);
void ss(t_stack **a, t_stack **b);
void swap(t_stack **stack);


void sa(t_stack **a)
{
    swap(a);
    write(1, "sa\n", 3);
}

void sb(t_stack **b)
{
    swap(b);
    write(1, "sb\n", 3);
}

void ss(t_stack **a, t_stack **b)
{
    swap(a);
    swap(b);
    write(1, "ss\n", 3);
}

void swap(t_stack **stack)
{
    t_stack *tmp;

    if (!stack || !*stack || !(*stack)->next)
        return ;
    tmp = (*stack)->next;
    (*stack)->next = tmp->next;
    tmp->next = *stack;
    *stack = tmp;
}

