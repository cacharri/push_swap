/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:47:20 by ialvarez          #+#    #+#             */
/*   Updated: 2021/12/22 21:31:15 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	keep_data(char **argv, t_stack **a)
{
	char	**take;
	t_stack	*aux;
	int		i;
	int		o;

	i = 0;
	while (*argv)
	{
		take = ft_split(*argv, ' ');
		while (take[i++])
		{
			if (ft_atoi(take[i]) < -214783648 || ft_atoi(take[i]) > 2147483647)
				exit (0);
			o = ft_atoi(take[i]);
			aux = ft_lstnew(o);
			ft_lstaddback(a, aux);
			free(take[i]);
		}
		free(take);
	}
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
		z = keep_data(++argv, &a);
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
