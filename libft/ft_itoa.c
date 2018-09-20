/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 10:14:04 by sankosi           #+#    #+#             */
/*   Updated: 2018/06/19 16:28:11 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int				ft_intlen(int n)
{
	unsigned int	ln;

	ln = 0;
	if (n == 0)
		ln++;
	while (n)
	{
		n /= 10;
		ln++;
	}
	return (ln);
}

static char		ft_negate(int n, char c)
{
	if (n < 0)
		return ('-');
	return (c);
}

char			*ft_itoa(int n)
{
	size_t				ln;
	char				*str;
	int					nbr;

	nbr = n;
	ln = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = n * -1;
		ln++;
	}
	if ((str = ft_strnew(ln)) && (ln += ft_intlen(n)))
	{
		str[ln] = '\0';
		while (0 < ln--)
		{
			str[ln] = (n % 10) + '0';
			n /= 10;
		}
		str[0] = ft_negate(nbr, str[0]);
		return (str);
	}
	return (NULL);
}
