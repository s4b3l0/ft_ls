/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorhandle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <sankosi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 13:26:01 by sankosi           #+#    #+#             */
/*   Updated: 2018/08/31 17:32:47 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_error(char flag)
{
	ft_printf("ft_ls: illegal option -- %c\nusage: [Rlart] [file ...]\n", flag);
	exit(EXIT_FAILURE);
}

void		throw_err(char *error, unsigned int er)
{
	ft_printf("ft_ls: %s:%c%s\n", error, ' ', strerror(errno));
	if (er)
		exit(EXIT_FAILURE);
}
