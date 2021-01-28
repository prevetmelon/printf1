#include "ft_printf.h"

int		ft_print_string(va_list ap, t_kek *kek)
{
	char	*str;
	int		len;
	char	*str_cpy;

	str = va_arg(ap, char *);
	if (!str)
		str_cpy = ft_strdup("(null)");
	else
		str_cpy = ft_strdup(str);
	str = str_cpy;
	len = 0;
	if (kek->precision != -1 && kek->precision <= (int)ft_strlen(str))
			str[kek->precision] = '\0';
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
	free(str_cpy);
	return (len);
}