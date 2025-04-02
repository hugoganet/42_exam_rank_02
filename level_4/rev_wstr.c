#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_space(char c)
{
	if (c == 9 || c == 32)
		return (1);
	return (0);
}

void	rev_wstr(char * str)
{
	int	i; // use to decrement
	int	j; // use for each word
	int	first_word; // flag

	i = 0;
	first_word = 1;
	while(str[i])
		i++; // goes to the end of the string
	while(i >= 0) // goes to beginning of the string
	{
		while(i >= 0 && (str[i] == '\0' || is_space(str[i])))
			i--; // skip the '\0' and spaces at the end of the string
		j = i; // j is now the end of the last word
		while(j >= 0 && !is_space(str[j]))
			j--; // goes to the begining of the string of a space
		if (first_word == 0)
			ft_putchar(' ');
		write(1, str + j + 1, i - j);
		first_word = 0; // stays 0 after we've printed a word
		i = j; // set i to the begining of string or a space
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		rev_wstr(av[1]);
	ft_putchar('\n');
	return (0);
}