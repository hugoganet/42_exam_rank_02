#include <stdio.h>

void	swap(int *a, int *b)
{
	unsigned int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	unsigned int	bubble = 0;

	while(bubble < size)
	{
		i  = 0;
		while (i < (size - 1 - bubble))
		{
			if (tab[i] > tab[i + 1])
				swap(&tab[i], &tab[i + 1]);
			i++;
		}
		bubble++;
	}
}
int main(void)
{
	int	tab[4] = {8, 2, 4, 1};
	int	i;

	sort_int_tab(tab, 4);
	i = 0;
	while(i < 4)
		printf("%i\n", tab[i++]);
	return (0);
}