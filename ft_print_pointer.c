#include "ft_printf.h"

int		ft_print_pointer(va_list ap, t_kek *kek)
{
	int				len;
	int				counter;
	char			*str;
	unsigned long	d;
	unsigned long	buf;

	d = va_arg(ap, unsigned long);
	len = 0;
	counter = 0;
	buf = d;
	if (d == 0 && kek->precision == 0)
	{
		ft_putstr_fd("0x", 1);
		len += 2;
		len += fill_width(kek->width, 0, 1);
		return (len);
	}
	else
	{
		if (d == 0)
		{
			str = ft_strdup("0");
		}
		else
		{
			while (d != 0)
			{
				d /= 16;
				counter++;
			}
			str = (char *)malloc(sizeof(char) * (counter + 1));
			str[counter] = '\0';
			counter--;
			while (buf != 0)
			{
				if (buf % 16 < 10)
				{
					str[counter] = buf % 16 + 48;
				}
				else
				{
					str[counter] = buf % 16 + 87;
				}
				buf /= 16;
				counter--;
			}
		}
		counter = 0;
		if (kek->minus == 0)
		{
			len += fill_width(kek->width, ft_strlen(str) + 2, kek->zero);
			len += fill_precision("0x", 2);
			if (kek->precision >= 0)
			{
				len += fill_width(kek->precision - 1, ft_strlen(str), kek->zero);
				len += fill_precision(str, kek->precision);
			}
			else
				len += fill_precision(str, ft_strlen(str));
		}
		else
		{
			len += fill_precision("0x", 2);
			if (kek->precision >= 0)
			{
				len += fill_width(kek->precision - 1, ft_strlen(str), kek->zero);
				len += fill_precision(str, kek->precision);
			}
			else
			len += fill_precision(str, ft_strlen(str));
			len += fill_width(kek->width, ft_strlen(str) + 2, kek->zero);
		}
	}
	return (len);
}
