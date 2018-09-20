/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 23:51:19 by sankosi           #+#    #+#             */
/*   Updated: 2018/06/12 15:36:47 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	d;
	size_t	i;

	d = (int)ft_strlen(dest);
	i = 0;
	while (i < (unsigned int)n && src[i] != '\0')
	{
		dest[d + i] = src[i];
		i++;
	}
	dest[d + i] = '\0';
	return (dest);
}
