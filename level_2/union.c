/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:02:17 by hganet            #+#    #+#             */
/*   Updated: 2025/01/30 14:37:45 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_union(char *s)
{
	int	i;
	static unsigned int lookup[256] = {0};

	i = 0;
	while (s[i])
	{
		if (lookup[(unsigned int)s[i]] == 0)
		{
			lookup[(unsigned int)s[i]] = 1;
			write(1, &s[i], 1);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		ft_union(av[1]);
		ft_union(av[2]);
	}
	write(1, "\n", 1);
	return (0);
}