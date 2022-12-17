#include "ft_printf.h"

int	ft_hexlen(long long int n)
{
	int	ret;

	ret = 1;
	while (n >= 16)
	{
		ret++;
		n = n / 16;
	}
	return (ret);
}