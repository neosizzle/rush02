#ifndef FTERR_H
# define FTERR_H

# define ARGC_ERR_MSG "Error: Invalid argument count\n"
# define INPUT_ERR_MSG "Error\n"
# define BAD_DICT_ERR_MSG "Dict Error\n"
# define READ_ERR_MSG "Dict Error\n"
# define MAX_LINE_ERR_MSG "Error : Max line reached\n"
# define MAX_LINE_WIDTH 1024
# define MAX_INPUT_NUM_LEN 1024
# define VALID_NUM_LEN 39

extern int	g_dict_err;
extern int	g_read_err;
extern int	g_input_num_err;

#endif 
