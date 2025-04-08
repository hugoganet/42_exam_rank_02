#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_space(char c)
{
	if (c == 32 || c == 9)
		return (1);
	return (0);
}

void	print_first_word(char *str, int i)
{
	while(str[i] && !is_space(str[i]))
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	rostring(char *str)
{
	int	i = 0;
	int	begin_space = 0;

	while(str[begin_space] && is_space(str[begin_space]))
		begin_space++;
	i = begin_space;
	while (str[i] && !is_space(str[i]))
		i++;
	while(str[i])
	{
		if (str[i] && !is_space(str[i]) && is_space(str[i - 1]))
		{
			while (str[i] && (i == 0 || !is_space(str[i])))
			{
				ft_putchar(str[i]);
				i++;
			}
			ft_putchar(' ');
		}
		else
			i++;
	}
	print_first_word(str, begin_space);
}

int	main(int ac, char **av)
{
	if (ac > 1)
		rostring(av[1]);
	ft_putchar('\n');
	return (0);
}