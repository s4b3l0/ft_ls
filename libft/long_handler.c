/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <sankosi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 23:11:41 by sankosi           #+#    #+#             */
/*   Updated: 2018/08/07 14:00:52 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void		ft_longs(char c, long long n, t_struct *p)
{
	if (c == 'i' || c == 'd')
		ft_printu(n, p);
	else if (c == 'o' || c == 'O')
		ft_printoct(n, p);
	else if (c == 'x' && (p->type = 'x'))
		ft_printx(n, p);
	else if (c == 'X' && (p->type = 'X'))
		ft_printx(n, p);
}

int				ft_printl(t_struct *pt, char *str, int i)
{
	char				c;
	long				l;
	long long			n;

	c = 0;
	n = 0;
	if (str[i] == 'l' && str[i + 1] == str[i])
	{
		n = va_arg(pt->ls, long long);
		i = i + 2;
		c = str[i];
	}
	else if (str[i] == 'l' && str[i + 1] != str[i])
	{
		l = va_arg(pt->ls, int);
		n = l;
		i = i + 1;
		c = str[i];
	}
	else if (str[i] == 'j' || str[i] == 'z')
		return (ft_printm(pt, str, i));
	ft_longs(c, n, pt);
	return (i);
}
