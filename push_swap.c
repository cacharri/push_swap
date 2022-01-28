/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:47:20 by ialvarez          #+#    #+#             */
/*   Updated: 2022/01/28 21:24:03 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
static	t_stack	*ft_new(int content)
{
	t_stack	*other;

	other = malloc(sizeof(t_stack));
	if (!other)
		return (NULL);
	other->num = content;
	other->next = NULL;
	return (other);
}

static	t_stack	*ft_last(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

static	void	ft_add_back(t_stack **lst, t_stack *new)
{
	t_stack	*rte;

	if (*lst == NULL)
	{
		*lst = new;
		new->next = NULL;
	}
	else
	{
		rte = *lst;
		rte = ft_last(rte);
		rte->next = new;
	}
}
*/
static void	keep_data(int argc, char **argv, char ***tak)
{
	int		i;
	int		j;
	int u;

	i = 1;
	u = 1;
	j = 0;
	while (u++ < argc)
	{
		if (argv != NULL)
		{
			*tak = ft_split((char *)argv, ' ');
			while (tak[i][j++])
			{
				if (!((*tak[i][j] >= '0' && *tak[i][ j] <= '9') || 
						(*tak[i][j] == '-' && (*tak[i][j + 1] <= '9' && *tak[i][j + 1] >= '0')) || 
						(*tak[i][j] == '+' && (*tak[i][j + 1] <= '9' && *tak[i][j + 1] >= '0'))))
						ft_error(*tak);
			}
			i++;
		}
	}
}

void	ft_error(char **a)
{
	write(1, "Error\n", 6);
	free(a);
	exit (0);
}

int		main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**tak;
	int		p;
	int		si;

	b = NULL;
	tak = NULL;
	if (argc <= 1)
		exit(0);
	else if (argc > 1)
	{
		keep_data(argc, ++argv, &tak);
		si = ft_strlen((char *)tak);
		a = init(tak);
		p = is_sorted(a, si);
		if (p == 1)
			exit (0);
		else if (p == 0)
		{
			if (argc > 100)
				radix_sort(a, b, a->num);
			else
				exit (0);
		//	if (big sort)
		//	radix sort
		//	if (small sort)
		//	radixmin
		}
	}
	return (0);
}
