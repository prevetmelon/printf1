#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include "stdarg.h"

typedef struct s_kek
{
	char	type;
	int		width;
	int		minus;
	int		zero;
	int		precision;
}				t_kek;

int		ft_printf(const char *format, ...);
char	*ft_parser(char *itr, va_list ap, t_kek *kek);
int		ft_print_char(va_list ap, t_kek *kek);
int		fill_width(int width, int minus, int zero);
int		ft_decider(va_list ap, t_kek *kek);
int		ft_print_string(va_list ap, t_kek *kek);
int		ft_print_pct(va_list ap, t_kek *kek);
int		ft_print_int(va_list ap, t_kek *kek);
char	*ft_itoa_u(unsigned int n);
int		ft_print_uint(va_list ap, t_kek *kek);
int		ft_print_pointer(va_list ap, t_kek *kek);
int		fill_precision(char *str, int precision);
int		ft_print_x(va_list ap, t_kek *kek);
#endif