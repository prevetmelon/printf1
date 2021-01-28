#include "ft_printf.h"

static char		*ft_prepare_lower_upper_str(char *str, int counter,
				unsigned int buf, int capitals)
{
	if (capitals == 1)
	{
		while (buf != 0)
		{
			if ((buf % 16) < 10)
				str[counter] = (buf % 16) + 48;
			else
				str[counter] = (buf % 16) + 55;
			buf /= 16;
			counter--;
		}
	}
	else
	{
		while (buf != 0)
		{
			if ((buf % 16) < 10)
				str[counter] = (buf % 16) + 48;
			else
				str[counter] = (buf % 16) + 87;
			buf /= 16;
			counter--;
		}
	}
	return (str);
}

static char		*ft_prepare_str(unsigned int d, int capitals, char *str)
{
	unsigned long	i;
	int				counter;

	i = d;
	counter = 0;
	if (i == 0)
	{
		str = ft_strdup("0");
		return (str);
	}
	else
	{
		while (i != 0)
		{
			i /= 16;
			counter++;
		}
		i = d;
		str = malloc(sizeof(char) * (counter + 1));
		if (!str)
			return (NULL);
		str[counter] = '\0';
		str = ft_prepare_lower_upper_str(str, --counter, i, capitals);
	}
	return (str);
}

static int		ft_put_x_helper_1(t_kek *kek, char *str)
{
	int		len;

	len = 0;
	if (kek->minus == 1)
	{
		if (kek->precision >= 0)
			len += fill_width(kek->precision, ft_strlen(str), 1);
		len += fill_precision(str, ft_strlen(str));
	}
	if (kek->precision >= 0 && kek->precision < (int)ft_strlen(str))
		kek->precision = ft_strlen(str);
	if (kek->precision >= 0)
	{
		kek->width -= kek->precision;
		len += fill_width(kek->width, 0, 0);
	}
	else
		len += fill_width(kek->width, ft_strlen(str), kek->zero);
	if (kek->minus == 0)
	{
		if (kek->precision >= 0)
			len += fill_width(kek->precision, ft_strlen(str), 1);
		len += fill_precision(str, ft_strlen(str));
	}
	return (len);
}

static int		ft_put_x_helper_0(t_kek *kek, unsigned int d, int capitals)
{
	int				len;
	unsigned long	i;
	char			*str;
	int				counter;

	len = 0;
	counter = 0;
	str = NULL;
	i = d;
	if (kek->precision == 0 && d == 0)
	{
		len += fill_width(kek->width, 0, 0);
		return (len);
	}
	else
	{
		str = ft_prepare_str(i, capitals, str);
		if (!str)
			return (-1);
	}
	counter = 0;
	len += ft_put_x_helper_1(kek, str);
	free(str);
	return (len);
}

int				ft_print_x(va_list ap, t_kek *kek)
{
	int		len;
	int		d;
	int		capitals;

	len = 0;
	if (kek->type == 'x')
		capitals = 0;
	else
		capitals = 1;
	d = va_arg(ap, unsigned int);
	len += ft_put_x_helper_0(kek, d, capitals);
	return (len);
}