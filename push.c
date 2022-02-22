/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:55:17 by ialvarez          #+#    #+#             */
/*   Updated: 2022/02/22 19:25:16 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	aux_parse(char **argv, int i, int j)
{
	long	n;

	while (argv[i][j])
	{
		if ((argv[i][j] == '-' && ft_isdigit(argv[i][j + 1]))
				|| (argv[i][j] == '+' && ft_isdigit(argv[i][j + 1])))
			j++;
		else if (!ft_isdigit(argv[i][j]))
		{
			write(1, "Error\n", 6);
			exit (0);
		}
		j++;
	}
	n = ft_atoi(argv[i]);
	if (n < -2147483648 || n > 2147483647)
	{
		write(1, "Error\n", 6);
		exit (0);
	}
}

void	push(t_list **a, t_list **b)
{
	if (is_sorted(*a) == 0)
	{
		ft_lstclear(a, free);
		exit (0);
	}
	else if (ft_lstsize(*a) == 2)
		small_two(a, b);
	else if (ft_lstsize(*a) <= 5 && ft_lstsize(*a) >= 3)
		small_five(a, b);
	else
	{
		simple(a);
		big_hundred(a, b);
	}
}
