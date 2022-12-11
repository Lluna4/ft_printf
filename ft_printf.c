#include <stdarg.h>
#include <string.h>
#include <unistd.h>


void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int        ft_putstr(char *s)
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

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		n = n % 10;
	}
	if (n < 10)
		ft_putchar(n + '0');
}

int flags(va_list pointer, char *args, int ret)
{
    args++;
    if (*args == 'c')
    {
        ft_putchar((char)va_arg(pointer, int));
        ret++;
    }
    if (*args == 's')
        ret += ft_putstr(va_arg(pointer, char *));
    if (*args == 'i')
        ft_putnbr((long int)va_arg(pointer, int));
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
            ret = flags(pointer, (char *)args, ret);
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

int main(void)
{
    ft_printf("%s %i", "auisgays", 217261 + 1);
}