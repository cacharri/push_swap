/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:10:08 by ialvarez          #+#    #+#             */
/*   Updated: 2022/02/21 20:20:44 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_two(t_list **a, t_list **b)
{
	t_list	*aux;
	int		i;
	int		j;

	aux = *a;
	i = *(int *)aux->content;
	j = *(int *)aux->next->content;
	if (i > j)
		swap(a, b, 'a');
}

void	small(t_list **a, t_list **b)
{
	int		i;
	int		j;
	int		k;

	i = *(int *)(*a)->content;
	j = *(int *)(*a)->next->content;
	k = *(int *)(*a)->next->next->content;
	if (is_sorted(*a) == 0)
		return ;
	if (k > i && k > j)
		swap(a, b, 'a');
	else if (i < j && i > k)
		rr_action(a, b, 'a');
	else if (k > i && j > k)
	{
		swap(a, b, 'a');
		r_action(a, b, 'a');
	}
	else if (i > k && k > j)
		r_action(a, b, 'a');
	else if (i > j && j > k)
	{
		swap(a, b, 'a');
		rr_action(a, b, 'a');
	}
}

void	find_small(t_list **a, t_list **b)
{
	int	i;
	int	k;

	i = *(int *)(*b)->content;
	k = *(int *)(*a)->next->content;
	if (i > *(int *)(*a)->next->next->content)
	{
		push_to(a, b, 'a');
		r_action(a, b, 'a');
	}
	else if (i > k && i < *(int *)(*a)->next->next->content)
	{
		rr_action(a, b, 'a');
		push_to(a, b, 'a');
		r_action(a, b, 'a');
		r_action(a, b, 'a');
	}
	else if (i < k && i > *(int *)(*a)->content)
	{
		push_to(a, b, 'a');
		swap(a, b, 'a');
	}
	if (i < *(int *)(*a)->content)
		push_to(a, b, 'a');
}
