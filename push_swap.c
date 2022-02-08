/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:47:20 by ialvarez          #+#    #+#             */
/*   Updated: 2022/02/08 22:05:22 by ialvarez         ###   ########.fr       */
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
/*
static void		ft_lstclear(t_stack **lst, void (*del)(void *))
{
	t_stack	*tur;
	
	if (lst)
	{
		while (*lst)
		{
			tur = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = tur;
		}
	}
}

void	error(t_stack **a)
{
	write(1, "Error\n", 6);
	ft_lstclear(a, free);

}
*/

static void parseo(char **argv)
{
	int i;
	int j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while(argv[i][j])
		{
			if ((argv[i][j] == '-' && ft_isdigit(argv[i][j + 1])) || 
					(argv[i][j] == '+' && ft_isdigit(argv[i][j])))
				j++;
			else if (!ft_isdigit(argv[i][j]))
			{

			//ft_error(tak);
				write(1, "Error\n", 6);
				//printf("asqwwqqw%s\n", argv[i]);
				exit (0);
			}
			j++;
		}
		i++;
	}
		/*	
	if (num > 2147483647 || num < -2147483648)
	{
		write (1, "Error", 6);
		free(argv);
		exit (0);
		*/
}
static void		keep_data(char *argv)
{
	char	**tak;

	tak = ft_split(argv, ' ');
		printf("hello%s\n", tak[0]);
	parseo(tak);
}

int		main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	//int	p;
	int		i = 2;
	int		j = 1;

	a = NULL;
	b = NULL;
	if (argc <= 1)
		return (0);
	else
	{
		while(i++ <= argc) //tengo que mirar el numero de numeros que hay en la lista, y guardarlo
			keep_data(argv[j++]);
		//a = init(&aux);
		//printf("%d\n", argc);
		//si = ft_strlen(tak);

/*
		p = is_sorted(a, 105);
		if (p == 1)
			exit (0);
		else if (p == 0)
		{
			if (argc > 5)
			{
				radix_sort(a, b, a->num);
			}
			else
				exit (0);
		//	if (big sort)
		//	radix sort
		//	if (small sort)
		//	radixmin
		}*/
	}
	return (0);
}
