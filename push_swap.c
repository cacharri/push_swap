/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:47:20 by ialvarez          #+#    #+#             */
/*   Updated: 2022/02/11 18:32:35 by ialvarez         ###   ########.fr       */
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
/*
static char **keep(char **argv, int argc)
{
	char **aux;
	char **auxa;
	int o = 0;
	int i;
	//int j;

	//j = 1;
	i = 2;
	aux = NULL;
	auxa = NULL;
	auxa[0] = ft_strdup(argv[1]);
	while(i < argc)
	{
		o = 1;
		aux = auxa;
		auxa[o] = ft_strjoin(auxa[o], " ");
		free(auxa);
		auxa[o] = *aux;
		auxa[o] = ft_strjoin(auxa[o], argv[i]);
		free(aux);
		i++;
		o++;
	}
	
	while (i++ <= argc)
	{
		aux = ft_split(argv[j], ' ');
		auxa = ft_strjoin()
		j++;
	}
	//aux[o++] = *aux;
	
	return (auxa);
}
*/
static t_list	*ft_add_number(int content)
{
	t_list *ay;

	ay = malloc(sizeof(int));
	if (!ay)
		return (NULL);
	ay->content = malloc(sizeof(int));
	ay->next = NULL;
	*(int *)ay->content = content;
	return (ay);
}
static void parseo(char **argv)
{
	int i;
	int j;
	long n;
	int k;
	i = 0;
	n = 0;
	while (argv[i])
	{
		j = 0;
		k = 0;
		//printf("parse%s\n\n", argv[i]);
		//printf("parsero--->%d\n", i);
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
	//printf("lola%s\n", tak[0]);
}

int		main(int argc, char **argv)
{
//	t_stack	*a;
//	t_stack	*b;
	t_list	*a;
	t_list	*b;
//	char **aux;
//	int	p;
//	int		o = 0;
	int		i = 2;
	int		j = 1;

//	a = NULL;
//	b = NULL;
	a = NULL;
	b = NULL;
//	aux = NULL;
	if (argc <= 1)
		return (0);
	else
	{
		if (ft_strlen(argv[1])== 0)
			return (0);
		while(i++ <= argc)
			look_data(argv[j++]);
		//printf("sdc-->%d", argc);
	//	a = init(argv + 1);
	//	printf("keepp---> %s\n", aux[3]);
	//	printf("keepp---> %s\n", aux[4]);
		
		//a = init(&aux);
		//printf("%d\n", argc);
		//si = ft_strlen(tak);
	/*	p = is_sorted(a, 105);
		if (p == 1)
			exit (0);
		else if (p == 0)
		{
			if (argc > 5)
			{
				printf("goooo");
				radix_sort(a, b, 105);
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
