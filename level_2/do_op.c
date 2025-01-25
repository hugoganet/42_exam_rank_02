/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoganet <hugoganet@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:11:43 by hugoganet         #+#    #+#             */
/*   Updated: 2025/01/25 18:27:45 by hugoganet        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int	n1;
	int n2;
	
	if (ac == 4)
	{
		n1 = atoi(av[1]);
		n2 = atoi(av[3]);
		if (av[2][0] == '+')
			printf("%i\n", n1 + n2);
		else if (av[2][0] == '-')
			printf("%i\n", n1 - n2);
		else if (av[2][0] == '*')
			printf("%i\n", n1 * n2);
		else if (av[2][0] == '/')
			printf("%i\n", n1 / n2);
	}
	else
		write(1, "\n", 1);
	return (0);
}