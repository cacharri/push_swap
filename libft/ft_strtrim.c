/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 13:51:35 by ialvarez          #+#    #+#             */
/*   Updated: 2021/04/16 13:25:38 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	  int		i;

	  if (!s1 || !set)
		return (NULL);
	  while (*s1 && ft_strchr(set, *s1))
		s1++;
	  i = ft_strlen(s1);
	  while (i && ft_strchr(set, s1[i]))
		i--;
	  return (ft_substr(s1, 0, i + 1));
}
