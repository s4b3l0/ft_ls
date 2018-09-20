/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <sankosi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 11:49:51 by sankosi           #+#    #+#             */
/*   Updated: 2018/09/01 13:33:55 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft/includes/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <time.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>
# define MULTIDIR(x) (x != NULL)? (1) : (0)
# define LEN(x) ft_strlen(x)

typedef struct		s_flags
{
	int				l;
	int				cap_r;
	int				a;
	int				r;
	int				t;
	int				tot;
}					t_flags;

typedef	struct		s_stat
{
	struct s_stat	*next;
	char			*name;
	char			*path;
	time_t			date;
	mode_t			st_mode;
	nlink_t			st_nlin;
	uid_t			st_uid;
	gid_t			st_gid;
	dev_t			st_rdev;
	off_t			st_size;
	blkcnt_t		st_blocks;
}					t_stat;

typedef struct		s_master
{
	t_list			*fold;
	t_list			*file;
	t_list			*lsrg;
	t_stat			*stats;
	t_stat			*d_stat;
	t_flags			*fl;
}					t_master;
void				getsize(t_master tm);
void				do_recursion(t_master tm, char *path);
void				recursion(t_master tm);
int					cmp_time(t_stat *st1, t_stat *st2);
void				exchange_stat(t_stat **st1, t_stat *s2);
void				swap_stat(t_stat **st1, t_stat **st2);
void				ls_sort(t_master tm);
t_stat				*rev_list(t_stat *head);
void				ft_error(char flag);
void				write_out(t_master tm);
void				body(t_flags f, t_list *l, int n);
void				unpackargs(t_flags *fl, t_list *lst, int n);
void				select_attributes(t_stat **st, char *name, char *path);
int					select_star(t_stat **st, struct dirent *fl, char *path);
void				throw_err(char *error, unsigned int er);
void				perm_out(t_stat *m);
#endif
