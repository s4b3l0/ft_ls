/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <sankosi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 10:07:11 by sankosi           #+#    #+#             */
/*   Updated: 2018/08/31 15:50:03 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# define BLEN 32
# define ABS(x)	(x < 0) ? -(x) : (x)
# define CHECK_CHR(x) if (x == 'c') ft_printchar(va_arg(pt->ls, int))
# define YES 'y'
# define NO 'n'
# define LEFT 'l'
# define RIGHT 'r'

typedef struct					s_struct
{
	int							pad;
	int							pos;
	char						hash;
	int							zpad;
	va_list						ls;
	int							lr;
	int							put;
	int							res;
	char						*form;
	char						type;
	int							pres;
}								t_struct;
void							initialize(t_struct *p);
char							*negcheck(char *bin, int num);
void							ft_printx(unsigned int i, t_struct *pt);
int								ft_printf(const char *format, ...);
void							ft_printinteger(int i, t_struct *pt);
void							ft_printu(unsigned long nbr, t_struct *pt);
void							ft_putpad(int n, t_struct *p);
void							ft_printstr(char *s, t_struct *pt);
void							ft_printchar(char s);
void							ft_printoct(int i, t_struct *pt);
void							ft_printu(unsigned long nbr, t_struct *pt);
void							ft_putunsigned(unsigned long n);
int								ft_printh(t_struct *pt, char *str, int i);
int								ft_printl(t_struct *pt, char *str, int i);
void							ft_putmax(__int128_t n);
void							ft_printmax(__int128_t nbr, t_struct *pt);
int								ft_printm(t_struct *pt, char *str, int i);
void							initialize(t_struct *p);
void							ft_printptr(unsigned long num, t_struct *pt);
#endif
