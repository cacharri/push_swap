/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:47:20 by ialvarez          #+#    #+#             */
/*   Updated: 2021/12/17 20:59:11 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	keep_data(char **argv, t_stack **a)
{

}

int		main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		i;
	int		z;
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
		no_cap(argc, argv);
		while (argv[i])
		{
			pv = ft_split(argv[i], ' ');
			printf("esto es %s", pv);
			z = ft_atoi((const char *)pv);
			printf("esto es %d", z);
			a = ft_lstnew((void *) z);
			i++;
		}
	}

	return (0);
}
