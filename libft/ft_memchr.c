/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 22:21:32 by sankosi           #+#    #+#             */
/*   Updated: 2018/06/13 15:51:58 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*str;

	str = (const char *)s;
	while (n-- != 0)
	{
		if (*str == (char)c)
			return ((void *)str);
		str++;
	}
	return (NULL);
}
