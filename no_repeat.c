/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_repeat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:36:46 by ialvarez          #+#    #+#             */
/*   Updated: 2022/01/24 21:05:00 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	no_cap(int count, char **argv)
{
	int i;
	int size;

	i = 1;
	size = ft_strlen((char *)argv);
	while (count > 1 && count)
	{
		if (argv[i] != ft_isdigit(argv[i]))
			exit (0);
		if ()
		if (argv[i] < -2147483648 || argv[i] > 2147483647)
			exit (0);
		if (argv == argv + 1)
			exit(0);
		i++;
		count++;
	}
}
