# include "push_swap.h"


void	push_swap(t_list	*a, t_list	*b)
{
	int	count;
	
	count = 0;

	if (a->size == 5)
		five_sort(a, b);
	else
		sort_a(a, b, a->size, &count);
}
