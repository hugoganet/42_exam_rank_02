/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoganet <hugoganet@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:41:04 by hugoganet         #+#    #+#             */
/*   Updated: 2025/01/28 15:53:22 by hugoganet        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i] && reject[j])
			if (s[i] == reject[j++])
				return (i);
		i++;
	}
	return (i);
}

int main()
{
	const char *s = "hello, world";
	const char *reject = " ,";
	size_t len = strcspn(s, reject);
	printf("Length of initial segment: %zu\n", len); // Output: 5
	return 0;
}