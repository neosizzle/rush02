#include "ftbst.h"
#include "fterr.h"
#include "ftdict.h"
#include "ftnum.h"
#include "ftstr.h"

int	is_valid_unsigned(char *str)
{
	int			i;
	long long	res;

	i = 0;
	res = 0;
	while (is_whitespace(*str))
		str++;
	while (i < ft_strlen(str))
	{
		if (!is_numeric(str[i]))
			return (0);
		i++;
	}
	res = ft_atoll(str);
	if (res > 4294967295)
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	char	*num;

	g_dict_err = 0;
	g_read_err = 0;
	g_input_num_err = 0;
	g_is_first = 0;
	g_root = NULL;
	if (argc == 2 || argc == 3)
	{
		if (argc == 2)
			num = argv[1];
		else
			num = argv[2];
		if (!is_valid_unsigned(num))
		{
			ft_putstr("Error\n");
			return (1);
		}
		rush (argc, argv);
		return (0);
	}
	else
		ft_putstr("Error\n");
	return (1);
}
