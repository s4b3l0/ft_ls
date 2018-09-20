/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <sankosi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 11:26:07 by sankosi           #+#    #+#             */
/*   Updated: 2018/08/07 14:00:21 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_unsigned_len(unsigned long nbr)
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

void	ft_printu(unsigned long nbr, t_struct *pt)
{
	pt->pad -= ft_unsigned_len(nbr);
	if (pt->hash == YES)
		pt->pad -= 1;
	if (pt->lr == LEFT)
		ft_putpad(pt->pad, pt);
	if (pt->hash == YES)
		ft_putchar('0');
	ft_putunsigned(nbr);
	if (pt->lr == RIGHT)
		ft_putpad(pt->pad, pt);
}

void	ft_putunsigned(unsigned long n)
{
	if (n >= 10)
	{
		ft_putunsigned(n / 10);
		ft_putchar((n % 10) + '0');
	}
	else
		ft_putchar(n + '0');
}
