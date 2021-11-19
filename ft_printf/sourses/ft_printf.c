#include "../includes/ft_printf.h"

static t_flags	flags_init(void)
{
	t_flags	flag;

	flag.dash = 0;
	flag.zero = 0;
	flag.width = 0;
	flag.star = 0;
	flag.accuracy = -1;
	flag.space = 0;
	return (flag);
}

int	ft_printf(const char *src, ...)
{
	va_list	ap;
	int		i;
	int		temp;
	int		len_str;
	t_flags	flag;

	va_start(ap, src);
	i = -1;
	len_str = 0;
	while (src[++i])
	{
		flag = flags_init();
		if (src[i] != '%')
			len_str += ft_putnchar(src[i], 1);
		else if (src[i] == '%')
		{
			i = flag_parser(src, ++i, &flag, ap);
			temp = type_printer(src, i, flag, ap);
			len_str += temp;
			if (temp == 0 && !src[i] && len_str == 0)
				return (0);
		}
	}
	va_end(ap);
	return (len_str);
}
