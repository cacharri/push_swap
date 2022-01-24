/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:04:52 by ialvarez          #+#    #+#             */
/*   Updated: 2022/01/24 21:07:33 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_stack *a, char **argv)
{
	int i;
	int p;
	int size;

	i = 1;
	size = ft_strlen((char *)argv);
	while (i < size)
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