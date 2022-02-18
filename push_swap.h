/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:48:24 by ialvarez          #+#    #+#             */
/*   Updated: 2022/02/18 19:50:57 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include	<stdio.h>
# include	<stdlib.h>
# include	"libft/libft.h"

void	push_to(t_list **a, t_list **b, char how);
void	swap(t_list **a, t_list **b, char how);
void	rotate(t_list **a);
void	r_action(t_list **a, t_list **b, char how);
void	rr_action(t_list **a, t_list **b, char how);
int		is_sorted(t_list *a);
void	error(t_list **a);
void	small(t_list **a, t_list **b);
void	small_two(t_list **a, t_list **b);
void	small_five(t_list **a, t_list **b);
void	big_hundred(t_list **a, t_list **b);
void	simple(t_list **a);

t_list	*ft_add_number(int content);

#endif
