/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:04:52 by ialvarez          #+#    #+#             */
/*   Updated: 2022/02/21 21:35:18 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *a)
{
	t_list	*aux;

	aux = a;
	while (aux->next != NULL)
	{
		if (*(int *)aux->content > *(int *)aux->next->content)
			return (-1);
		aux = aux->next;
	}
	return (0);
}

t_list	*ft_add_number(int content)
{
	t_list	*ay;

	ay = malloc(sizeof(int));
	if (!ay)
		return (NULL);
	ay->content = malloc(sizeof(int));
	ay->next = NULL;
	*(int *)ay->content = content;
	return (ay);
}
