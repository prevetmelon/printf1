#include "ft_printf.h"

int		ft_print_pct(va_list ap, t_kek *kek)
{
	int		len;

	(void)ap;
	len = 0;
	if (kek->minus)
	{
		ft_putchar_fd('%', 1);
		len++;
		len += fill_width(kek->width, 1, 0);
	}
	else
	{
		len += fill_width(kek->width, 1, kek->zero);
		ft_putchar_fd('%', 1);
		len++;
	}
	return (len);
}