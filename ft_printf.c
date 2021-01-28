#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int		len;
	char	*itr;
	va_list	ap;
	t_kek	kek;

	va_start(ap, format);

	len = 0;
	itr = (char *)format;
	while (*itr)
	{
		if (*itr == '%')
		{
			itr++;
			itr = ft_parser(itr, ap, &kek);
			len += ft_decider(ap, &kek);
			continue ;
		}
		ft_putchar_fd(*itr, 1);
		len++;
		itr++;
	}
	va_end(ap);
	return (len);
}