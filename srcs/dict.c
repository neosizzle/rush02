#include "ftdict.h"
#include "ftstr.h"
#include "fterr.h"

//GLOBAL VARIABLES
//g_fd yields the value of current fd
//
//g_line stores the state of current line read 
//in the .dict files
//
//g_eof will be 1 or 0 depending if the file ptr is at
//the end of the file
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

//helper func that will check if keyvalue are valid
int	is_valid_key_val(char *str)
{
	int	cnt_colon;
	int	cnt_key;
	int	cnt_val;

	cnt_colon = 0;
	cnt_key = 0;
	cnt_val = 0;
	while (*str)
	{
		if (*str == ':')
			cnt_colon++;
		else if (*str != 9 && *str != 32)
		{
			if (cnt_colon)
				cnt_val++;
			else
				cnt_key++;
		}
		str++;
	}
	return (cnt_colon == 1 && cnt_key > 0 && cnt_val > 0);
}

//helper function that will extract individual key or val
// for the 2nd arg, 0 means key and 1 means val
char	*extract (char *str, int type)
{
	char	*temp;

	temp = str;
	if (!type)
	{
		while (*temp != ':')
			temp++;
		*temp = '\0';
		return (str);
	}
	while (*temp != ':')
		temp++;
	return (++temp);
}

//helper func that will return after trimmed whitespaces the key and value
char	*trim(char *str)
{
	char	*start;
	char	*end;

	while (*str == 9 || *str == 32)
		str++;
	start = str;
	end = str;
	while (!(*end == 9 || *end == 32) && *end)
		end++;
	*end = 0;
	return (start);
}

//driver func that will make a linkedlist/bst for conversion
void	build_dict(char *dict)
{
	char	*curr_key;
	char	*curr_val;

	g_fd = open(dict, O_RDONLY);
	if (g_fd < 0)
	{
		g_read_err = 1;
		ft_putstr(READ_ERR_MSG);
		return ;
	}
	g_eof = 1;
	g_line = read_line(g_fd);
	curr_key = 0;
	curr_val = 0;
	process_line(curr_key, curr_val);
	if (!has_def_keys())
	{
		g_dict_err = 1;
		ft_putstr(BAD_DICT_ERR_MSG);
	}
}
