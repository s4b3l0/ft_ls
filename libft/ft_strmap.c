/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 12:53:33 by sankosi           #+#    #+#             */
/*   Updated: 2018/06/14 15:18:15 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fstr;
	size_t	i;
	int		x;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	fstr = ft_strnew(i);
	if (!fstr)
		return (NULL);
	x = -1;
	while (s[++x])
		fstr[x] = (*f)(s[x]);
	fstr[x] = '\0';
	return (fstr);
}
