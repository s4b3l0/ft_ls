/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 16:01:34 by sankosi           #+#    #+#             */
/*   Updated: 2018/06/14 15:05:42 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_strncmp(char const *s1, char const *s2, size_t n)
{
	int		i;

	i = 0;
	while (i < (int)n - 1 && *s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		i++;
		s1++;
		s2++;
	}
	if (n)
		return (*((unsigned char *)s1) - *((unsigned char *)s2));
	return (0);
}
