/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:45:25 by hganet            #+#    #+#             */
/*   Updated: 2025/01/30 14:56:12 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	snake_to_camel(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '_')
		{
			i++;
			continue ;		
		}
		if (i > 0 && s[i - 1] == '_')
			s[i] -= 32;
		write (1, &s[i], 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		snake_to_camel(av[1]);
	}
	write(1, "\n", 1);
	return (0);
}