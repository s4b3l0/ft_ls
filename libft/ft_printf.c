/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <sankosi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 10:44:09 by sankosi           #+#    #+#             */
/*   Updated: 2018/08/16 12:28:34 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdio.h>

static void				formatcheck(t_struct *p, char c)
{
	if (c == '0')
		p->zpad = YES;
	if (c == '-')
		p->lr = RIGHT;
	if (c == '+')
		p->pos = YES;
	if (c == ' ')
		p->put = YES;
	if (c == '#')
		p->hash = YES;
}

int						checkflags(int c)
{
	if (c == '-' || c == '+' || c == '0' || c == ' ' || c == 39 || c == '#')
		return (1);
	else
		return (0);
}

static int				set_padding(t_struct *pt, char *str, int i)
{
	initialize(pt);
	while (checkflags(str[i]))
	{
		formatcheck(pt, str[i]);
		i++;
	}
	if (ft_isdigit(str[i]) || str[i] == '.')
	{
		if (ft_isdigit(str[i]))
			pt->pad = ft_atoi(&str[i]);
		while (ft_isdigit(str[i]) || str[i] == '.')
		{
			if (str[i] == '.')
			{
				i++;
				pt->pres = ft_atoi(&str[i]);
			}
			i++;
		}
	}
	return (i);
}

static void				ft_print(char c, t_struct *pt)
{
	char	b[2];

	if (c == 's' || c == 'S')
		ft_printstr(va_arg(pt->ls, char *), pt);
	if (c == 'i' || c == 'd' || c == 'D')
		ft_printinteger(va_arg(pt->ls, int), pt);
	if ((c == 'c' || c == 'C') && (pt->type = 'c'))
	{
		b[0] = va_arg(pt->ls, unsigned int);
		b[1] = '\0';
		ft_printstr(b, pt);
	}
	if (c == 'o' || c == 'O')
		ft_printoct(va_arg(pt->ls, int), pt);
	if (c == 'x' && (pt->type = 'x'))
		ft_printx(va_arg(pt->ls, unsigned int), pt);
	if (c == 'X' && (pt->type = 'X'))
		ft_printx(va_arg(pt->ls, unsigned int), pt);
	if (c == 'u' || c == 'U')
		ft_printu(va_arg(pt->ls, unsigned int), pt);
	if (c == 'p')
		ft_printptr(va_arg(pt->ls, unsigned long), pt);
	if (c == '%')
		ft_putchar('%');
}

int						ft_printf(const char *format, ...)
{
	t_struct	pt;
	int			i;

	i = -1;
	pt.form = (char *)format;
	va_start(pt.ls, format);
	while (pt.form[++i])
	{
		if (pt.form[i] == '%')
		{
			i++;
			i = set_padding(&pt, pt.form, i);
			ft_print(pt.form[i], &pt);
			i = ft_printh(&pt, pt.form, i);
		}
		else
		{
			ft_putchar(pt.form[i]);
			pt.res = i;
		}
	}
	return (pt.res + 1);
}
