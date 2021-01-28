#include "ft_printf.h"

static int	ft_count(int n)
{
	int count;

	count = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	while (n)
	{
		if (n < 0)
		{
			n = n * -1;
			count++;
		}
		n = n / 10;
		count++;
	}
	return (count);
}

char		*ft_itoa_u(unsigned int n)
{
	char				*str;
	int					count;
	unsigned int		i;
	int					negative;

	count = ft_count(n) + 1;
	i = n;
	if (n == 4294967295)
		return (ft_strdup("4294967295"));
	negative = 1;
	if (!(str = (char *)malloc(sizeof(char) * count)))
		return (NULL);
	if (n == 0)
		str[count - 2] = '0';
	str[count - 1] = '\0';
	if (n < 0)
	{
		negative = -1;
		str[0] = '-';
	}
	while (count-- && n)
	{
		i = n % 10 * negative;
		n = n / 10;
		str[count - 1] = i + '0';
	}
	return (str);
}
