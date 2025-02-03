/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:17:49 by hganet            #+#    #+#             */
/*   Updated: 2025/02/03 11:35:25 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int	is_valid(char c, int base)
{
	char *digits = "0123456789abcdef";
	char *digits_upper = "0123456789ABCDEF";
	int	i;
	
	i = 0;
	while (i < base)
	{
		if (c == digits[i] || c == digits_upper[i])
			return (1);
		i++;
	}
	return (0);
}

/**
 * @brief  By subtracting the ASCII value of the base character ('0', 'a', or 'A'),
 * 		   we get the position of the character in the sequence. For letters,
 * 		   we add 10 because 'a' or 'A' represents 10 in hexadecimal.
 */
int	value_of(char c)
{
	if (c >= '0' && c <= '9')
		return (c - 48);
	else if (c >= 'a' && c <= 'f')
		return (c - 97 + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 65 + 10);
	return (0);
}

int ft_atoi_base(const char *str, int str_base)
{
	int res;
	int sign;
	int	i;
	
	if (str_base < 2 || str_base > 16)
		return (0);
	res = 0;
	sign = 1;
	i = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && is_valid(str[i], str_base))
	{
		res = res * str_base + value_of(str[i]);
		i++;
	}
	return (res * sign);
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		printf("%d", ft_atoi_base(av[1], ft_atoi_base(av[2], 10)));
	}
	return (0);
}