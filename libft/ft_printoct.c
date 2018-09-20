/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printoct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <sankosi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 07:58:50 by sankosi           #+#    #+#             */
/*   Updated: 2018/08/07 13:59:23 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BINBASE 8
#include <ft_printf.h>
#include <stdio.h>

static void		convertooct(unsigned long num, t_struct *pt)
{
	unsigned long	res;
	unsigned long	n;

	res = 0;
	n = 1;
	while (num > 0)
	{
		res = res + ((num % BINBASE) * n);
		num = num / BINBASE;
		n = n * 10;
	}
	ft_printu(res, pt);
}

static void		ft_printneg(int *bin, t_struct *pt)
{
	unsigned long	inc;
	int				i;
	unsigned long	sum;

	i = BLEN - 1;
	inc = 1;
	sum = 0;
	while (i >= 0)
	{
		if (bin[i] == 1)
			sum = sum + inc;
		inc *= 2;
		i--;
	}
	printf("%lu", sum);
	convertooct(sum, pt);
}

static void		ft_negat(int num, t_struct *pt)
{
	int		bin[BLEN];
	int		tmp;
	int		i;

	tmp = (num + 1) * -1;
	i = BLEN - 1;
	while (i >= 0)
	{
		bin[i] = tmp % 2;
		tmp = tmp / 2;
		i--;
	}
	i = 0;
	while (i <= (BLEN - 1))
	{
		if (bin[i] == 0)
			bin[i] = 1;
		else if (bin[i] == 1)
			bin[i] = 0;
		i++;
	}
	ft_printneg(bin, pt);
}

void			ft_printoct(int i, t_struct *pt)
{
	if (i >= 0)
		convertooct(i, pt);
	else if (i < 0)
		ft_negat(i, pt);
}
