#ifndef FTERR_H
# define FTERR_H

# define ARGC_ERR_MSG "Error : The count of arguments should be less than 3.\n"
# define INPUT_ERR_MSG "Input error\n"
# define BAD_DICT_ERR_MSG "Bad dict Error\n"
# define READ_ERR_MSG "Bad read Error\n"
# define MAX_LINE_WIDTH 1024
# define MAX_INPUT_NUM_LEN 1024
# define VALID_NUM_LEN 39

extern int	g_dict_err;
extern int	g_read_err;
extern int	g_input_num_err;

#endif 
