#include "ft_printf.h"

static t_kek	*ft_init(t_kek *kek)
{
	kek->type = 0;
	kek->width = 0;
	kek->minus = 0;
	kek->zero = 0;
	kek->precision = -1;

	return (kek);
}

char			*ft_parser(char *itr, va_list ap, t_kek *kek)
{
	int		len;
	int		tmp;

	len = 0;
	kek = ft_init(kek);
	// while (*itr)
	// {
		if (*itr == '-')
		{
			kek->minus = 1;
			itr++;
		}
		if (*itr == '0')
		{
			kek->zero = 1;
			itr++;
		}
		if (*itr == '-')
		{
			kek->minus = 1;
			itr++;
		}
		// if (ft_isdigit(*itr))
		// {
			if (*itr == '*')
			{
				tmp = va_arg(ap, int);
				if (tmp < 0)
					kek->minus = 1;
				if (tmp < 0)
					tmp *= -1;
				kek->width = tmp;
				itr++;
			}
			else if (ft_isdigit(*itr))
			{
				kek->width = ft_atoi(itr);
				while (ft_isdigit(*itr))
					itr++;
			}
		//}
		if (*itr == '.')
		{
			itr++;
			if (*itr == '*')
			{
				tmp = va_arg(ap, int);
				if (tmp < 0)
					tmp = -1;
				kek->precision = tmp;
				itr++;
			}
			else if (ft_isdigit(*itr))
			{
				kek->precision = ft_atoi(itr);
				while (ft_isdigit(*itr))
					itr++;
			}
			else
			{
				kek->precision = 0;
			}
		}
		if (ft_strchr("cspdiuxX%", *itr))
		{
			kek->type = *itr;
			itr++;
			return (itr);
		}
	// }
	return (itr);
}
