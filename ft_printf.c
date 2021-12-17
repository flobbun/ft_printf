#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		size;
	int		i;
	va_list	list;

	size = 0;
	i = 0;
	va_start(list, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (ft_strchr("cspdiuxX", str[++i]))
			{
				size += ft_check_flag(list, str[i++]);
				continue ;
			}
		}
		size += ft_putchar(str[i++]);
	}
	va_end(list);
	return (size);
}

char	*ft_strchr(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (0);
}

int	ft_check_flag(va_list list, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(list, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(list, char *)));
	else if (c == 'p')
		return (ft_putvoid(va_arg(list, unsigned long), "0123456789abcdef", 1));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(list, int)));
	else if (c == 'u')
		return (ft_put_unsigned_nbr(va_arg(list, unsigned int)));
	else if (c == 'x')
		return (ft_puthexa(va_arg(list, unsigned int), "0123456789abcdef"));
	return (ft_puthexa(va_arg(list, unsigned int), "0123456789ABCDEF"));
}
