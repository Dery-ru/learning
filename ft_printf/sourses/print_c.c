#include "../includes/ft_printf.h"

int	print_c(t_flags flag, va_list ap)
{
	int		len;
	char	c;

	len = 0;
	c = va_arg(ap, int);
	if (flag.dash)
		len += ft_putnchar(c, 1);
	len += ft_putnchar(' ', flag.width - 1);
	if (!flag.dash)
		len += ft_putnchar(c, 1);
	return (len);
}
