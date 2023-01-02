/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltranca- <ltranca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:21:45 by ltranca-          #+#    #+#             */
/*   Updated: 2023/01/02 19:14:29 by ltranca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_puthex(unsigned long long n, char may, int iter)
{
    int ret;
    int sum;
    if (may == 'X')
        sum = 55;
    else
        sum = 87;
    ret = ft_hexlen(n);
    if (n >= 16)
    {
        ft_puthex(n / 16, may, iter++);
        n = n % 16;
    }
    if (n == 0 && iter == 0)
        return(ft_putchar('0'));
    if (n > 9)
        ft_putchar(n + sum);
    if (n <= 9)
        ft_putchar(n + '0');
    return (ret);
}