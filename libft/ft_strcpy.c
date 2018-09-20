/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 11:11:58 by sankosi           #+#    #+#             */
/*   Updated: 2018/06/30 21:31:08 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, const char *src)
{
	char	*d;

	d = dest;
	while (*src != '\0')
		*(dest++) = *(src++);
	*dest = '\0';
	return (d);
}
