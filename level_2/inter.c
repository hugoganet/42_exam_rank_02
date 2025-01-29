/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:26:25 by hganet            #+#    #+#             */
/*   Updated: 2025/01/29 13:28:38 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	int	j;
	int	lookup[256] = {0};
	
	if (ac == 3)
	{
		i = 0;
		while (av[1][i])
		{
			j = 0;
			while (av[2][j])
			{
				if (av[1][i] == av[2][j] && !lookup[(int)av[1][i]])
				{
					lookup[(int)av[2][j]] = 1;
					write(1, &av[1][i], 1);
					break ;
				}
				j++;
			}
			i++;
		}
		return (1);
	}
	write (1, "\n", 1);
	return (0);
}
