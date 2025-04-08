
#include <stdlib.h>
#include "list.h"

void ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

t_list *sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list *tmp;

	tmp = lst; // store the adress of the head so we can reset the pointer after sorting
	while (lst->next != NULL)
	{
		if (((*cmp)(lst->data, lst->next->data)) == 0)
		{
			ft_swap(&lst->data, &lst->next->data);
			lst = tmp; // reset lst to the start of the list again
		}
		else
			lst = lst->next; // if the pair is in right order, just move forward
	}
	lst = tmp;
	return (lst);
}