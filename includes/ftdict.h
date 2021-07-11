#ifndef FTDICT_H
# define FTDICT_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define DEFAULT_DICT "dicts/numbers.dict"

extern int		g_is_first;
extern int		g_eof;
extern int		g_fd;
extern char		*g_line;

void	process_line(char *key, char *value);
void	build_dict(char *dict);
char	*trim(char *str);
char	*extract(char *str, int type);
char	*read_line(int fd);

int		has_def_keys(void);
int		is_valid_key_val(char *str);

void	rush(int argc, char *argv[]);

#endif
