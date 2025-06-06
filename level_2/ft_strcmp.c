/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoganet <hugoganet@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:29:05 by hugoganet         #+#    #+#             */
/*   Updated: 2025/01/28 15:40:00 by hugoganet        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
    if (!s1 || !s2)
        return (s1 == s2 ? 0 : (s1 ? 1 : -1));

    while (*s1 && *s2 && *s1 == *s2)
    {
        s1++;
        s2++;		
    }
    return ((unsigned char)*s1 - (unsigned char)*s2);
}
