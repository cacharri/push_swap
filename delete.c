/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:44:50 by ialvarez          #+#    #+#             */
/*   Updated: 2021/12/16 20:10:20 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delete_stack(t_stack *from)
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
