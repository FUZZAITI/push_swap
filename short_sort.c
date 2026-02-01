/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepinhei <pepinhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 01:56:18 by pepinhei          #+#    #+#             */
/*   Updated: 2026/02/01 03:02:24 by pepinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_2(t_stack **a);
void sort_3(t_stack **a);
void sort_4(t_stack **a, t_stack **b);
void sort_5(t_stack **a, t_stack **b);
void push_min_to_b(t_stack **a, t_stack **b, int size);


void sort_2(t_stack **a)
{
    if ((*a)->value > (*a)->next->value)
        sa(a);
}

void sort_3(t_stack **a)
{
    int top = (*a)->value;
    int mid = (*a)->next->value;
    int bot = (*a)->next->next->value;

    if (top > mid && mid < bot && top < bot)
        sa(a);               
    else if (top > mid && mid > bot)
    {
        sa(a);
        rra(a);              
    }
    else if (top > mid && mid < bot && top > bot)
        ra(a);               
    else if (top < mid && mid > bot && top < bot)
    {
        sa(a);
        ra(a);               
    }
    else if (top < mid && mid > bot && top > bot)
        rra(a);             
}

void sort_4(t_stack **a, t_stack **b)
{
    push_min_to_b(a, b, 4);
    sort_3(a);
    pa(a, b);
}

void sort_5(t_stack **a, t_stack **b)
{
    push_min_to_b(a, b, 5);
    push_min_to_b(a, b, 4);
    sort_3(a);
    pa(a, b);
    pa(a, b);
}

void push_min_to_b(t_stack **a, t_stack **b, int size)
{
    int min;
    t_stack *tmp;
    int i;
    int pos;

    pos = 0; 
    tmp = *a;
    min = tmp->value;
    i = 0;
    while (tmp)
    {
        if (tmp->value < min)
        {
            min = tmp->value;
            pos = i;
        }
        tmp = tmp->next;
        i++;
    }
    while ((*a)->value != min)
    {
        if (pos < size / 2)
            ra(a);
        else
            rra(a);
    }
    pb(a, b);
}
