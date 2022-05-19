/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utit_node.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:57:58 by rmamison          #+#    #+#             */
/*   Updated: 2022/05/19 15:50:01 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_new_node(int	x)
{
	t_node	*new;

	new = malloc(sizeof(*new));
	if (!new)
	{
		ft_printf("Error\n Allocation memory failure\n");
		exit(1);
	}
	new->value = x;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_node	*last_node(t_list	*li)
{
	t_node	*last;
	t_node	*temp;

	temp = li->head;
	if (!li->head)
		last = NULL;
	else
	{
	  	while (temp)
		{	
			last = temp;
			temp = temp->next;
		}
	}
	return (last);
}

int	list_size(t_list *li)
{
	t_node	*actual;
   	int	ret;
	
	actual = li->head;
	ret = 0;
	while (actual != NULL)
	{
		ret++;
		actual = actual->next;
	}
	free(actual);
	actual = NULL;
	return (ret);
}

void	insert_back_list(t_list	*li, int	nbr)
{
	t_node	*news; 
	
	news = get_new_node(nbr);
	if (li->head == NULL)
	{
		li->head = news;
		li->size++;
		return ;
	}
	t_node	*temp;

	temp = li->head;
	while (temp->next != NULL)
		temp = temp->next;
	news->prev = temp;
	temp->next = news;
	li->last = temp->next;
	li->size++;
}

void	insert_front_list(t_list	*li, int	nbr)
{
	t_node	*news;

	news = get_new_node(nbr);
	if (li->head != NULL)
	{
		news->next = li->head;
		li->head = news;
		li->size++;
		return ;
	}
	li->head = news;
	li->size++;
}

void	delete_back_list(t_list	*li)
{
	if (!li->head)
		return ;
	else if (li->head->next == NULL)
	{
		free(li->head);
		li->head = NULL;
		li->size--;
		return ;
	}
	t_node	*temp;
	t_node	*before;

	temp = li->head;
	before = li->head;
	while(temp->next != NULL)
	{
		before = temp;
		temp = temp->next;
	}
	before->next = NULL;
	li->last = before;
	free(temp);
	temp = NULL;
	li->size--;
}

void	delete_front_list(t_list	*li)
{
	if (!li->head)
		return ;
	if (li->head->next == NULL)
	{
		free(li->head);
		li->head = NULL;
		li->size--;
		return;
	}
	t_node	*temp;

	temp = li->head->next;
	li->head = temp;
	temp->prev = NULL;
	free(temp->prev);
	li->size--;
}

void	clear_list(t_list *li)
{
	if (!li)
		return ;
	while (li->head != NULL)
		delete_back_list(li);
}

int	max_value(t_list	*li, int	size)
{
	t_node	*h;

	int	max;
	max  = 0;
	h = li->head;
	while (h && size--)
	{
		if (max < h->value)
			max = h->value;
		h = h->next;
	}
	return (max);
}

int	min_value(t_list	*li, int	size)
{
	t_node	*h;

	int	min;
	if (!li->head)
		return (0);
	min = li->head->value;
	h = li->head;
	while (h && size--)
	{
		if (min >= h->value)
			min = h->value;
		h = h->next;
	}
	return (min);
}

int	middle_list(t_list	*li)
{
	t_node	*slow;
	t_node	*fast;
	int	ret;

	ret = 0;
	slow = li->head;
	fast = li->head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	ret = slow->value;
	return (ret);
}

int	mid_five_sort(t_list	*li)
{
	int	value[5];
	int	i;
	int	j;
	int	swp;
	t_node	*temp;

	temp = li->head;
	i = -1;
	while (++i < 5 && temp)
	{
		value[i] = temp->value;
		temp = temp->next;
	}
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


int	check_need_sort(t_list	*li)
{
	t_node	*av;
	t_node	*aft;
	int	sort;

	av = li->head;
	aft = li->head->next;
	sort = 0;
	while (aft)
	{
		if (aft->value < av->value)
		{
			sort++;
			return (sort);
		}
		aft = aft->next;
		av = av->next;
	}
	return (sort);
}

