/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 15:47:49 by sankosi           #+#    #+#             */
/*   Updated: 2018/07/01 13:57:18 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;

	i = 0;
	i = ft_strlen(s);
	if ((dest = ft_strnew(i)))
		ft_strncpy(dest, s, i);
	return (dest);
}
