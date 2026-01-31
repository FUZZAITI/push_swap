/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepinhei <pepinhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 12:01:25 by pepinhei          #+#    #+#             */
/*   Updated: 2026/01/31 12:01:25 by pepinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void);
void	free_list(char **lista);
void	management_error(int i, char **s);

void	management_error(int i, char **s)
{
	if (i)
		free_list(s);
	error_exit ();
}

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_list(char **list)
{
	int	i;

	i = 0;
	if (list)
	{
		while (list[i])
		{
			free(list[i]);
			i++;
		}
		free(list);
	}
}
