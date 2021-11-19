#include "../includes/ft_printf.h"

int	with_dash(long num, int num_len, t_flags flag)
{
	int	len;

	len = 0;
	num *= -1;
	num_len--;
	len = ft_putnchar('-', 1) + ft_putnchar('0', flag.accuracy - num_len)
		+ putnnbr(num);
	if (flag.accuracy > 0)
		len += ft_putnchar(' ', flag.width - flag.accuracy - 1);
	else
		len += ft_putnchar(' ', flag.width - num_len - 1);
	return (len);
}

int	without_dash(long num, int num_len, t_flags flag)
{
	int	len;

	len = 0;
	num *= -1;
	if (flag.zero && flag.accuracy < 0)
		len += ft_putnchar('-', 1)
			+ ft_putnchar('0', flag.width - num_len) + putnnbr(num);
	else if (flag.zero && flag.accuracy >= num_len)
	{
		num_len--;
		len += ft_putnchar(' ', flag.width - flag.accuracy - 1)
			+ ft_putnchar('-', 1) + ft_putnchar('0', flag.accuracy - num_len)
			+ putnnbr(num);
	}
	else if (flag.zero && flag.accuracy < num_len)
		len += ft_putnchar(' ', flag.width - num_len)
			+ ft_putnchar('-', 1) + putnnbr(num);
	else
	{
		num_len--;
		len += ft_putnchar(' ', flag.width - flag.accuracy - 1)
			+ ft_putnchar('-', 1) + ft_putnchar('0', flag.accuracy - num_len)
			+ putnnbr(num);
	}
	return (len);
}

int	pos_acc(long num, int num_len, t_flags flag)
{
	int	len;

	len = 0;
	if (flag.zero && !flag.accuracy && !flag.dash)
	{
		len += ft_putnchar('0', flag.width - num_len) + putnnbr(num);
		return (len);
	}
	if (flag.dash)
		len += ft_putnchar('0', flag.accuracy - num_len) + putnnbr(num);
	len += ft_putnchar(' ', flag.width - flag.accuracy);
	if (!flag.dash)
		len += ft_putnchar('0', flag.accuracy - num_len) + putnnbr(num);
	return (len);
}

int	pos_int(long num, int num_len, t_flags flag)
{
	int	len;

	len = 0;
	if (flag.accuracy >= 0 && flag.accuracy < num_len)
		flag.accuracy = num_len;
	if (flag.accuracy >= 0)
		len += pos_acc(num, num_len, flag);
	else if (flag.accuracy < 0)
	{
		if (flag.width && flag.dash)
			len += putnnbr(num) + ft_putnchar (' ', flag.width - num_len);
		else if (flag.width && flag.zero)
			len += ft_putnchar('0', flag.width - num_len) + putnnbr(num);
		else if (flag.width)
			len += ft_putnchar(' ', flag.width - num_len) + putnnbr(num);
		else
			len += putnnbr(num);
	}
	else
		len += putnnbr(num) + ft_putnchar(' ', flag.width - num_len);
	return (len);
}

int	print_int(t_flags flag, va_list ap)
{
	int		len;
	long	num;
	int		num_len;

	len = 0;
	num = va_arg(ap, int);
	num_len = ft_int_len(num);
	if (flag.space == 1 && num > 0)
		len += ft_putnchar(' ', 1);
	if (num == 0 && flag.accuracy == 0)
	{
		len += ft_putnchar(' ', flag.width);
		return (len);
	}
	if (num < 0 && (flag.zero == 1 || flag.accuracy >= num_len))
	{
		if (flag.dash)
			len += with_dash(num, num_len, flag);
		if (!flag.dash)
			len += without_dash(num, num_len, flag);
		return (len);
	}
	len += pos_int(num, num_len, flag);
	return (len);
}
