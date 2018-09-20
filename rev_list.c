/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <sankosi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 14:01:04 by sankosi           #+#    #+#             */
/*   Updated: 2018/08/31 17:58:04 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_stat		*rev_list(t_stat *head)
{
	t_stat	*now;
	t_stat	*prev;
	t_stat	*tmp;

	now = head;
	prev = NULL;
	tmp = now->next;
	while (now != NULL)
	{
		now->next = prev;
		prev = now;
		now = tmp;
		if (tmp != NULL)
			tmp = tmp->next;
	}
	return (prev);
}
