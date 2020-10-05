/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsonja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 16:47:29 by jsonja            #+#    #+#             */
/*   Updated: 2019/09/14 15:20:18 by jsonja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	j = 0;
	i = ft_strlen(s1);
	while (*s2 && j < n)
	{
		s1[i] = *s2;
		s2++;
		j++;
		i++;
	}
	s1[i] = '\0';
	return (s1);
}