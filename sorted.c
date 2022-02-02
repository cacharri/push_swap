/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:04:52 by ialvarez          #+#    #+#             */
/*   Updated: 2022/02/02 01:21:30 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_stack *a, int si)
{
	int i;
	int p;

	i = 0;
	while (i < si)
	{
		if (a->num > a->next->num)
		{
			p = 0;
			break ;
		}
		else
			p = 1;
		a = a->next;
		i++;
	}
	a = a->next;
	return (p);
}
