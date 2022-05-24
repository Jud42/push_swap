/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_middle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 20:16:46 by rmamison          #+#    #+#             */
/*   Updated: 2022/05/24 20:27:50 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_value(t_list *li, int size)
{
	t_node	*h;
	int		max;

	max = 0;
	h = li->head;
	while (size-- && h)
	{
		if (max < h->pos)
			max = h->pos;
		h = h->next;
	}
	return (max);
}
/*---------------------------------*/

int	min_value(t_list *li, int size)
{
	t_node	*h;
	int		min;

	min = li->head->pos;
	h = li->head;
	while (size-- && h)
	{
		if (h->pos < min)
			min = h->pos;
		h = h->next;
	}
	return (min);
}
/*------------------------------------*/

static int	mid_value(int *value, int i)
{
	int	j;

	while (--i > 0)
	{
		j = -1;
		while (++j < i)
		{
			if (value[j] > value[j + 1])
			{
				swp = value[j + 1];
				value[j + 1] = value[j];
				value[j] = swp;
			}
		}	
	}
	return (value[2]);
}

int	mid_five_sort(t_list	*li)
{
	int		i;
	int		j;
	int		swp;
	int		value[5];
	t_node	*temp;

	temp = li->head;
	i = -1;
	while (++i < 5 && temp)
	{
		value[i] = temp->value;
		temp = temp->next;
	}
	return (mid_value(value, i));
}
