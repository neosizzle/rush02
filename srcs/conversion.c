#include <unistd.h>
#include "ftbst.h"
#include "cvrs_hlpr.h"

void	convert_to_words(unsigned int num);

unsigned int	get_highest_ten_mulp(unsigned int value)
{
	unsigned int	ten_mulp;
	unsigned int	temp;

	ten_mulp = 1;
	temp = value;
	while (temp > 9)
	{
		temp /= 10;
		ten_mulp *= 10;
	}
	if (!get_entry_value(g_root, ten_mulp))
	{
		while (!get_entry_value(g_root, ten_mulp))
			ten_mulp /= 10;
		return (ten_mulp);
	}
	else
		return (ten_mulp);
}

void	convert_to_words(unsigned int num)
{
	unsigned int	highest_ten_mulp;

	highest_ten_mulp = get_highest_ten_mulp(num);
	if (num <= 9)
	{
		put_str(get_entry_value(g_root, (num)));
		return ;
	}
	if (highest_ten_mulp == 10)
	{
		handle_tens(num);
		return ;
	}
	convert_to_words(num / highest_ten_mulp);
	write(1, " ", 1);
	put_str(get_entry_value(g_root, highest_ten_mulp));
	if (num % highest_ten_mulp != 0)
	{
		if (is_third_place(highest_ten_mulp))
			write(1, ",", 2);
		handle_aft_mod(num, highest_ten_mulp);
	}
}
