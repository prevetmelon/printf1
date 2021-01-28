#include "ft_printf.h"

int		ft_decider(va_list ap, t_kek *kek)
{
	int		len;

	len = 0;
	if (kek->type == 'c')
		len = ft_print_char(ap, kek);
	else if (kek->type == 's')
		len = ft_print_string(ap, kek);
	else if (kek->type == '%')
		len = ft_print_pct(ap, kek);
	else if (kek->type == 'p')
		len = ft_print_pointer(ap, kek);
	else if (kek->type == 'd' || kek->type == 'i')
		len = ft_print_int(ap, kek);
	else if (kek->type == 'u')
		len = ft_print_uint(ap, kek);
	else if (kek->type == 'x' || kek->type == 'X')
		len = ft_print_x(ap, kek);
	return (len);
}