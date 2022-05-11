/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:48:44 by rmamison          #+#    #+#             */
/*   Updated: 2022/05/11 21:53:39 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

// set the pivot and place it 
t_node	*partition_list(t_node	*head, t_node *last)
{
    int	x;
    t_node	*i;
    t_node	*j;

	x = last->value;
	i = head->prev;
	j = head; 
	while (j != last)
    {
        if (j->value <= x)
        {
            if (i == NULL) 
				i = head; 
			else
				i = i->next;
			swap_stack(i, j, " ");
        }
		j = j->next;
    }
    if (i == NULL)
		i =	head;
	else
		i = i->next;
    swap_stack(i, last, " ");
    return i;
}

void _quickSort(t_node	*l, t_node	*h, t_list	*li)
{
    if (h != NULL && l != h && l != h->next)
    {
        t_node *p = partition_list(l, h);
        _quickSort(l, p->prev, li);
        _quickSort(p->next, h, li);
    }
}

void	mini_sort(t_list	*li)
{
	t_node	*head = li->head;
	t_node	*last = li->last;
	if (head->value > last->value)
	{
		if (head->value > head->next->value && \
				last->value < last->prev->value)
		{	
			rotate_stack(li, "ra");
			swap_stack(head, head->next, "sa");
		}
		else
			rotate_stack(li, "ra");
		return ;
	}
	swap_stack(head, head->next, "sa");
	//rotate_stack(li, "ra");
}

void	test(t_list	*a, t_list *b)
{
	t_node	*a_h;
	t_node	*a_l;
	//t_node	*st_b;

	a_h = a->head;
	middle_list(a); //initialize midpoint
	while (a_h && a_h != a->mid)
	{
		if (a_h->value > a_h->next->value)
			swap_stack(a_h, a_h->next, "sa");
		if (a_h->value < a->mid->value)
		{
			push_stack(b, a, "pb");
			a_h = a->head;
		}
		else
			a_h = a_h->next;
	}
	print_list(a, b);
	a_l = a->last;
	while (a_l && a_l != a->mid)
	{
		if (a_l->value < a->mid->value)
			reverse_rotate(a, "rra");
		else
		{
			a_l = a_l->prev;
			ft_printf("%d\n", a_l->value);
		}
	}
	print_list(a, b);
}
