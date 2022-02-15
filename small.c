/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:10:08 by ialvarez          #+#    #+#             */
/*   Updated: 2022/02/15 21:57:53 by ialvarez         ###   ########.fr       */
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
	t_list	*aux;

	aux = *a;
	i = *(int *)aux->content;
	j = *(int *)aux->next->content;
	k = *(int *)aux->next->next->content;
	if (k > i && k > j)
		swap(a, b, 'a');
	if (i < j && i > k)
		rr_action(a, b, 'a');
	if (k > i && j > k)
	{
		swap(a, b, 'a');
		r_action(a, b, 'a');
	}
	if (i > k && k > j)
		r_action(a, b, 'a');
	if (i > j && j > k)
	{
		swap(a, b, 'a');
		rr_action(a, b, 'a');
	}
}

void	small_five(t_list **a, t_list **b)
{
	push_to(a, b, 'b');
	push_to(a, b, 'b');
	small(a, b);
	push_to(a, b, 'a');
	if (*(int *)(*a)->content > *(int*)(*a)->next->content)
		r_action(a, b, 'a');
	push_to(a, b, 'a');
	if (*(int *)(*a)->content > *(int *)(*a)->next->content)
		small_five(a, b);
	/*
	if(is_sorted(*a) == 0)
		push_to(a, b, 'a');
	else
	{
		r_action(a, b, 'a');
		if(is_sorted(*a) == 0)
			push_to(a, b, 'a');
		else
		{
			r_action(a, b, 'a');
			push_to(a, b, 'a');
		}
	}
	if(is_sorted(*a) == 0)
		return ;
	else
	{
		r_action(a, b, 'a');
		if (!(is_sorted(*a) == 0))
			r_action(a, b, 'a');
	}*/
}
