/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoganet <hugoganet@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:24:39 by hugoganet         #+#    #+#             */
/*   Updated: 2025/01/28 15:27:53 by hugoganet        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32 ? 1 : 0);
}

int ft_isdigit(int c)
{
	return (c >= 48 && c <= 57 ? 1 : 0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	sign;
	
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
		result = (result * 10) + str[i++] - 48;
	return (result * sign);
		
		
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("ft_atoi : %i\n", ft_atoi(av[1]));
		printf("atoi    : %i\n", atoi(av[1]));
	}
	return (0);
}