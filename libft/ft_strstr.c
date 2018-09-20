/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:12:17 by sankosi           #+#    #+#             */
/*   Updated: 2018/06/15 11:30:31 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t		len;

	if ((*needle == '\0') && (*haystack == '\0'))
		return ((char *)haystack);
	len = ft_strlen(needle);
	while (*haystack != '\0')
	{
		if ((ft_memcmp(haystack, needle, len)) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
