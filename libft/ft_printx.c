/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <sankosi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 14:53:25 by sankosi           #+#    #+#             */
/*   Updated: 2018/08/16 11:44:02 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdio.h>

static int			xlen(unsigned long num)
{
	int		i;

	i = 0;
	while (num > 0)
	{
		num = num / 16;
		i++;
	}
	return (i);
}

static void			pleft(char *res, t_struct *pt)
{
	if (pt->hash == YES && pt->zpad == YES)
	{
		ft_putstr("0x");
		pt->pad -= 2;
		pt->pad -= ft_strlen(res);
		ft_putpad(pt->pad, pt);
	}
	else if (pt->hash == YES && pt->zpad == NO)
	{
		pt->pad -= 2;
		pt->pad -= ft_strlen(res);
		ft_putpad(pt->pad, pt);
		ft_putstr("0x");
	}
	else
	{
		pt->pad -= ft_strlen(res);
		ft_putpad(pt->pad, pt);
	}
}

static void			px(char *res, t_struct *pt)
{
	if (pt->lr == LEFT)
		pleft(res, pt);
	else
	{
		pt->pad -= ft_strlen(res);
		if (pt->hash == YES && pt->lr != LEFT)
		{
			pt->pad -= 2;
			ft_putstr("0x");
		}
	}
	ft_putstr(res);
	if (pt->lr == RIGHT)
		ft_putpad(pt->pad, pt);
}

static void			convertox(unsigned long num, t_struct *pt)
{
	char				*res;
	int					n;
	char				*xtab;

	if (pt->type == 'x')
		xtab = "0123456789abcdef";
	else
		xtab = "0123456789ABCDEF";
	n = xlen(num);
	res = (char *)malloc(sizeof(char) * (n + 1));
	res[n] = '\0';
	n--;
	while (n >= 0)
	{
		res[n] = xtab[num % 16];
		num = num / 16;
		n--;
	}
	px(res, pt);
}

void				ft_printx(unsigned int i, t_struct *pt)
{
	convertox(i, pt);
}
