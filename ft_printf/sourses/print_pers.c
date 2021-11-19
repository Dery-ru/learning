#include "../includes/ft_printf.h"

int	print_pers(t_flags flag)
{
	int	len;

	len = 0;
	if (!flag.width)
	{
		len += ft_putnchar('%', 1);
		return (len);
	}
	else if (flag.dash || (flag.dash && flag.zero))
		len += ft_putnchar('%', 1) + ft_putnchar(' ', flag.width - 1);
	else if (flag.zero)
		len += ft_putnchar('0', flag.width - 1) + ft_putnchar('%', 1);
	else
		len += ft_putnchar(' ', flag.width - 1) + ft_putnchar('%', 1);
	return (len);
}
