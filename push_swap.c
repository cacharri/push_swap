/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:47:20 by ialvarez          #+#    #+#             */
/*   Updated: 2022/01/26 22:02:27 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	keep_data(char **argv, t_stack **a)
{
	char	**tak;
	t_stack	*aux;
	int		i;
	int		o;

	i = 0;
	while (*argv)
	{
		if (**argv != ' ')
		{
			tak = ft_split(*argv, ' ');
			while (tak[i++])
			{
				if (ft_atoi(tak[i]) < -214783648 || ft_atoi(tak[i]) > 2147483647)
					exit (0);
				o = ft_atoi(tak[i]);
				aux = ft_new(o);
				ft_add_back(a, aux);
				free(tak[i]);
			}
			free(tak);
		}
	}
}

static	int	size(int argc)
{
	int i;

	i = -1;
	while(argc)
		i++;
	return (i);
}

int		main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		p;
	int		si;
	char	**pv;

	si = size(argc);
	if (argc <= 1)
		exit(0);
	else if (argc > 1)
	{
		a = init(argv);
		b = init(argv);
		keep_data(++argv, &a);
		p = is_sorted(a);
		if (p == 1)
			exit (0);
		else if (p == 0)
		{
		//	if (big sort)
		//	radix sort
		//	if (small sort)
		//	radixmin
		}
	}
	return (0);
}
