/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:31:01 by hganet            #+#    #+#             */
/*   Updated: 2025/01/30 13:01:01 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	wdmatch(char *s1, char *s2)
{
	int	i;
	int	len;

	len = 0;
	while (s1[len])
		len++;
	i = 0;
	while (i < len && *s2)
		if (s1[i] == *s2++)
			i++;
	if (i == len)
		write(1, s1, len);
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		wdmatch(av[1], av[2]);
	}
	write(1, "\n", 1);
	return (0);
}