/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <sankosi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 15:04:37 by sankosi           #+#    #+#             */
/*   Updated: 2018/08/07 13:59:33 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void		ft_printstr(char *s, t_struct *pt)
{
	if (pt->type != 'c')
		pt->zpad = NO;
	if (s == NULL)
		s = "(null)";
	pt->pad -= ft_strlen(s);
	if (pt->lr == LEFT)
		ft_putpad(pt->pad, pt);
	ft_putstr(s);
	if (pt->lr == RIGHT)
		ft_putpad(pt->pad, pt);
}
