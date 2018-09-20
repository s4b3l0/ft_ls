/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 22:37:30 by sankosi           #+#    #+#             */
/*   Updated: 2018/06/15 11:42:14 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			x;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	x = -1;
	while (++x < n)
		if (str1[x] != str2[x])
			return (str1[x] - str2[x]);
	return (0);
}
