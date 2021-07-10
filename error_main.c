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

int	check_unsigned(char *str)
{
	int				i;
	unsigned int	input;
	unsigned int	value;

	value = 4294967295;
	i = 0;
	input = ft_atoi(str);
	while (str[i])
	{	
		if (str[i] >= '9' && str[i] <= '0')
			return (0);
		else if (str[i] == '-')
			return (0);
		else if (str[i] == '.')
		{
			if ((str[i + 1] <= '9') && (str[i + 1] > '0'))
				if ((str[i - 1] <= '9') && (str[i - 1] >= '0'))
					return (0);
		}
		else if (input > value)
			return (0);
		i++;
	}
	return (1);
}

void	file_open(char *str)
{
}

void	print_error(void)
{
	write(1, "Error", 4);
	write(1, "\n", 1);
}

int	main(int argc, char *argv[])
{
	unsigned int	input;// im not sure if this is needed for u guys la

	if (argc == 2)
	{
		if (check_unsigned(argv[1]))
		{
			//input = ft_atoi(argv[1]);
			file_open("numbers.dict");//it will do open and storing into bst
			print_output();//output
		}
		else
			print_error();
	}
	else if (argc == 3)
	{
		if (check_unsigned(argv[2]))
			//input = ft_atoi(argv[2]);
			file_open("argv[1]");
			print_output();
		else
			print_error();
	}
	else 
		print_error();
}
