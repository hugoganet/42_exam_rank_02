/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:25:09 by hganet            #+#    #+#             */
/*   Updated: 2025/01/23 18:05:46 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	unsigned int	i;
	char			*str;

	if (ac == 2)
	{
		str = av[1];
		i = 0;
		while (str[i] == 32 || str[i] == 11)
			i++;
		while (str[i] && str[i] != 32 && str[i] != 11)
			write(1, &str[i++], 1);
	}
	write(1, "\n", 1);
	return (0);
}
