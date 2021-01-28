#include "ft_printf.h"

int		ft_print_char(va_list ap, t_kek *kek)
{
	int		len;
	char	c;

	c = va_arg(ap, int);
	len = 0;
	if (kek->minus)
	{
		ft_putchar_fd(c, 1);
		len++;
		len += fill_width(kek->width, 1, kek->zero);
	}
	else
	{
		len += fill_width(kek->width, 1, kek->zero);
		ft_putchar_fd(c, 1);
		len++;
	}
	return (len);
}