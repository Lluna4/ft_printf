#include "ft_printf.h"

int ft_puthex(unsigned long n, char may)
{
    int ret;
    int sum;

    if (may == 'X')
        sum = 55;
    else
        sum = 87;
    ret = ft_hexlen(n);
    if (n >= 15)
    {
        ft_puthex(n / 16, sum);
        n = n % 16;
    }
    if (n > 9)
        ft_putchar(n + sum);
    if (n < 9)
        ft_putchar(n + '0');
    return (ret);
}