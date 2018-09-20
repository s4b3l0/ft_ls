/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 12:15:29 by sankosi           #+#    #+#             */
/*   Updated: 2018/07/01 13:53:43 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char	*ft_strchr(char const *s, int c)
{
	char		*tmp;

	while (*s)
	{
		if (*s == c)
		{
			tmp = (char*)s;
			return (tmp);
		}
		s++;
	}
	if (c == '\0')
	{
		tmp = (char*)s;
		return (tmp);
	}
	return (NULL);
}
