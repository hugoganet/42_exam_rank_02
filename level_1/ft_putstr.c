/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:47:10 by hganet            #+#    #+#             */
/*   Updated: 2025/01/24 09:54:08 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	unsigned int	i;
	
	if (!str || !*str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}