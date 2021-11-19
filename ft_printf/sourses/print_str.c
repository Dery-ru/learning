#include "../includes/ft_printf.h"

static int	strnlen(char *str, int n)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < n)
	{
		len += ft_putnchar(str[i], 1);
		i++;
	}
	return (i);
}

int	print_str(t_flags flag, va_list ap)
{
	int		len;
	char	*str;
	int		str_len;
	int		sp_len;

	str = va_arg(ap, char *);
	len = 0;
	if (str == NULL)
		str = "(null)";
	str_len = ft_strlen(str);
	if (flag.accuracy > flag.width)
		sp_len = flag.accuracy;
	if (flag.accuracy <= flag.width)
		sp_len = flag.width;
	if (flag.accuracy < str_len && flag.accuracy != -1 && flag.accuracy >= 0)
		str_len = flag.accuracy;
	if (flag.dash)
		len += strnlen(str, str_len) + ft_putnchar(' ', flag.width - str_len);
	else if (flag.accuracy <= str_len)
		len += ft_putnchar(' ', sp_len - str_len) + strnlen(str, str_len);
	else
		len += ft_putnchar(' ', flag.width - str_len) + strnlen(str, str_len);
	return (len);
}
