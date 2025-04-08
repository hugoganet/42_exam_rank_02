#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static void	free_words(char **words, int count)
{
	while (count--)
		free(words[count]);
	free(words);
}

static char *get_and_malloc_word(char *str)
{
	int	len;
	char *word;

	len = 0;
	while(str[len] && !(str[len] == 32 || (str[len] >= 9 && str[len] <= 13)))
		len++;
	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	word[len] = '\0'; // NULL terminate the word
	while(len--)
		word[len] = str[len];
	return (word);
}

static char **split_words(char *str, char **words)
{
	int	i;

	i = 0;
	while(*str)
	{
		if (!(*str == 32 || (*str >= 9 && *str <= 13)))
		{
			words[i] = get_and_malloc_word(str);
			if (!words[i])
			{
				free_words(words, i);
				return (NULL);
			}
			i++;
			while (*str && !(*str == 32 || (*str >= 9 && *str <= 13)))
				str++;
		}
		else
			str++;
	}
	words[i] = (0);
	return (words);
}

/**
 * A "word" is defined as a part of a string delimited either by spaces/tabs/new
 * lines, or by the start/end of the string.
 */
static int	count_words(char *str)
{
	int	in_word; // Flag
	int	word_count;

	in_word = 0;
	word_count = 0;
	while(*str)
	{
		if (!(*str == 32 || (*str >= 9 && *str <= 13)) && in_word == 0) // If we are on a 'valid' char and we are not already in a word
		{
			word_count++;
			in_word = 1;
		}
		else if (*str == 32 || (*str >= 9 && *str <= 13)) // If we are not on a 'valid' char, set flag to 0 (not in word)
			in_word = 0;
		str++;
	}
	return (word_count);
}

char	**ft_split(char *str)
{
	char	**words = NULL;
	int		word_count;

	if (!str)
		return (NULL);
	word_count = count_words(str);
	words = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	return (split_words(str, words));

}

int	main(int ac, char **av)
{
	char	*str;
	char	**words = NULL;
	int		i;

	if (ac == 2)
	{
		str = av[1];
		words = ft_split(str);
	}
	i = 0;
	while(words[i])
		printf("%s\n", words[i++]);
	return(0);
}