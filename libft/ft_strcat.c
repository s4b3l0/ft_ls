/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 11:51:10 by sankosi           #+#    #+#             */
/*   Updated: 2018/06/14 13:56:24 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strcat(char *dest, char const *src)
{
	int		i;
	int		z;

	i = -1;
	z = (int)ft_strlen(dest);
	while (src[++i])
		dest[z++] = src[i];
	dest[z++] = '\0';
	return (dest);
}
