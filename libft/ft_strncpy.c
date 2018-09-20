/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 11:19:25 by sankosi           #+#    #+#             */
/*   Updated: 2018/06/14 13:55:34 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strncpy(char *dst, char const *src, size_t len)
{
	int		i;

	i = -1;
	while (++i < (int)len)
		if (src[i])
			dst[i] = src[i];
		else
			while (i < (int)len)
				dst[i++] = '\0';
	return (dst);
}
