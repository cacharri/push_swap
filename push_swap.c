/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:47:20 by ialvarez          #+#    #+#             */
/*   Updated: 2021/12/15 20:14:23 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	//t_list	*a;
//	t_list	*b;
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
