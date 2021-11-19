#include "../includes/ft_printf.h"

int	print_uns_int(t_flags flag, va_list ap)
{
	int				len;
	unsigned int	u_num;
	int				u_num_len;

	len = 0;
	u_num = va_arg(ap, unsigned int);
	if (u_num < 0)
		u_num = 4294967295 + u_num;
	u_num_len = ft_int_len(u_num);
	if (u_num == 0 && flag.accuracy == 0)
	{
		len += ft_putnchar(' ', flag.width);
		return (len);
	}
	if (flag.accuracy >= 0 && flag.accuracy < u_num_len)
		flag.accuracy = u_num_len;
	if (flag.accuracy >= 0)
		len += pos_acc((long)u_num, u_num_len, flag);
	else
		len += pos_int((long)u_num, u_num_len, flag);
	return (len);
}
