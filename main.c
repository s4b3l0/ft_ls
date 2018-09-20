/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <sankosi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 11:45:14 by sankosi           #+#    #+#             */
/*   Updated: 2018/09/01 11:22:46 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			grabflags(char *str, t_flags *fl)
{
	int		i;

	i = 0;
	while (str[++i] != '\0')
	{
		if (str[i] == 'l')
			fl->l = 1;
		else if (str[i] == 'R')
			fl->cap_r = 1;
		else if (str[i] == 'a')
			fl->a = 1;
		else if (str[i] == 'r')
			fl->r = 1;
		else if (str[i] == 't')
			fl->t = 1;
		else
			ft_error(str[i]);
	}
}

static void			save_prms(t_list **list, t_flags *fl, char **strar)
{
	int i;

	i = 0;
	while (strar[i + 1])
	{
		if (strar[i + 1][0] == '-')
			grabflags(strar[i + 1], fl);
		else if (strar[i + 1])
			ft_lstpushback(list, strar[1 + i], ft_strlen(strar[i + 1]));
		i++;
	}
}

int					main(int ac, char **av)
{
	t_flags		fl;
	t_list		*lst;

	fl = (t_flags){0, 0, 0, 0, 0, 0};
	lst = NULL;
	if (ac > 1)
		save_prms(&lst, &fl, av);
	if (lst == NULL)
		lst = ft_lstnew(".", 1);
	body(fl, lst, MULTIDIR(lst->next));
	return (0);
}
