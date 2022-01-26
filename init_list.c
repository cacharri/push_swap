/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:29:00 by ialvarez          #+#    #+#             */
/*   Updated: 2022/01/26 22:02:29 by ialvarez         ###   ########.fr       */
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

void positive_sort(t_stack *a, t_stack *b, t_save *save, int num)
{
	int j;

	j = 1;
	while (j++ <= num)
	{
		if ((a->num >> save->i) & 1)
		{
			push_to_other_list(a, b);
			r_act(b);
			write(1, "pb rb", 6);
			save->j++;
		}
		else
		{
			r_act(a);
			write(1, "ra", 3);
		}
	}
	j = 0;
	if (b != NULL)
	{
		while (j < save->j)
		{
			push_to_other_list(b, a);
			write(1, "pa", 3);
		}
	}
}

void negative_sort(t_stack *a, t_stack *b, t_save *save, int num)
{
	int j;

	j = 1;
	while (j++ <= num)
	{
		if ((a->num >> 31) & 1)
		{
			push_to_other_list(a, b);
			write(1, "pb", 3);
			save->j++;
		}
		else
		{
			r_act(a);
			write(1, "ra", 3);
		}
	}
	j = 0;
	if (b != NULL)
	{
		while (j < save->j)
		{
			push_to_other_list(b, a);
			write(1, "pa", 3);
		}
	}
}

void radix_sort(t_stack *a, t_stack *b, t_save *save, int num)
{
	save->i = 0;
	while (save->i++ << 31)
	{
		save->j = 0;
		positive_sort(a, b, save, num);
	}
	save->j = 0;
	negative_sort(a, b, save, num);
	write(1, "rb\n", 3);
}
