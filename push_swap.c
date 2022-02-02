/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:47:20 by ialvarez          #+#    #+#             */
/*   Updated: 2022/02/02 06:44:27 by ialvarez         ###   ########.fr       */
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

static void parseo(char *argv)
{
	long num = 0;

	if(!ft_atoi(argv) && argv[0] != '0')
	{
		if((argv[0] == '+' || argv[0] == '-') && argv[1] == '0')
			num = ft_atoi(argv);
		else
			write(1, "Error\n", 6);
	}
	else
		num = ft_atoi(argv);
	if (num > 2147483647 || num < -2147483648)
		write (1, "Error", 6);
}
static void	keep_data(char *argv, char **tak)
{
	int		i;

	tak = ft_split(argv, ' ');
	i = 0;
	while (tak[i] != NULL)
	{
		parseo(tak[i]);
		/*if (!((ft_atoi(tak[i]) >= '0' && ft_atoi(tak[i]) <= '9') || 
				(ft_atoi(tak[i]) == '-' && (ft_atoi(tak[i + 1]) <= '9' && ft_atoi(tak[i + 1]) >= '0')) || 
				(ft_atoi(tak[i]) == '+' && (ft_atoi(tak[i + 1]) <= '9' && ft_atoi(tak[i + 1]) >= '0'))))
		{
			//ft_error(tak);
			printf("asadsad\n");
			exit(0);
		}*/
		i++;
	}
}

void	ft_error(char ***a)
{
	write(1, "Error\n", 6);
	free(a);
	exit (0);
}

int		main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*tak;
	int		p;
	int		si;
	int		i = 1;

	if (argc <= 1)
		return (0);
	else
	{
		a = NULL;
		b = NULL;
		tak = NULL;
		while(i++ < argc)
			keep_data(argv[i], &tak);
		printf("buu\n");
		si = ft_strlen(tak);

		a = init(&tak);
		p = is_sorted(a, si);
		if (p == 1)
			exit (0);
		else if (p == 0)
		{
			if (argc > 100)
			{
				radix_sort(a, b, a->num);
			}
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
