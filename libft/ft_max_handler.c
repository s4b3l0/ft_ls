/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <sankosi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 23:11:41 by sankosi           #+#    #+#             */
/*   Updated: 2018/08/16 12:29:30 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void		ft_max_parse(char c, long long n, t_struct *p)
{
	if (c == 'i' || c == 'd')
		ft_printmax(n, p);
	else if (c == 'o' || c == 'O')
		ft_printoct(n, p);
	else if (c == 'x' && (p->type = 'x'))
		ft_printx(n, p);
	else if (c == 'X' && (p->type = 'X'))
		ft_printx(n, p);
}

int				ft_printm(t_struct *pt, char *str, int i)
{
	char					c;
	size_t					sz;
	unsigned long long		n;

	c = 0;
	n = 0;
	if (str[i] == 'j')
	{
		n = va_arg(pt->ls, unsigned long long);
		i = i + 1;
		c = str[i];
	}
	else if (str[i] == 'z')
	{
		sz = va_arg(pt->ls, unsigned int);
		n = sz;
		i = i + 1;
		c = str[i];
	}
	ft_max_parse(c, n, pt);
	return (i);
}
