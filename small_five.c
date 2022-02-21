/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_five.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:06:17 by ialvarez          #+#    #+#             */
/*   Updated: 2022/02/21 20:25:33 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	aux_five(t_list **a, t_list **b)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = *(int *)(*b)->content;
	j = *(int *)(*a)->content;
	k = *(int *)(*a)->next->content;
	l = *(int *)(*a)->next->next->content;
	if (i < j)
		push_to(a, b, 'a');
	if (i < l && i > k)
	{
		rr_action(a, b, 'a');
		rr_action(a, b, 'a');
		push_to(a, b, 'a');
		rr_action(a, b, 'a');
		rr_action(a, b, 'a');
	}
	else if (i < k && i > j)
	{
		push_to(a, b, 'a');
		swap(a, b, 'a');
	}
}

static	int	find_fifth(t_list **a, t_list **b)
{
	int	i;
	int	l;
	int	s;

	i = *(int *)(*b)->content;
	l = *(int *)(*a)->next->next->content;
	s = *(int *)(*a)->next->next->next->content;
	if (i > s)
	{
		push_to(a, b, 'a'),
		r_action(a, b, 'a');
		return (1);
	}
	else if (i < s && i > l)
	{
		rr_action(a, b, 'a');
		push_to(a, b, 'a');
		r_action(a, b, 'a');
		r_action(a, b, 'a');
		return (1);
	}
	return (0);
}

static void	aux_k(t_list **a, t_list **b)
{
	rr_action(a, b, 'a');
	rr_action(a, b, 'a');
	rr_action(a, b, 'a');
	swap(a, b, 'a');
	r_action(a, b, 'a');
}

static int	special_k(t_list **a, t_list **b)
{
	int	i;
	int	j;
	int	l;
	int	s;

	i = *(int *)(*a)->content;
	j = *(int *)(*a)->next->content;
	l = *(int *)(*a)->next->next->next->content;
	s = *(int *)(*a)->next->next->next->next->content;
	if (s < l && l < i && i < j && j < *(int *)(*a)->next->next->content)
	{
		rr_action(a, b, 'a');
		rr_action(a, b, 'a');
		swap(a, b, 'a');
	}
	else if (l > j && j > i && i > s && s > *(int *)(*a)->next->next->content)
		aux_k(a, b);
	else
		return (0);
	return (1);
}

void	small_five(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) == 3)
		small(a, b);
	else if (ft_lstsize(*a) == 4)
	{
		push_to(a, b, 'b');
		small(a, b);
		find_small(a, b);
	}
	else if (ft_lstsize(*a) == 5)
	{
		if (special_k(a, b) == 1)
			return ;
		else if (special_k(a, b) == 0)
		{
			push_to(a, b, 'b');
			push_to(a, b, 'b');
			small(a, b);
			find_small(a, b);
			if (find_fifth(a, b) == 1)
				return ;
			else
				aux_five(a, b);
		}
	}
}
