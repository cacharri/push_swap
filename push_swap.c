/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:47:20 by ialvarez          #+#    #+#             */
/*   Updated: 2022/02/22 19:24:37 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	parseo(char **argv)
{
	int		i;
	int		j;
	char	*aux;

	aux = NULL;
	i = 0;
	while (argv[i])
	{
		j = 0;
		aux_parse(argv, i, j);
		i++;
	}
	if (i == 0)
	{
		write(1, "Error\n", 6);
		exit (0);
	}
}

static void	look_data(char *argv)
{
	char	**tak;
	int		i;

	i = 0;
	tak = ft_split(argv, ' ');
	parseo(tak);
	while (tak[i])
	{
		free(tak[i]);
		i++;
	}
	free (tak);
}

static int	no_repeat(t_list *a)
{
	t_list	*aux;
	t_list	*last;

	aux = a;
	last = ft_lstlast(a);
	while (aux->next != NULL)
	{
		if (*(int *)aux->content == *(int *)last->content)
		{
			write (1, "Error\n", 6);
			return (-1);
		}
		aux = aux->next;
	}
	return (0);
}

static t_list	*keep_data(char *argv, t_list *a)
{
	while (*argv != '\0')
	{
		ft_lstadd_back(&a, ft_add_number(ft_atoi(argv)));
		while (*argv == ' ')
			argv++;
		if (no_repeat(a) == -1)
		{
			ft_lstclear(&a, free);
			exit (0);
		}
		while (ft_isdigit(*argv) || (*argv != ' ' && *argv != '\0')
			|| ((*argv == '-' && ft_isdigit(*argv + 1)) && (*argv == '+'
					&& ft_isdigit(*argv + 1))))
			argv++;
	}
	return (a);
}
/*
void	leaks()
{
	system("leaks push_swap");
}*/

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		i;
	int		j;

	a = NULL;
	b = NULL;
	i = 2;
	j = 1;
	if (argc <= 1)
		return (0);
	else
	{
		j = 1;
		while (i++ <= argc)
			look_data(argv[j++]);
		i = 2;
		while (i++ <= argc && argv++)
			a = keep_data(*argv, a);
		push(&a, &b);
	}
	ft_lstclear(&a, free);
	return (0);
}
