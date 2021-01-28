#include "ft_printf.h"

static char	*ft_prepare_str(long long d, t_kek *kek)
{
	char	*str;
	int		is_negative;
	int		len;

	is_negative = 0;
	//printf("str5=%d\n", d);
	if (d < 0)
	{
		is_negative = 1;
		d *= -1;
	}
	str = ft_itoa(d);
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
		if (is_negative)
			len++;
		while (kek->width > len)
		{
			str = ft_strjoin("0", str);
			kek->width--;
		}
		if (is_negative)
		{
			str = ft_strjoin("-", str);
			is_negative = 0;
		}
	}
	else if (is_negative)
			str = ft_strjoin("-", str);
	if (kek->precision == 0)
		str = ft_strdup("");
	return (str);
}


int		ft_print_int(va_list ap, t_kek *kek)
{
	int		d;
	char	*str;
	int		len;

	d = va_arg(ap, int);
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