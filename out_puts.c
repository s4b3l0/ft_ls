/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_puts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <sankosi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 18:04:20 by sankosi           #+#    #+#             */
/*   Updated: 2018/08/31 18:08:14 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void					perm_out(t_stat *m)
{
	ft_printf("%c", (S_ISFIFO(m->st_mode)) ? 'p' : '\0');
	ft_printf("%c", (S_ISCHR(m->st_mode)) ? 'c' : '\0');
	ft_printf("%c", (S_ISDIR(m->st_mode)) ? 'd' : '\0');
	ft_printf("%c", (S_ISBLK(m->st_mode)) ? 'b' : '\0');
	ft_printf("%c", (S_ISREG(m->st_mode)) ? '-' : '\0');
	ft_printf("%c", (S_ISLNK(m->st_mode)) ? 'l' : '\0');
	ft_printf("%c", (S_ISSOCK(m->st_mode)) ? 's' : '\0');
	ft_printf("%c", (m->st_mode & S_IRUSR) ? 'r' : '-');
	ft_printf("%c", (m->st_mode & S_IWUSR) ? 'w' : '-');
	ft_printf("%c", (m->st_mode & S_IXUSR) ? 'x' : '-');
	ft_printf("%c", (m->st_mode & S_IRGRP) ? 'r' : '-');
	ft_printf("%c", (m->st_mode & S_IWGRP) ? 'w' : '-');
	ft_printf("%c", (m->st_mode & S_IXGRP) ? 'x' : '-');
	ft_printf("%c", (m->st_mode & S_IROTH) ? 'r' : '-');
	ft_printf("%c", (m->st_mode & S_IWOTH) ? 'w' : '-');
	ft_printf("%c", (m->st_mode & S_IXOTH) ? 'x' : '-');
}

void					do_recursion(t_master tm, char *path)
{
	t_stat	*files;
	DIR		*dir;

	files = NULL;
	ft_putchar('\n');
	ft_putstr(path);
	ft_putstr(":\n");
	if ((dir = opendir(path)) != NULL)
	{
		while (select_star(&files, readdir(dir), \
					ft_strjoin(path, "/")) != 42)
			;
		closedir(dir);
		tm.d_stat = files;
		if (tm.d_stat)
			write_out(tm);
		files = NULL;
	}
	else
		throw_err(path, 0);
}

void					recursion(t_master tm)
{
	t_stat	*cur;

	cur = tm.d_stat;
	while (cur)
	{
		if (cur->name && cur->path && \
				S_ISDIR(cur->st_mode) && \
				ft_strcmp(".", cur->name) && \
				ft_strcmp("..", cur->name) && \
				!(tm.fl->a == 0 && cur->name[0] == '.'))
			do_recursion(tm, cur->path);
		cur = cur->next;
	}
}
