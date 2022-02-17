/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:10:08 by ialvarez          #+#    #+#             */
/*   Updated: 2022/02/16 20:54:48 by ialvarez         ###   ########.fr       */
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

static	void find_small(t_list **a, t_list **b)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = *(int *)(*b)->content;
	j = *(int *)(*a)->content;
	k = *(int *)(*a)->next->content;
	l = *(int *)(*a)->next->next->content;
	if (i > l)
	{
		push_to(a, b, 'a');
		r_action(a, b, 'a');
	}
	else if (i > k && i < l)
	{
		rr_action(a, b, 'a');
		push_to(a, b, 'a');
		r_action(a, b, 'a');
		r_action(a, b, 'a');
	}
	else if (i < k && i > j)
	{
		push_to(a, b, 'a');
		swap(a, b, 'a');
	}
	if (i < j)
		push_to(a, b, 'a');
}

static	void find_fifth(t_list **a, t_list **b)
{
	int	i;
	int	j;
	int	k;
	int	l;
	int	s;

	i = *(int *)(*b)->content;
	j = *(int *)(*a)->content;
	k = *(int *)(*a)->next->content;
	l = *(int *)(*a)->next->next->content;
	s = *(int *)(*a)->next->next->next->content;
	if (i < j)
		push_to(a, b, 'a');
	if (i > s)
	{
		push_to(a, b, 'a'),
		r_action(a, b, 'a');
	}
	else if (i < s && i > l)
	{
		rr_action(a, b, 'a');
		push_to(a, b, 'a');
		r_action(a, b, 'a');
		r_action(a, b, 'a');
	}
	else if (i < l && i > k)
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

static int special_k(t_list **a, t_list **b)
{
	int	i;
	int	j;
	int	k;
	int	l;
	int	s;

	i = *(int *)(*a)->content;
	j = *(int *)(*a)->next->content;
	k = *(int *)(*a)->next->next->content;
	l = *(int *)(*a)->next->next->next->content;
	s = *(int *)(*a)->next->next->next->next->content;
	if (s < l && l < i && i < j && j < k)
	{
		rr_action(a, b, 'a');
		rr_action(a, b, 'a');
		swap(a, b, 'a');
		return (1);
	}
	return (0);
}

void	small_five(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) == 4)
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
			find_fifth(a, b);
		}
	}
}
