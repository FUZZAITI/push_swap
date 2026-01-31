/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepinhei <pepinhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 12:17:32 by pepinhei          #+#    #+#             */
/*   Updated: 2026/01/31 12:17:32 by pepinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include  <stdlib.h>
# include  <unistd.h>
# include  <limits.h>
# include  <stdio.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

char		**ft_split(const char *s, char c);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlen(const char *s);

long		ft_atol(const char *str);

int			*parse_args(int len, char **lista, int *size);
int			is_num(char **s);
int			is_valid(char **list);
int			has_duplicates(char **nums);

void		error_exit(void);
void		management_error(int i, char **s);
void		free_list(char **lista);

int			*nrb_array(char **list, int is_split);
int			*copy_array(int *arr, int size);
int			count_nums(char **nums);
void		sort_array(int *arr, int size);
void		index_array(int *ori, int *sorted, int size);

int			max_bits(int size);
void		radix_sort(t_stack **a, t_stack **b, int size);

t_stack		*init_stack(int *array, int size);
t_stack		*stack_new(int value);
void		stack_add_back(t_stack **stack, t_stack *new);
void		free_stack(t_stack **stack);

void		sa(t_stack **a);
void		sb(t_stack **b);
void		ss(t_stack **a, t_stack **b);
void		swap(t_stack **stack);

void		push(t_stack **from, t_stack **to);
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **a, t_stack **b);

void		rotate(t_stack **stack);
void		ra(t_stack **a);
void		rb(t_stack **b);
void		rr(t_stack **a, t_stack **b);

void		reverse_rotate(t_stack **stack);
void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);
#endif
