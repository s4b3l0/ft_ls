/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 19:35:44 by sankosi           #+#    #+#             */
/*   Updated: 2018/06/18 10:50:13 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_getactlen(char const *s)
{
	unsigned int	i;

	i = 0;
	while (!ft_isspace(s[i]) && (s[i] != '\0'))
		i++;
	return (i);
}

char	*ft_strtrim(char const *s)
{
	size_t		len;
	char		*dest;
	char		*is;

	if (s == NULL)
		return (NULL);
	len = 0;
	is = (char *)s;
	while (ft_isspace(*is) && is)
	{
		is++;
		s++;
	}
	if (!(len = ft_strlen(s)))
		return ((char *)s);
	while (ft_isspace(s[--len]))
		;
	if (!(dest = ft_strnew(len++)))
		return (NULL);
	dest[len] = '\0';
	while (len-- > 0)
		dest[len] = s[len];
	return (dest);
}
