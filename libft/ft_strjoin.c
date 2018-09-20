/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 19:13:50 by sankosi           #+#    #+#             */
/*   Updated: 2018/06/30 21:29:22 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin(const char *s1, char const *s2)
{
	char	*dest;
	char	*id;

	if (s1 == NULL && s2 == NULL)
		return (ft_strnew(0));
	else if (s1 == NULL)
		return (ft_strdup(s2));
	else if (s2 == NULL)
		return (ft_strdup(s1));
	dest = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (dest == NULL)
		return (NULL);
	id = dest;
	while (*s1 != '\0')
		*id++ = *s1++;
	while (*s2 != '\0')
		*id++ = *s2++;
	*id = '\0';
	return (dest);
}
