/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:48:44 by rmamison          #+#    #+#             */
/*   Updated: 2022/05/10 20:58:34 by rmamison         ###   ########.fr       */
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
