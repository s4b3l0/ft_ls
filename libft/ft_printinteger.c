/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printinteger.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <sankosi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 10:39:56 by sankosi           #+#    #+#             */
/*   Updated: 2018/08/07 13:58:49 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>

int			ft_intlen(int c)
{
	int i;

	i = 0;
	while (c > 0)
	{
		c = c / 10;
		i++;
	}
	return (i);
}

void		putsigns(int i, t_struct *pt)
{
	if (i < 0 || pt->pos == YES)
	{
		pt->pad -= 1;
		if (pt->pos == YES && i >= 0 && pt->zpad == YES)
			ft_putchar('+');
	}
	if (pt->zpad == YES && i < 0)
	{
		i = ABS(i);
		ft_putchar('-');
	}
}

void		ft_printinteger(int i, t_struct *pt)
{
	pt->pad = pt->pad - ft_intlen(ABS(i));
	pt->pad = pt->pad - pt->pres;
	putsigns(i, pt);
	if (pt->put == YES && i >= 0)
	{
		pt->pad -= 1;
		ft_putchar(' ');
	}
	if (pt->lr == LEFT)
		ft_putpad(pt->pad, pt);
	if (pt->pos == YES && i >= 0)
		ft_putchar('+');
	if (pt->zpad == YES && i < 0)
		i = i * -1;
	ft_putnbr(i);
	if (pt->lr == RIGHT)
	{
		if (pt->put == YES)
			pt->pad = pt->pad - 1;
		ft_putpad(pt->pad, pt);
	}
}
