/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <sankosi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 16:07:33 by sankosi           #+#    #+#             */
/*   Updated: 2018/08/31 17:34:46 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		exchange_stat(t_stat **st1, t_stat *s2)
{
	(*st1)->name = s2->name;
	(*st1)->path = s2->path;
	(*st1)->date = s2->date;
	(*st1)->st_mode = s2->st_mode;
	(*st1)->st_nlin = s2->st_nlin;
	(*st1)->st_uid = s2->st_uid;
	(*st1)->st_gid = s2->st_gid;
	(*st1)->st_size = s2->st_size;
	(*st1)->st_blocks = s2->st_blocks;
}

void		swap_stat(t_stat **st1, t_stat **st2)
{
	t_stat tmp;

	tmp = **st1;
	exchange_stat(st1, *st2);
	exchange_stat(st2, &tmp);
}

void		ls_sort(t_master tm)
{
	t_stat	*st;
	t_stat	*nx;

	st = tm.d_stat;
	while (st)
	{
		nx = st->next;
		while (nx)
		{
			if (cmp_time(st, nx) > 0)
				swap_stat(&st, &nx);
			nx = nx->next;
		}
		st = st->next;
	}
}
