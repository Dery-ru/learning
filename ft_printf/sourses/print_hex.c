#include "../includes/ft_printf.h"
#include <stdio.h>

int	putnhex(unsigned long long dec, char str)
{
	static int		i;
	char			*up_hex_alp;
	char			*hex_alp;

	up_hex_alp = "0123456789ABCDEF";
	hex_alp = "0123456789abcdef";
	i = 0;
	if (dec >= 16)
		putnhex(dec / 16, str);
	if (str == 'X')
		i += ft_putnchar(up_hex_alp[(unsigned int)dec % 16], 1);
	else if (str == 'x')
		i += ft_putnchar(hex_alp[(unsigned int)dec % 16], 1);
	else if (str == 'p')
	{
		if (i == 0)
			i += ft_putnchar('0', 1) + ft_putnchar('x', 1);
		if (i > 1)
			i += ft_putnchar(hex_alp[(unsigned int)dec % 16], 1);
	}
	return (i);
}

int	pos_acc_hex(unsigned long long hex, int hex_len, t_flags flag, char src)
{
	int	len;

	len = 0;
	if (flag.zero && !flag.accuracy && !flag.dash)
	{
		len += ft_putnchar('0', flag.width - hex_len)
			+ putnhex((unsigned long long)hex, src);
		return (len);
	}
	if (flag.dash)
		len += ft_putnchar('0', flag.accuracy - hex_len) + putnhex(hex, src);
	len += ft_putnchar(' ', flag.width - flag.accuracy);
	if (!flag.dash)
		len += ft_putnchar ('0', flag.accuracy - hex_len) + putnhex(hex, src);
	return (len);
}

int	neg_acc_hex(unsigned long long hex, int hex_len, t_flags flag, char src)
{
	int	len;

	len = 0;
	if (flag.width && flag.dash)
		len += putnhex(hex, src)
			+ ft_putnchar(' ', flag.width - hex_len);
	else if (flag.width && flag.zero)
		len += ft_putnchar('0', flag.width - hex_len)
			+ putnhex(hex, src);
	else if (flag.width)
		len += ft_putnchar(' ', flag.width - hex_len)
			+ putnhex(hex, src);
	else
		len += putnhex(hex, src);
	return (len);
}

int	print_hex(const char *src, int i, t_flags flag, va_list ap)
{
	int				len;
	unsigned int	hex;
	int				hex_len;

	len = 0;
	hex = va_arg(ap, unsigned int);
	if ((long int)hex < 0)
		hex = hex - 1;
	if (hex == 0 && flag.accuracy == 0)
	{
		len += ft_putnchar(' ', flag.width);
		return (len);
	}
	hex_len = ft_hex_len(hex);
	if (flag.accuracy >= 0 && flag.accuracy < hex_len)
		flag.accuracy = hex_len;
	if (flag.accuracy >= 0)
		len += pos_acc_hex((unsigned long long)hex, hex_len, flag, src[i]);
	if (flag.accuracy < 0)
		len += neg_acc_hex((unsigned long long)hex, hex_len, flag, src[i]);
	return (len);
}
