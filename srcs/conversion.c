#include <unistd.h>
#include "ftbst.h"

void	convert_to_words(unsigned int num);

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
	if (!get_entry_value(ten_mulp))
	{
		while (!get_entry_value(ten_mulp))
			ten_mulp /= 10;
		return (ten_mulp);
	}
	else
		return (ten_mulp);
}

void	handle_tens(unsigned int num)
{
	if (num <= 19)
		put_str(get_entry_value(num));
	else
	{
		put_str(get_entry_value((num / 10) * 10));
		if (num % 10)
		{
			put_str("-");
			put_str(get_entry_value(num % 10));
		}
	}
}

void	convert_to_words(unsigned int num)
{
	unsigned int	highest_ten_mulp;

	highest_ten_mulp = get_highest_ten_mulp(num);
	if (num <= 9)
	{
		if (num > 0)
			put_str(get_entry_value((num)));
		return ;
	}
	if (highest_ten_mulp == 10)
	{
		handle_tens(num);
		return ;
	}
	convert_to_words(num / highest_ten_mulp);
	write(1, " ", 1);
	put_str(get_entry_value(highest_ten_mulp));
	if (num % highest_ten_mulp != 0)
	{
		write(1, " ", 1);
		if (num % highest_ten_mulp > 9)
			convert_to_words(num % highest_ten_mulp);
		else
			put_str(get_entry_value(num % highest_ten_mulp));
	}
}
