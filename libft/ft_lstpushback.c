/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <sankosi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 15:07:49 by sankosi           #+#    #+#             */
/*   Updated: 2018/09/01 12:06:12 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstpushback(t_list **list, void *content, size_t content_size)
{
	t_list	*ptr;

	ptr = NULL;
	ptr = *list;
	if (ptr)
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = ft_lstnew(content, content_size);
	}
	else
		*list = ft_lstnew(content, content_size);
}
