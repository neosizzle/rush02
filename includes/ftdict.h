#ifndef FTDICT_H
# define FTDICT_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define DEFAULT_DICT "dicts/numbers.dict"

typedef struct s_entry
{
	char			*key;
	char			*value;
	struct s_entry	*next;
}	t_entry;

extern t_entry	*g_head_entry;
extern int		g_is_first;
extern int		g_eof;
extern int		g_fd;
extern char		*g_line;

t_entry	*entry_create(char *key, char *value);
char	*entry_find(char *key);
void	entry_add(char *key, char *value);

void	process_line(char *key, char *value);
void	build_dict(char *dict);
char	*trim(char *str);
char	*extract(char *str, int type);
char	*read_line(int fd);
int		is_valid_key_val(char *str);

void	rush(int argc, char *argv[]);

#endif
