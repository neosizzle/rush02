int	is_whitespace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\r' || c == '\f')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	res;

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
