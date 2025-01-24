/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:11:01 by hganet            #+#    #+#             */
/*   Updated: 2025/01/24 10:57:09 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	is_alpha(char c)
{
	if ((c >= 65 && c <= 90) ||  (c >= 97 && c <= 122))
		return (1);
	return (0);
}

void	ft_put_repeat_alpha(char c, int repetition)
{
	int i;

	i = 0;
	while (i < repetition)
	{
		write(1, &c, 1);
		i++;
	}
}

char	to_lower_case(char c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	else
		return (c);
}

int	get_repetition(char c)
{
	int		i;
	char	low_c;

	low_c = to_lower_case(c);
	i = 0;
	while (i < 26)
	{
		if (low_c == "abcdefghijklmnopqrstuvwxyz"[i])
			return (i + 1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	unsigned int	i;
	
	if (ac == 2)
	{
		i = 0;
		while (av[1] && av[1][i])
		{
			if (is_alpha(av[1][i]))
				ft_put_repeat_alpha(av[1][i], get_repetition(av[1][i]));
			else
				write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}