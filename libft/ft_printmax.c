/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmax.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <sankosi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 11:26:07 by sankosi           #+#    #+#             */
/*   Updated: 2018/08/07 13:59:00 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_max_t(__int128_t nbr)
{
	int		i;

	i = 0;
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

void	ft_printmax(__int128_t nbr, t_struct *pt)
{
	pt->pad -= ft_max_t(nbr);
	if (pt->hash == YES)
		pt->pad -= 1;
	if (pt->lr == LEFT)
		ft_putpad(pt->pad, pt);
	if (pt->hash == YES)
		ft_putchar('0');
	ft_putmax(nbr);
	if (pt->lr == RIGHT)
		ft_putpad(pt->pad, pt);
}

void	ft_putmax(__int128_t n)
{
	if (n >= 10)
	{
		ft_putmax(n / 10);
		ft_putchar((n % 10) + '0');
	}
	else
		ft_putchar(n + '0');
}
