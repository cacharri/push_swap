/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:47:20 by ialvarez          #+#    #+#             */
/*   Updated: 2022/02/18 19:43:42 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(t_list **a)
{
	write(1, "Error\n", 6);
	ft_lstclear(a, free);

}

static void parseo(char **argv)
{
	int i;
	int j;
	long n;
	i = 0;
	while (argv[i])
	{
		j = 0;
		while(argv[i][j])
		{
			if ((argv[i][j] == '-' && ft_isdigit(argv[i][j + 1])) || 
					(argv[i][j] == '+' && ft_isdigit(argv[i][j + 1])))
				j++;
			else if (!ft_isdigit(argv[i][j]))
			{
				write(1, "Error\n", 6);
				exit (0);
			}
			j++;
		}
		n = ft_atoi(argv[i]);
		if(n < -2147483648 || n > 2147483647)
		{
			write(1, "Error\n", 6);
			exit (0);
		}
		i++;
	}
}
static void		look_data(char *argv)
{
	char	**tak;

	tak = ft_split(argv, ' ');
	parseo(tak);
	free(tak);
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
static t_list *keep_data(char *argv, t_list *a)
{
	while(*argv != '\0')
	{
		ft_lstadd_back(&a, ft_add_number(ft_atoi(argv)));
		if (no_repeat(a) == -1)
		{
			free(a);
			exit (0);
		}
		while (ft_isdigit(*argv) || (*argv != ' ' && *argv != '\0') 
				|| ((*argv == '-' && ft_isdigit(*argv + 1)) && (*argv == '+' 
				&& ft_isdigit(*argv + 1))))
			argv++;
		if (*argv == ' ')
			argv++;
	}
	return(a);
}

int		main(int argc, char **argv)
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
		if (ft_strlen(argv[1])== 0)
			return (0);
		while(i++ <= argc)
			look_data(argv[j++]);
		i = 2;
		while(i++ <= argc && argv++)
			a = keep_data(*argv, a);
		if (is_sorted(a) == 0)
			return (0);
		else if (ft_lstsize(a) == 3)
			small(&a, &b);
		else if (ft_lstsize(a) == 2)
			small_two(&a, &b);
		else if (ft_lstsize(a) <= 5 && ft_lstsize(a) > 3)
			small_five(&a, &b);
		else
		{
			simple(&a);
			big_hundred(&a, &b);
		}/*
		while (a != NULL)
		{
			printf("%d\n", *(int *)a->content);
			a = a->next;
		}*/
	}
	//system("leaks push_swap");
	return (0);
}
