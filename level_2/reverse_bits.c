/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:22:51 by hganet            #+#    #+#             */
/*   Updated: 2025/01/30 12:29:34 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned int	i;
	unsigned char	res;

	res = 0;
	i = 8;
	while (i--)
	{
		res = (res << 1) | (octet & 1);
		octet = octet >> 1;
	}
	return (res);
}

int main(void)
{
	unsigned char bit = 0;
	unsigned char res = reverse_bits((unsigned char)5);

	int i = 8;
	while (i--)
	{
		bit = (res >> i & 1) + 48;
		printf("%c", bit);
	}
}