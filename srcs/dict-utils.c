#include "ftstr.h"
#include "ftdict.h"
#include "fterr.h"

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
		//bst_insert(char *key, char *value);
		ft_putstr("key : ");
		ft_putstr(key);
		ft_putstr("val : ");
		ft_putstr(value);
		ft_putstr("\n");
		g_line = read_line(g_fd);
	}
}
