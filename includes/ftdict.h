#ifndef FTDICT_H
# define FTDICT_H

# include <stdlib.h>
# include <fctnl.h>

# define DEFAULT_DICT "dicts/default.dict"

typedef struct s_entry
{
	char			*key;
	char			*value;
	struct s_entry	*next;
}	t_entry;

extern t_entry	*g_head_entry;
extern int		g_is_first;
extern int		g_eof;

t_entry	*entry_create(char *key, char *value);
char	*entry_find(char *key);
void	entry_add(char *key, char *value);

void	build_dict(char *dict);
char	*read_line(int fd);

void	rush(int argc, char *argv[]);

#endif
