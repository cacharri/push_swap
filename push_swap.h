/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:48:24 by ialvarez          #+#    #+#             */
/*   Updated: 2022/01/27 20:31:01 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include	<stdio.h>
# include	<stdlib.h>
# include	"libft/libft.h"


typedef struct s_stack
{
	int num;
	struct s_stack *next;
	struct s_stack *pre;
}					t_stack;

typedef struct s_save
{
	int i;
	int j;
}					t_save;

//void	no_cap(int count, char **argv, int si);
void	push_to_other_list(t_stack *from, t_stack *to);		//pa
void	r_act(t_stack *list);								//ra
void	rr_act(t_stack *list);								//rra
int		is_sorted(t_stack *a, char **argv, int si);
void	positive_sort(t_stack *a, t_stack *b, t_save *save, int num);
void	negative_sort(t_stack *a, t_stack *b, t_save *save, int num);
void	radix_sort(t_stack *a, t_stack *b, t_save *save, int num);
void	ft_error(char **a);

t_stack		*init(char **da);

#endif
