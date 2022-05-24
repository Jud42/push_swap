/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utit_node.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:57:58 by rmamison          #+#    #+#             */
/*   Updated: 2022/05/24 20:12:33 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_new_node(int	x)
{
	t_node	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->value = x;
	new->pos = 0;
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
	else if (li->size == 1)
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
	temp->prev = NULL;
	free(li->head);
	li->head = temp;
	li->size--;
}

void	clear_list(t_list *li)
{
	if (!li->head)
		return ;
	while (li->head != NULL)
		delete_front_list(li);
}

int	max_value(t_list	*li, int	size)
{
	t_node	*h;

	int	max;
	max  = 0;
	h = li->head;
	while (size-- && h)
	{
		if (max < h->pos)
			max = h->pos;
		h = h->next;
	}
	return (max);
}

int	min_value(t_list	*li, int	size)
{
	t_node	*h;
	int	min;
	
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
	t_node	*temp;
	t_node	*i;
	int	sort;
	
	sort = 0;
	temp = li->head;
	while (temp && temp->next)
	{
		i = temp->next;
		while (i)
		{	
			if (temp->value == i->value)
				return (DUP);
			else if (temp->value > i->value)
				sort = true;
			i = i->next;
		}
		temp = temp->next;
	}
	return (sort);
}

