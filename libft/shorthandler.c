/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shorthandler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <sankosi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 22:51:09 by sankosi           #+#    #+#             */
/*   Updated: 2018/08/07 14:01:13 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void				ft_plen(char c, int n, t_struct *p)
{
	if (c == 'i' || c == 'd')
		ft_printinteger(n, p);
	else if (c == 'o' || c == 'O')
		ft_printoct(n, p);
	else if (c == 'x' && (p->type = 'x'))
		ft_printx(n, p);
	else if (c == 'X' && (p->type = 'X'))
		ft_printx(n, p);
}

int					ft_printh(t_struct *pt, char *str, int i)
{
	char				c;
	char				l;
	int					n;
	short int			x;

	n = 0;
	c = '\0';
	if (str[i] == 'h' && str[i + 1] == str[i])
	{
		l = va_arg(pt->ls, int);
		n = l;
		i = i + 2;
		c = str[i];
	}
	else if (str[i] == 'h' && str[i + 1] != str[i])
	{
		x = va_arg(pt->ls, int);
		n = x;
		i = i + 1;
		c = str[i];
	}
	else if (str[i] == 'l' || str[i] == 'j' || str[i] == 'z')
		return (ft_printl(pt, str, i));
	ft_plen(c, n, pt);
	return (i);
}
