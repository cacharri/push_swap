/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:48:24 by ialvarez          #+#    #+#             */
/*   Updated: 2022/01/19 16:34:19 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include	<stdio.h>
# include	<stdlib.h>
# include	"libft/libft.h"

void	no_cap(int count, char **argv);
void	push_to_other_list(t_stack *from, t_stack *to);		//pa
void	r_act(t_stack *list);								//ra
void	rr_act(t_stack *list);								//rra

typedef struct s_stack
{
	int num;
	struct s_stack *next;
	struct s_stack *pre;
}					t_stack;

t_stack		*init(char **da);

#endif
