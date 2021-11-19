#include "../includes/ft_printf.h"

static int	manage_accuracy(const char *src, int i, t_flags *flag, va_list ap)
{
	i++;
	if (src[i] == '*')
	{
		flag->accuracy = va_arg(ap, int);
		i++;
	}
	else
	{
		flag->accuracy = 0;
		while (ft_isdigit(src[i]))
			flag->accuracy = (flag->accuracy * 10) + (src[i++] - '0');
	}
	return (i);
}

static int	manage_with_star(int i, t_flags *flag, va_list ap)
{
	flag->star = 1;
	flag->width = va_arg(ap, int);
	if (flag->width < 0)
	{
		flag->dash = 1;
		flag->width *= -1;
		flag->zero = 0;
	}
	i++;
	return (i);
}

static int	manage_with_digit(const char *src, int i, t_flags *flag)
{
	if (flag->star == 1)
		flag->width = 0;
	while (ft_isdigit(src[i]))
	{
		flag->width = (flag->width * 10) + (src[i] - '0');
		i++;
	}
	return (i);
}

static int	manage_with_dash(int i, t_flags *flag)
{
	flag->dash = 1;
	flag->zero = 0;
	i++;
	return (i);
}

int	flag_parser(const char *src, int i, t_flags *flag, va_list ap)
{
	while (src[i])
	{
		if (ft_isalpha(src[i]) || src[i] == '%'
			|| (!ft_isdigit(src[i]) && !ft_strchar("-0.*", src[i])))
			break ;
		if (src[i] == '0' && flag->width == 0 && flag->dash == 0)
		{
			flag->zero = 1;
			i++;
		}
		if (src[i] == '.')
			i = manage_accuracy(src, i, flag, ap);
		if (src[i] == '-')
			i = manage_with_dash(i, flag);
		if (src[i] == '*')
			i = manage_with_star(i, flag, ap);
		if (ft_isdigit(src[i]))
			i = manage_with_digit(src, i, flag);
	}
	return (i);
}
