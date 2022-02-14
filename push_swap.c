/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:47:20 by ialvarez          #+#    #+#             */
/*   Updated: 2022/02/14 20:20:03 by ialvarez         ###   ########.fr       */
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
*/
void	error(t_list **a)
{
	write(1, "Error\n", 6);
	ft_lstclear(a, free);

}

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
	//printf("lola%s\n", tak[0]);
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
			return (-1);
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
			return (0);
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
//	int	p;
//	int		o = 0;
	int		i = 2;
	int		j = 1;

	a = NULL;
	b = NULL;
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

		while (a != NULL)
		{
			printf("%d\n", *(int *)a->content);
			a = a->next;
		}
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
