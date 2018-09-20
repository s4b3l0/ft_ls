/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <sankosi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 10:59:08 by sankosi           #+#    #+#             */
/*   Updated: 2018/08/07 14:00:31 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void			initialize(t_struct *p)
{
	p->zpad = NO;
	p->lr = LEFT;
	p->pos = NO;
	p->put = NO;
	p->hash = NO;
	p->pad = 0;
	p->type = 0;
	p->pres = 0;
}
