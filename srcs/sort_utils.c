/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:48:44 by rmamison          #+#    #+#             */
/*   Updated: 2022/05/12 17:01:55 by rmamison         ###   ########.fr       */
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
	ft_printf("partition %d\n=>", i->value);
    return i;
}

void _quickSort(t_node	*l, t_node	*h, t_list	*li)
{
    if (h != NULL && l != h && l != h->next)
    {
        t_node *p = partition_list(l, h);
		print_list(li, li);
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
	ft_printf("[midpoint] => %d\n", a->mid);
	while (a_h && a_h->value != a->mid)
	{
		if (a_h->value > a_h->next->value)
			swap_stack(a_h, a_h->next, "sa");
		if (a_h->value < a->mid)
		{
			push_stack(b, a, "pb");
			a_h = a->head;
		}
		else
			a_h = a_h->next;
	}
	print_list(a, b);
	a_l = a->last;
	while (a_l && a_l->value != a->mid)
	{
		if (a_l->value < a->mid)
			reverse_rotate(a, "rra");
		else
		{
			a_l = a_l->prev;
			ft_printf("%d\n", a_l->value);
		}
	}
	print_list(a, b);
}

void	part_a(t_list	*a, t_list	*b)
{
	t_node	*a_h;
	//t_node	*a_l;
	int	midp;

	a_h = a->head;
	midp = middle_list(a);
	ft_printf("midpoint => %d\n", midp);
	while (a_h && a_h->value != midp)
	{
		if (a_h->value > midp)
			rotate_stack(a, "ra");
		if (a_h->value > a_h->next->value)
			swap_stack(a_h, a_h->next, "sa");
		if (a_h->value < midp)
			push_stack(b, a, "pb");
		else
			a_h = a_h->next;
		a_h = a->head;
	}
	print_list(a, b);
}

void	_kiki(t_list	*a, t_list	*b)
{
	//t_node	*new_a = a->head;
	//t_node	*new_b = b->head;

	if (a->head)
	{
		if (check_need_sort(a))
		{
			part_a(a, b);
			_kiki(a, b);
		}
	//	else if (b->head && check_need_sort(b))
	//		part_a(a, b);		
	}
	ft_printf("finish\n");
}
