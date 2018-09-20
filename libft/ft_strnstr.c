/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:12:17 by sankosi           #+#    #+#             */
/*   Updated: 2018/07/01 13:41:52 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char const	*s1;
	char const	*s2;
	int			i;
	int			x;

	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (*haystack != '\0' && i < (int)len)
	{
		s1 = haystack;
		s2 = needle;
		x = 0;
		while ((i + x) < (int)len && *s2 != '\0' && *s1 == *s2)
		{
			x++;
			s1++;
			s2++;
		}
		if (*s2 == '\0')
			return ((char *)haystack);
		i++;
		haystack++;
	}
	return (NULL);
}
