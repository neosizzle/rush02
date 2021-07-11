#include "ftbst.h"
#include "ftnum.h"
#include "ftstr.h"
#include "ftdict.h"
#include "fterr.h"
#include <stdio.h>

unsigned int	g_d_0[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
unsigned int	g_d_1[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
unsigned int	g_d_2[] = {20, 30, 40, 50, 60, 70, 80, 90, 100, 1000};

//this helper function helps generate numbers that
//represents powers of 10
unsigned int	get_power_int(int i)
{
	unsigned int	res;

	res = 1;
	while (i-- > 0)
		res *= 10;
	return (res);
}

//this helper function returns 1 if 
//all the required keys exist in the dict
int	has_def_keys(void)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (get_entry_value(g_root, g_d_0[i]) == NULL
			 || get_entry_value(g_root, g_d_1[i]) == NULL
			 || get_entry_value(g_root, g_d_2[i]) == NULL)
			return (0);
		i++;
	}
	i = 3;
	while (i <= 9)
	{
		if (get_entry_value(g_root, get_power_int(i)) == NULL)
			return (0);
		i += 3;
	}
	return (1);
}

void	process_line(char *key, char *value)
{
	while (g_line)
	{
		if (g_eof++)
			break ;
		if (ft_strlen(g_line) == 0)
		{
			g_line = read_line(g_fd);
			continue ;
		}
		if (!is_valid_key_val(g_line))
		{
			g_read_err = 1;
			ft_putstr(BAD_DICT_ERR_MSG);
			break ;
		}
		value = trim(extract(g_line, 1));
		key = trim(extract(g_line, 0));
		if (ft_strlen(key) > 10)
			continue ;
		if (g_root == NULL)
			g_root = insert_entry(g_root, ft_atoi(key), value);
		else
			insert_entry(g_root, ft_atoi(key), value);
		g_line = read_line(g_fd);
	}
}
