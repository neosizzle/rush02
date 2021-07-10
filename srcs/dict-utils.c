#include "ftbst.h"
#include "ftnum.h"
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
		if (ft_strlen(key) > 10)
			continue ;
		if (g_root == NULL)
			g_root = insert_entry(g_root, ft_atoi(key), value);
		else
			insert_entry(g_root, ft_atoi(key), value);
		g_line = read_line(g_fd);
	}
}
