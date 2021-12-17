/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:44:50 by ialvarez          #+#    #+#             */
/*   Updated: 2021/12/17 20:18:08 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	delete_stack(t_stack *from)
{
	if (from == from->next)
		from = NULL;
	else
	{
		from->pre->next = from->next;
		from->next->pre = from->pre;
		from = from->next;
	}
}

void	push_to_other_list(t_stack *from, t_stack *to)
{
	t_stack *save;
	t_stack *tock;

	if (!from)
		return;
	save = from;
	delete_stack(from);
	if (to)
	{
		tock = to->pre;
		to->pre = save;
		to->pre->next = to;
		to->pre->pre = tock;
		to->pre->pre->next = save;
		to = to->pre;
	}
	else
	{
		to = save;
		to->next = to;
		to->pre = to;
	}
}

void	first_end(t_stack *list)
{
	list = list->next;
}
