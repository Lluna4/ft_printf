/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltranca- <ltranca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:35:25 by ltranca-          #+#    #+#             */
/*   Updated: 2022/12/14 17:02:25 by ltranca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int flags(va_list pointer, char *args, int plus)
{
    int ret;

    ret = 0;
    args++;
    if (*args == '+' || *args == ' ')
    {
        args++;
        if (*args == '+')
            plus = 1;
        else
            plus = 2;
    }  
    if (*args == 'c')
    {
        ft_putchar((char)va_arg(pointer, int));
        ret++;
    }
    if (*args == 'p')
    {
        ret += ft_putstr("0x");
        ret += ft_puthex((unsigned long)va_arg(pointer, void *), 0);
    }
    if (*args == 's')
        ret += ft_putstr(va_arg(pointer, char *));
    if (*args == 'i' || *args == 'd')
        ret += ft_putnbr((int)va_arg(pointer, int), plus, -1, 0);
    if (*args == 'u')
        ret += ft_putnbr((unsigned int)va_arg(pointer, unsigned int), plus, -1, 0);
    if (*args == 'x' || *args == 'X')
        ret += ft_puthex(va_arg(pointer, unsigned int), *args - 'x');
    if (*args == '%')
        ret += ft_putchar('%');
    return (ret);
}

int ft_printf(const char *args, ...)
{
    va_list pointer;
    int ret;
    
    ret = 0;
    va_start(pointer, args);
    while (*args)
    {
        if (!args)
            break ;
        if ( *args == '%')
        {
            ret += flags(pointer, (char *)args, 0);
            args++;
            if (*args == '+' || *args == ' ')
                args++;
        }
        else
        {
            ft_putchar(*args);
            ret++;
        }
        args++;
    }
    return (ret);
}
