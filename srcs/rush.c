#include "ftbst.h"
#include "fterr.h"
#include "ftdict.h"
#include "ftstr.h"

//GLOAL VARIABLES
//g_*_error are error varlables. 1 or 0.
// if they are 1, which means there is an err
//
//g_eof marks the end of file while parsing. 
// 1 means end of file, 0 means otherwise
//
//g_head_entry is the head of  dictionary extracted from the
// .dict file.
//contains all keys and values.
//
//g_is_first states if teh current entry is the first entry.
// 1 if its is, 0 otherwise
//
//Please document and declare other variables if needed.
//t_entry	*g_head_entry;
int		g_is_first;
int		g_dict_err;
int		g_read_err;
int		g_input_num_err;

//check for errors and trim input
//1. checks for valid num of arguments
//   and throw err if num of args invalid (done) - jng
// 2. build dictionary depends on the num of args
// 3. trim the input, calculate and display output

void	rush(int argc, char *argv[])
{
	if (argc > 3)
	{
		ft_putstr(ARGC_ERR_MSG);
		return ;
	}
	else if (argc == 3)
		build_dict(argv[1]);
	else
		build_dict(DEFAULT_DICT);
	//dict now built, math logic goes here
}
