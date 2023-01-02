/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltranca- <ltranca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:35:21 by ltranca-          #+#    #+#             */
/*   Updated: 2023/01/02 19:22:10 by ltranca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <string.h>
#include <unistd.h>

int     ft_putchar(char c);
int	    ft_intlen(long long int n);
int	    ft_hexlen(unsigned long long int n);
int     ft_putnbr(long long int n, int plus, int iter, int ret);
int     ft_putstr(char *s);
int     ft_printf(const char *args, ...);
int     ft_puthex(unsigned long long n, char may, int iter);


#endif