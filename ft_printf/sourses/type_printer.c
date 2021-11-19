#include "../includes/ft_printf.h"

int	type_printer(const char *src, int i, t_flags flag, va_list ap)
{
	int	len;

	len = 0;
	if (!ft_strchar("cspdiuxX%%", src[i]))
	{
		len++;
		return (0);
	}
	if (src[i] == '%')
		len += print_pers(flag);
	else if (src[i] == 'c')
		len += print_c(flag, ap);
	else if (src[i] == 'd' || src[i] == 'i')
		len += print_int(flag, ap);
	else if (src[i] == 's')
		len += print_str(flag, ap);
	else if (src[i] == 'u')
		len += print_uns_int(flag, ap);
	else if (src[i] == 'x' || src[i] == 'X')
		len += print_hex(src, i, flag, ap);
	else if (src[i] == 'p')
		len += print_pointer(flag, ap, src, i);
	return (len);
}
