/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 21:32:31 by sankosi           #+#    #+#             */
/*   Updated: 2018/07/01 13:59:32 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		ft_countwords(char const *s, char c)
{
	int				it_s;
	unsigned int	i;

	i = 0;
	it_s = i;
	while (s[it_s] != '\0')
	{
		while (s[it_s] == c)
			it_s++;
		if ((s[it_s] != '\0') && (s[it_s] != c))
		{
			i++;
			while (s[it_s] != c && s[it_s] != '\0')
				it_s++;
		}
	}
	return (i);
}

static	char	**ft_populate(char const *s, int num, char **res, char c)
{
	int i;
	int k;
	int j;

	i = 0;
	j = 0;
	while (i < (num - 1))
	{
		if (s[j] != c && s[j] != '\0')
		{
			k = 0;
			while (s[j + k] != '\0' && s[j + k] != c)
				k++;
			res[i] = ft_strsub(s, j, k);
			j += k;
			i++;
		}
		else
			j++;
	}
	return (res);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;

	if (!s)
		return (NULL);
	i = ft_countwords(s, c);
	if (!(res = (char **)malloc(sizeof(char *) * i + 1)))
		return (NULL);
	res = ft_populate(s, i + 1, res, c);
	res[i] = (void *)0;
	return (res);
}
