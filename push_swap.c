/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:47:20 by ialvarez          #+#    #+#             */
/*   Updated: 2022/01/19 19:43:09 by ialvarez         ###   ########.fr       */
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

void	keep_data(char **argv, t_stack **a)
{
	char	**take;
	t_stack	*aux;
	int		i;
	int		o;

	i = 0;
	while (*argv)
	{
		if (**argv != ' ')
		{
			take = ft_split(*argv, ' ');
			while (take[i++])
			{
				if (ft_atoi(take[i]) < -214783648 || ft_atoi(take[i]) > 2147483647)
					exit (0);
				o = ft_atoi(take[i]);
				aux = ft_new(o);
				ft_add_back(a, aux);
				free(take[i]);
			}
			free(take);
		}
	}
}

int		main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		i;
	char	**pv;

//	a = malloc(sizeof(t_list));
//	b = malloc(sizeof(t_list));
	i = 1;
	if (argc <= 1)
		exit(0);
	if (argc > 1)
	{
		a = NULL;
		b = NULL;
		keep_data(++argv, &a);
		//no_cap(argc, argv);
		/*while (argv[i])
		{
			pv = ft_split(argv[i], ' ');
			printf("esto es %s", pv);
			z = ft_atoi((const char *)pv);
			printf("esto es %d", z);
			a = ft_lstnew((void *) z);
			i++;
		}
		*/
	}

	return (0);
}
