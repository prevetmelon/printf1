#include "ft_printf.h"

static char	*ft_prepare_str(int d, t_kek *kek)
{
	char	*str;
	int		len;

	str = ft_itoa_u(d);
	len = (int)ft_strlen(str);
	if (kek->precision > len)
	{
		while ((kek->precision - len) > 0)
		{
			str = ft_strjoin("0", str);
			kek->precision--;
		}
	}
	if (kek->precision == -1 && kek->zero && kek->width != 0)
	{
		len = (int)ft_strlen(str);
		while (kek->width > len)
		{
			str = ft_strjoin("0", str);
			kek->width--;
		}
	}
	if (kek->precision == 0)
		str = ft_strdup("");
	return (str);
}

int			ft_print_uint(va_list ap, t_kek *kek)
{
	unsigned int		d;
	char				*str;
	int					len;

	d = va_arg(ap, unsigned int);
	len = 0;
	str = ft_prepare_str(d, kek);
	if (kek->minus)
	{
		ft_putstr_fd(str, 1);
		len += (int)ft_strlen(str);
		len += fill_width(kek->width, (int)ft_strlen(str), 0);
	}
	else
	{
		len += fill_width(kek->width, (int)ft_strlen(str), 0);
		ft_putstr_fd(str, 1);
		len += (int)ft_strlen(str);
	}
	return (len);
}
