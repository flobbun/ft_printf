#include "ft_printf.h"

int	ft_puthexa(unsigned int n, char *base)
{
	int		size;

	size = 0;
	if (n > 15)
	{
		size += ft_puthexa((n / 16), base);
		size += ft_putchar(base[n % 16]);
	}
	else
		size += ft_putchar(base[n]);
	return (size);
}
