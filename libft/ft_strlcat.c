/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 20:52:31 by sankosi           #+#    #+#             */
/*   Updated: 2018/06/18 10:25:43 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*id;
	char const	*is;
	size_t		n;
	size_t		dlen;

	n = size;
	id = dst;
	is = src;
	while (n-- != 0 && *id != '\0')
		id++;
	dlen = id - dst;
	n = size - dlen;
	if (n == 0)
		return (dlen + ft_strlen(is));
	while (*is != '\0')
	{
		if (n != 1)
		{
			*id++ = *is;
			n--;
		}
		is++;
	}
	*id = '\0';
	return (dlen + (is - src));
}
