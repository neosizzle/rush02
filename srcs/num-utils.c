int	is_whitespace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\r' || c == '\f')
		return (1);
	return (0);
}

int	is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

unsigned int	ft_atoi(char *str)
{
	unsigned int	res;

	res = 0;
	while (is_whitespace(*str))
		str++;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		res *= 10;
		res += (*str - '0');
		str++;
	}
	return (res);
}

long long	ft_atoll(char *str)
{
	long long	pp;

	pp = 0;
	while (is_whitespace(*str))
		str++;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		pp *= 10;
		pp += (*str - '0');
		str++;
	}
	return (pp);
}
