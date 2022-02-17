/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:11:59 by ialvarez          #+#    #+#             */
/*   Updated: 2022/02/16 20:46:39 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_to(t_list **a, t_list **b, char how)
{
	t_list *aux;

	if (how == 'a' && ft_lstsize(*b) > 0)
	{
		ft_lstadd_front(a, ft_add_number(*(int *)(*b)->content));
		aux = (*b)->next;
		free((*b)->content);
		free(*b);
		(*b) = aux;
		write (1, "pa\n", 3);
	}
	if (how == 'b' && ft_lstsize(*a) > 0)
	{
		ft_lstadd_front(b, ft_add_number(*(int *)(*a)->content));
		aux = (*a)->next;
		free((*a)->content);
		free(*a);
		(*a) = aux;
		write (1, "pb\n", 3);
	}
}

void swap(t_list **a, t_list **b, char how)
{
	void	*aux;

	if ((how == 'a' || how == 's') && ft_lstsize(*a) > 1)
	{
		aux = (*a)->content;
		(*a)->content = (*a)->next->content;
		(*a)->next->content = aux;
		if (how == 'a')
			write (1, "sa\n", 3);
	}
	if ((how == 'b' || how == 's') && ft_lstsize(*b) > 1)
	{
		aux = (*b)->content;
		(*b)->content = (*b)->next->content;
		(*b)->next->content = aux;
		if (how == 's')
			write (1, "sb\n", 3);
	}
	if (how == 's')
		write (1, "ss\n", 3);
}

void rotate(t_list **a)
{
	t_list *aux;

	aux = (*a);
	while (aux->next->next != NULL)
		aux = aux->next;
	ft_lstadd_front(a, ft_add_number(*(int *)aux->next->content));
	free(aux->next->content);
	free(aux->next);
	aux->next = NULL;
}

void r_action(t_list **a, t_list **b, char how)
{
	t_list *aux;

	if ((how == 'a' || how == 'r') && ft_lstsize(*a) > 1)
	{
		ft_lstadd_back(a, ft_add_number(*(int *)(*a)->content));
		aux = (*a)->next;
		free((*a)->content);
		free(*a);
		(*a) = aux;
		if (how == 'a')
			write (1, "ra\n", 3);
	}
	if ((how == 'b' || how == 'r') && ft_lstsize(*b) > 1)
	{
		ft_lstadd_back(b, ft_add_number(*(int *)(*b)->content));
		aux = (*b)->next;
		free((*b)->content);
		free(*b);
		(*b) = aux;
		if (how == 'b')
			write (1, "rb\n", 3);
	}
	if (how == 'r')
		write (1, "rr\n", 3);
}

void rr_action(t_list **a, t_list **b, char how)
{
	if ((how == 'a' || how == 'r') && ft_lstsize(*a) > 1)
	{
		rotate(a);
		if (how == 'a')
			write (1, "rra\n", 4);
	}
	if ((how == 'b' || how == 'r') && ft_lstsize(*b) > 1)
	{
		rotate(b);
		if (how == 'b')
			write (1, "rrb\n", 1);
	}
}


