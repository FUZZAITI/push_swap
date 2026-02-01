/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepinhei <pepinhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 12:09:35 by pepinhei          #+#    #+#             */
/*   Updated: 2026/01/31 12:09:35 by pepinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		max_bits(int size);
void	radix_sort(t_stack **a, t_stack **b, int size);
int		is_sorted(t_stack *a);

int	max_bits(int size)
{
	int	bits;

	bits = 0;
	size--;
	while ((size >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_stack **a, t_stack **b, int size)
{
	int	j;
	int	bit;
	int	value;
	int	max;

	max = max_bits(size);
	bit = 0;
	while (bit < max)
	{
		j = 0;
		while (j < size)
		{
			value = (*a)->value;
			if (((value >> bit) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			j++;
		}
		while (*b)
			pa(a, b);
		bit++;
	}
}

int is_sorted(t_stack *a)
{
    while (a && a->next)
    {
        if (a->value > a->next->value)
            return (0);
        a = a->next;
    }
    return (1);
}
