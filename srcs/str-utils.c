#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	ft_strlen(char *str)
{
	int	res;

	res = 0;
	while (str[res])
		res++;
	return (res);
}

void	ft_strcpy(char *dst, char *begin, char *end)
{
	int	i;

	i = 0;
	while (begin <= end)
	{
		dst[i++] = *begin;
		begin++;
	}
	*begin = 0;
}
