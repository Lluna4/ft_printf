#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

static int	ft_intlen(int n)
{
	int	ret;

	ret = 1;
	while (n >= 10)
	{
		ret++;
		n = n / 10;
	}
	return (ret);
}

int    ft_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}

int ft_putstr(char *s)
{
    int ret;

    ret = 0;
    while (*s)
    {
        ret++;
        ft_putchar(*s);
        s++;
    }
    return (ret);
}

int ft_putnbr(int n, int plus)
{
    int ret;

    if (plus >= 1)
    {
        if (n > 0)
        {
            if (plus == 1)
                ft_putchar('+');
            if (plus == 2)
                ft_putchar(' ');
        }
        ret++;
    }
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return (12);
	}
	if (n < 0)
	{
        ft_putchar('-');
		n = n * -1;
        ret++;
	}
    ret = ft_intlen(n);
	if (n >= 10)
	{
		ft_putnbr(n / 10, 0);
		n = n % 10;
	}
	if (n < 10)
		ft_putchar(n + '0');
    return (ret);
}

int flags(va_list pointer, char *args, int plus)
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
    if (*args == 's')
        ret += ft_putstr(va_arg(pointer, char *));
    if (*args == 'i')
        ret += ft_putnbr((int)va_arg(pointer, int), plus);
    if (*args == 'u')
        ret += ft_putnbr((int)va_arg(pointer, unsigned int), plus);
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
    return (ret + 1);
}

int main(void)
{
    int f = ft_printf("%i",217261);
    ft_printf("%i", f);
}