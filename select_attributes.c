/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_attributes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <sankosi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 14:14:44 by sankosi           #+#    #+#             */
/*   Updated: 2018/08/31 18:09:42 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_stat		*populate_stats(char *name, char *path)
{
	t_stat		*stp;
	struct stat fstat;

	stp = (t_stat *)malloc(sizeof(t_stat));
	stp->name = ft_strdup(name);
	stp->path = ft_strjoin(path, name);
	if (lstat(stp->path, &fstat) == -1)
	{
		throw_err(stp->name, 1);
		return (NULL);
	}
	stp->st_mode = fstat.st_mode;
	stp->st_nlin = fstat.st_nlink;
	stp->st_uid = fstat.st_uid;
	stp->st_gid = fstat.st_gid;
	stp->st_size = fstat.st_size;
	stp->st_rdev = fstat.st_rdev;
	stp->st_blocks = fstat.st_blocks;
	stp->date = fstat.st_mtime;
	stp->next = NULL;
	return (stp);
}

int			select_star(t_stat **st, struct dirent *fl, char *path)
{
	t_stat		*ptr;

	ptr = NULL;
	ptr = *st;
	if (!fl)
		return (42);
	if (ptr)
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = populate_stats(fl->d_name, path);
	}
	else
		*st = populate_stats(fl->d_name, path);
	return (1);
}

void		select_attributes(t_stat **st, char *name, char *path)
{
	t_stat	*ptr;

	ptr = NULL;
	ptr = *st;
	if (ptr)
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = populate_stats(name, path);
	}
	else
		*st = populate_stats(name, path);
}
