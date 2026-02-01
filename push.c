/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepinhei <pepinhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 12:07:01 by pepinhei          #+#    #+#             */
/*   Updated: 2026/01/31 12:07:01 by pepinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*parse_args(int len, char **lista, int *size);
void short_sort(t_stack **a, t_stack **b, int size);

int	*parse_args(int len, char **lista, int *size)
{
	char	**nuns;
	int		is_split;

	is_split = 0;
	if (len == 2)
	{
		nuns = ft_split(lista[1], ' ');
		is_split = 1;
		if (!nuns || !nuns[0])
			management_error(1, nuns);
	}
	else
		nuns = lista + 1;
	if (!is_num(nuns))
		management_error(is_split, nuns);
	if (!is_valid(nuns))
		management_error(is_split, nuns);
	if (!has_duplicates(nuns))
		management_error(is_split, nuns);
	*size = count_nums(nuns);
	return (nrb_array(nuns, is_split));
}

int	*copy(int *array, int size)
{
	int	*copy_nbr;

	copy_nbr = copy_array(array, size);
	if (!copy_nbr)
		error_exit();
	sort_array(copy_nbr, size);
	return (copy_nbr);
}

int	main(int argc, char **argv)
{
	int		*array_nbr;
	int		*sorted;
	int		size;
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	array_nbr = parse_args(argc, argv, &size);
	sorted = copy(array_nbr, size);
	index_array(array_nbr, sorted, size);
	free(sorted);
	a = init_stack(array_nbr, size);
	b = NULL;
	free(array_nbr);
	if (!is_sorted(a))
	{
		if (size <= 5)
			short_sort(&a, &b, size);
		else
			radix_sort(&a, &b, size);
	}
	free_stack(&a);
}

void short_sort(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
		sort_2(a);
	else if (size == 3)
		sort_3(a);
	else if (size == 4)
		sort_4(a, b);
	else if (size == 5)
		sort_5(a, b);
}
//c3r8p5% ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' ');./push_swap $ARG | wc -l