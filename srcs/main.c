#include "fterr.h"
#include "ftdict.h"

int	main(int argc, char *argv[])
{
	g_dict_err = 0;
	g_read_err = 0;
	g_input_num_err = 0;
	g_is_first = 0;
	rush (argc, argv);
	return (0);
}
