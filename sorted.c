/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:04:52 by ialvarez          #+#    #+#             */
/*   Updated: 2022/02/14 20:18:56 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_list *a)
{
	t_list *aux;

	aux = a;
	while (aux->next != NULL)
	{
		if (*(int *)aux->content > *(int *)aux->next->content)
			return (-1);
		aux = aux->next;
	}
	return (0);
}
