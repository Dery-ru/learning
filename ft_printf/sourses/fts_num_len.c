#include "../includes/ft_printf.h"
#include <stdio.h>

int	ft_int_len(long long num)
{
	int	num_len;

	num_len = 0;
	if (num <= 0)
	{
		num *= -1;
		num_len++;
	}
	while (num)
	{
		num = num / 10;
		num_len++;
	}
	return (num_len);
}

int	ft_hex_len(unsigned int num)
{
	int	hex_len;

	hex_len = 0;
	if (num == 0)
		hex_len++;
	while (num)
	{
		num = num / 16;
		hex_len++;
	}
	return (hex_len);
}

int	putnnbr(long int num)
{
	if (num < 0)
	{
		write(1, "-", 1);
		putnnbr(-num);
	}
	else
	{
		if (num >= 10)
			putnnbr(num / 10);
		ft_putnchar((num % 10) + '0', 1);
	}
	return (ft_int_len(num));
}
