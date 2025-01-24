/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirro.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:51:46 by hganet            #+#    #+#             */
/*   Updated: 2025/01/24 18:10:01 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	is_alpha(char c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}

int	get_index(char c)
{
	int	i;

	if (c >= 65 && c <= 90)
		c += 32;
	i = 0;
	while (i < 26)
	{
		if (c == "abcdefghijklmnopqrstuvwxyz"[i])
			return (i);
		i++;
	}
	return (0);
}

int	get_mirror_index(char c)
{
	// printf("mirro index of %c = %i\n", c, 26 - get_index(c));
	return (26 - get_index(c));
}

int	main(int ac, char **av)
{
	int	i;

	if (ac == 2)
	{
		i = 0;
		while (av[1][i])
		{
			if (is_alpha(av[1][i]))
				if (av[1][i] >= 65 && av[1][i] <= 90)
					write(1, &"ABCDEFGHIJKLMNOPQRSTUVWXYZ"[get_mirror_index(av[1][i]) - 1], 1);
				else
					write(1, &"abcdefghijklmnopqrstuvwxyz"[get_mirror_index(av[1][i]) - 1], 1);
			else
				write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}