/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   body.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <sankosi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 12:53:42 by sankosi           #+#    #+#             */
/*   Updated: 2018/09/01 12:02:51 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#define JOIN(x, y) ft_strjoin(x, y)
#define SEL(x, y, z) select_star(x, y ,z)

void		folder_rdr(t_master tm, int mult)
{
	DIR		*dir;
	t_stat	*file;
	int		st;

	st = 0;
	file = NULL;
	while (tm.stats)
	{
		dir = opendir(tm.stats->name);
		while ((SEL(&file, readdir(dir), JOIN(tm.stats->path, "/"))) != 42)
			;
		closedir(dir);
		tm.d_stat = file;
		if (tm.d_stat)
		{
			getsize(tm);
			(st == 1) ? ft_printf("%c", '\n') : 0;
			(mult) ? ft_printf("%s:\n", tm.stats->name) : 0;
			(tm.fl->l == 1) ? (ft_printf("total %i\n", tm.fl->tot)) : 0;
			st = 1;
			write_out(tm);
		}
		file = NULL;
		tm.stats = tm.stats->next;
	}
}

void		fold_attributes(t_master tm, int mult)
{
	while (tm.fold)
	{
		select_attributes(&(tm.stats), tm.fold->content, "");
		tm.fold = tm.fold->next;
	}
	folder_rdr(tm, mult);
}

void		file_attributes(t_master tm)
{
	while (tm.file)
	{
		select_attributes(&(tm.d_stat), tm.file->content, "");
		tm.file = tm.file->next;
	}
	if (tm.d_stat)
		write_out(tm);
}

void		unpackargs(t_flags *fl, t_list *lst, int n)
{
	DIR				*dir;
	t_master		tm;

	tm = (t_master){NULL, NULL, lst, NULL, NULL, fl};
	while (tm.lsrg)
	{
		if (!(dir = opendir(ft_strdup(tm.lsrg->content))))
		{
			(errno != ENOTDIR) ? throw_err(ft_strdup(tm.lsrg->content), 0) : \
			ft_lstpushback(&(tm.file), tm.lsrg->content, LEN(tm.lsrg->content));
		}
		else
		{
			ft_lstpushback(&(tm.fold), tm.lsrg->content, LEN(tm.lsrg->content));
			(closedir(dir) == -1) ? throw_err(tm.lsrg->content, 0) : NULL;
		}
		tm.lsrg = tm.lsrg->next;
	}
	if (tm.file)
		file_attributes(tm);
	if (tm.fold)
		fold_attributes(tm, n);
}

void		body(t_flags fl, t_list *t, int n)
{
	unpackargs(&fl, t, n);
}
