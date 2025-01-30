/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:00:01 by hganet            #+#    #+#             */
/*   Updated: 2025/01/30 15:52:05 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(long int sum)
{
	unsigned long int	nb;

	if (sum < 0)
	{
		ft_putchar('-');
		nb = -sum;
	}
	else
		nb = sum;
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar(nb %10 + '0');
}

int	ft_atoi(char *str)
{
	int	res;
	int sign;
	int	i;

	res = 0;
	i = 0;
	while (str[i] == 32 || str[i] == 9)
		i++;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] && str[i] >= 48 && str[i] <= 57)
		res = (res * 10) + str[i++] - 48;
	return (res * sign);
}

int	is_prime(int nbr)
{
	int	i;
	
	if (nbr < 2)
		return (0);
	i = 2;
	while (i * i <= nbr)
	{
		if (nbr % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int			nbr;
	long int	sum;

	if (ac != 2 || ft_atoi(av[1]) <= 0)
	{
		write(1, "0\n", 2);
		return (0);
	}
	nbr = ft_atoi(av[1]);
	sum = 0;
	while (nbr > 1)
	{
		if (is_prime(nbr))
			sum += nbr;
		nbr--;
	}
	ft_putnbr(sum);
	write(1, "\n", 1);
	return (0);
}