# include "push_swap.h"

int	need_oper(t_list	*li, int	size)
{
	int	min;
	int	max;
	int	continuous;

	continuous = 0;
	min = min_value(li, size);
	max = max_value(li, size);
	if (li->last->value == min)
		reverse_rotate(li, A);
	else if (li->head->value == max)
		rotate_stack(li, A);
	if (check_need_sort(li))
		continuous = 1;
	return (continuous);
}

void	push_swap(t_list	*a, t_list	*b)
{
	int	count;
	
	count = 0;
	if (!need_oper(a, a->size))
		return ;
	if (a->size < 6)
		little_sort(a, b);
	else
		sort_a(a, b, a->size, &count);
}
