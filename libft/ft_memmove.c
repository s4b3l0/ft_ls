/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 14:21:43 by sankosi           #+#    #+#             */
/*   Updated: 2018/06/18 10:20:35 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*tmp_s;
	char		*tmp_d;
	int			x;

	x = -1;
	tmp_s = (char *)src;
	tmp_d = (char *)dst;
	if (tmp_s < tmp_d)
		while ((int)(--len) >= 0)
			tmp_d[len] = tmp_s[len];
	else
		while (++x < (int)len)
			tmp_d[x] = tmp_s[x];
	return (dst);
}
