# include "push_swap.h"
/*
void	init_oper(t_nb_oper	*op)
{
	op->ra = 0;
	op->rb = 0;
	op->pa = 0;
	op->pb = 0;
}
*/
void	push_swap(t_list	*a, t_list	*b)
{
	int	count;
	
	count = 0;
	if (a->size == 3)
		three_sort(a);
	else if (a->size == 5)
		five_sort(a, b);
	else
		sort_a(a, b, a->size, &count);
}
