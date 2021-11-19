#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_flags
{
	int		dash;
	int		zero;
	int		width;
	int		star;
	int		accuracy;
	int		space;	
}				t_flags;

int		ft_printf(const char *src, ...);
int		ft_isalpha(char c);
int		ft_isdigit(char c);
size_t	ft_strlen(const char *str);
int		ft_putnchar(char c, int n);
char	*ft_strchar(const char *str, int c);
int		flag_parser(const char *src, int i, t_flags *flag, va_list ap);
int		type_printer(const char *src, int i, t_flags flag, va_list ap);
int		print_pers(t_flags flag);
int		print_c(t_flags flag, va_list ar);
int		print_int(t_flags flag, va_list ap);
int		print_str(t_flags flag, va_list ap);
int		print_uns_int(t_flags flag, va_list ap);
int		print_hex(const char *src, int i, t_flags flag, va_list ap);
int		ft_int_len(long long num);
int		putnnbr(long int num);
int		with_dash(long num, int num_len, t_flags flag);
int		without_dash(long num, int num_len, t_flags flag);
int		pos_acc(long num, int num_len, t_flags flag);
int		pos_int(long num, int num_len, t_flags flag);
int		putnhex(unsigned long long dec, char str);
int		ft_hex_len(unsigned int num);
int		pos_acc_hex(unsigned long long hex,
			int hex_len, t_flags flag, char src);
int		neg_acc_hex(unsigned long long hex,
			int hex_len, t_flags flag, char src);
int		len_ptr(unsigned long long num);
int		print_pointer(t_flags flag, va_list ap, const char *str, int i);

#endif