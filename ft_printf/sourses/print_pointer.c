#include "../includes/ft_printf.h"

int	len_ptr(unsigned long long num)
{
	int	len;

	len = 2;
	if (num == 0)
		len++;
	while (num != 0)
	{
		num /= 16;
		len++;
	}
	return (len);
}

int	print_pointer(t_flags flag, va_list ap, const char *str, int i)
{
	int					len;
	unsigned long long	num;
	int					p_len;

	len = 0;
	num = (unsigned long long)va_arg(ap, void *);
	p_len = len_ptr(num);
	if (num == 0 && flag.accuracy == 0)
		len += ft_putnchar(' ', flag.width - 2)
			+ ft_putnchar('0', 1) + ft_putnchar('x', 1);
	else if (flag.accuracy >= 0 && flag.accuracy < p_len)
		flag.accuracy = p_len;
	else if (flag.accuracy >= 0)
		len += pos_acc_hex(num, p_len, flag, str[i]);
	else if (flag.accuracy < 0)
		len += neg_acc_hex(num, p_len, flag, str[i]);
	return (len);
}
