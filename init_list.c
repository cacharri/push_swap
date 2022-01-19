/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:29:00 by ialvarez          #+#    #+#             */
/*   Updated: 2022/01/19 19:43:12 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void other_nodes(char **da, t_stack *first, t_stack *last, t_stack *node)
{
	t_stack	*node_next;
	int		i;

	i = 2;
	while (da[i] != NULL)
	{
		node_next = malloc(sizeof(t_stack));
		node_next->num = ft_atoi(da[i]);
		node_next->next = first;
		node->next = node_next;
		last = node;
		node = node->next;
		node->pre = last;
	}
}

t_stack *init(char **da)
{
	t_stack	*last;
	t_stack	*first;
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return NULL;
	node->num = ft_atoi(da[1]);
	node->pre = node;
	node->next = node;
	first = node;
	other_nodes(da, first, last, node);
	last = node;
	node = node->next;
	node->pre = last;
	return (node);
}
