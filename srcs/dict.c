#include "ftdict.h"
#include "ftstr.h"
#include "fterr.h"

//GLOBAL VARIABLES
//g_fd yields the value of current fd
//
//g_line stores the state of current line read 
//in the .dict files
//
//Please declare and document any other global variables

int		g_eof;
int		g_fd;
char	*g_line;

//reads a line from a .dict file and returns said line
//allocates memory for the key:value pair
//
//set g_eof to 0 since we know that if the code reach here
// its not eof
//
//throw err if the curren len is maximum
//when encounter a \n, null and return the result
char	*read_line(int fd)
{
	int		i;
	char	*res;

	i = 0;
	res = (char *)malloc(MAX_LINE_WIDTH + 1);
	while (read(fd, &res[i], 1))
	{
		g_eof = 0;
		if (i == MAX_LINE_WIDTH)
		{
			free(res);
			g_read_err = 1;
			ft_putstr("Error : Max line width.\n");
			return (0);
		}
		if (res[i] == '\n')
		{
			res[i] = 0;
			break ;
		}
		++i;
	}
	return (res);
}

//driver func that will make a linkedlist/bst for conversion
void	build_dict(char *dict)
{
	g_fd = open(dict, O_RDONLY);
	if (g_fd < 0)
	{
		ft_putstr(READ_ERR_MSG);
		return ;
	}
	g_eof = 1;
	g_line = read_line(g_fd);
	while (g_line)
	{
		if (g_eof++)
			break ;
		ft_putstr(g_line);
		ft_putstr("\n");
		g_line = read_line(g_fd);
	}
}
