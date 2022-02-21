/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:37:39 by ialvarez          #+#    #+#             */
/*   Updated: 2022/02/21 20:58:59 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*order(int *save, int size)
{
	int	i;
	int	j;
	int	aux;

	i = -1;
	while (++i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (save[i] > save[j])
			{
				aux = save[i];
				save[i] = save[j];
				save[j] = aux;
			}
			j++;
		}
	}
	return (save);
}

static t_list	**re_do(t_list **a, int *before, int *save, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (before[i] == save[j])
			{
				before[i] = j;
				break ;
			}
		}
	}
	ft_lstclear(a, free);
	i = -1;
	while (++i < size)
		ft_lstadd_back(a, ft_add_number(before[i]));
	free(save);
	free(before);
	return (a);
}

void	simple(t_list **a)
{
	t_list	*aux;
	int		*save;
	int		*before;
	int		i;

	aux = *a;
	save = malloc(ft_lstsize(*a) * sizeof(int));
	if (!save)
		exit (0);
	before = malloc(ft_lstsize(*a) * sizeof(int));
	if (!before)
	{
		free(save);
		exit(0);
	}
	i = -1;
	while (++i < ft_lstsize(*a))
	{
		save[i] = *(int *)aux->content;
		aux = aux->next;
	}
	ft_memcpy(before, save, ft_lstsize(*a) * sizeof(int));
	order(save, ft_lstsize(*a));
	re_do(a, before, save, ft_lstsize(*a));
}

void	big_hundred(t_list **a, t_list **b)
{
	int	i;
	int	j;
	int	by;
	int	size;

	by = 0;
	size = ft_lstsize(*a);
	while ((size - 1) >> by != 0)
		by++;
	i = -1;
	while (++i < by)
	{
		j = -1;
		while (++j < size)
		{
			if (is_sorted(*a) == 0)
				break ;
			if (((*(int *)(*a)->content >> i) & 1) == 1)
				r_action(a, b, 'a');
			else
				push_to(a, b, 'b');
		}
		while (*b)
			push_to(a, b, 'a');
	}
}
