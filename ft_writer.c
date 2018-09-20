/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <sankosi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 13:00:56 by sankosi           #+#    #+#             */
/*   Updated: 2018/09/01 11:55:19 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void					ls_out(t_master tm)
{
	t_stat	*ptr;
	int		chk;

	chk = (tm.fl->a == 1) ? (1) : (0);
	ptr = tm.d_stat;
	if (chk == 0)
		while (ptr && *(ptr->name) == '.')
			ptr = ptr->next;
	while (ptr)
	{
		if (!(chk == 0 && *ptr->name == '.'))
			ft_printf("%s\n", ptr->name);
		ptr = ptr->next;
	}
}

void					ls_outl(t_master tm)
{
	t_stat	*ptr;
	int		chk;
	char	*str;
	int		started;

	started = 0;
	chk = (tm.fl->a == 1) ? (1) : (0);
	ptr = tm.d_stat;
	if (chk == 0)
		while (ptr && *(ptr->name) == '.')
			ptr = ptr->next;
	while (ptr)
	{
		if (!(chk == 0 && *ptr->name == '.'))
		{
			str = ft_strsub(ctime(&(ptr->date)), 4, 12);
			perm_out(ptr);
			ft_printf("%5i %s ", ptr->st_nlin, getpwuid(ptr->st_uid)->pw_name);
			ft_printf("%s %7i %10s %s\n", getgrgid(ptr->st_gid)->gr_name, \
				ptr->st_size, str, ptr->name);
		}
		started = 1;
		ptr = ptr->next;
	}
}

void					getsize(t_master tm)
{
	t_stat *ptr;

	ptr = tm.d_stat;
	tm.fl->tot = 0;
	while (ptr)
	{
		tm.fl->tot += ptr->st_blocks;
		ptr = ptr->next;
	}
}

void					write_out(t_master tm)
{
	if (tm.fl->t == 1)
		ls_sort(tm);
	if (tm.fl->r == 1)
		tm.d_stat = rev_list(tm.d_stat);
	if (tm.fl->l == 0)
		ls_out(tm);
	if (tm.fl->l == 1)
		ls_outl(tm);
	if (tm.fl->cap_r == 1)
		recursion(tm);
}
