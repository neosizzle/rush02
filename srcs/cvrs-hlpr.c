#include <unistd.h>
#include "conversion.h"
#include "ftbst.h"

void	put_str(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	handle_tens(unsigned int num)
{
	if (num <= 19)
		put_str(get_entry_value(g_root, num));
	else
	{
		put_str(get_entry_value(g_root, (num / 10) * 10));
		if (num % 10)
		{
			put_str("-");
			put_str(get_entry_value(g_root, num % 10));
		}
	}
}

void	handle_aft_mod(unsigned int num, unsigned int ten_mulp)
{
	write(1, " ", 1);
	if (num % ten_mulp > 9 && ten_mulp == 100)
		write(1, "and ", 4);
	if (num % ten_mulp > 9)
		convert_to_words(num % ten_mulp);
	else
	{
		write(1, "and ", 4);
		put_str(get_entry_value(g_root, num % ten_mulp));
	}
}

int	is_third_place(int ten_mulp)
{
	return (ten_mulp == 1000 || ten_mulp == 1000000 || ten_mulp == 1000000000);
}
