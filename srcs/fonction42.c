/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 11:58:40 by rmamison          #+#    #+#             */
/*   Updated: 2022/05/13 17:03:26 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_list	*li, char	*s)
{

	if (!li->head || !li->head->next)
		return ;
	t_node	*temp;
	t_node	*a;
	t_node	*b;
	
	a = li->head;
	b = li->head->next;
	temp = b;
	if (list_size(li) == 2)
	{
		temp = b;
		temp->prev = NULL;
		a->prev = temp;
		b = a;
		b->next = NULL;
		temp->next = b;
		li->head = temp;
	}
	else
	{
		temp = b;
		temp->prev = NULL;
		a->prev = temp;
		b = a;
		b->next = temp->next;
		b->next->prev = b;
		temp->next = b;
		li->head = temp;
	}

	ft_printf("%s\n", s);
}

void	swap_a_b(t_list	*a, t_list	*b)
{
	swap_stack(a, " ");
	swap_stack(b, " ");
	ft_printf("ss\n");
}

void	push_stack(t_list	*from, t_list	*to, char	*s)
{
	if (from->head == NULL)
		return ;
	if (from->head->next == NULL)
	{
		if (to->head == NULL)
			to->head = from->head;
		delete_front_list(from);
	}	
	else
	{
		//t_node	*temp;
		if (to->head == NULL)
		{
			to->head = from->head;
			from->head = from->head->next;
			from->head->prev = NULL;
			to->head->next = NULL;
		}
		else 
		{
			to->head->prev = from->head;
			from->head = from->head->next;
			from->head->prev = NULL;
			to->head->prev->next = to->head;
			to->head = to->head->prev;
		}
	}
	ft_printf("%s\n", s);
}

void	rotate_stack(t_list	*li, char	*s)
{
	if (li->head == NULL || li->head->next == NULL)
		return ;
	t_node	*temp;
	t_node	*temp_nxt;

	temp = li->head;
	temp_nxt = li->head->next;
	/*-------*/
	li->last->next = temp;
	temp->prev = li->last;
	temp->next = NULL;
	temp_nxt->prev = NULL;
	li->head = temp_nxt;
	li->last = temp;
	/*---------*/
	ft_printf("%s\n", s);
}

void	rotate_a_b(t_list	*a, t_list	*b, char	*s)
{
	rotate_stack(a, " ");
	rotate_stack(b, " ");
	ft_printf("%s\n", s);
}

void	reverse_rotate(t_list	*li, char	*s)
{
	if (li->head == NULL || li->head->next == NULL)
		return ;
	t_node	*temp;
	t_node	*last_prv;

	temp = li->last;
	last_prv = li->last->prev;
	/*-------*/
	li->head->prev = temp;
	temp->next = li->head;
	temp->prev = NULL;
	last_prv->next = NULL;
	li->head = temp;
	li->last = last_prv;
	/*---------*/
	ft_printf("%s\n", s);
}

void	reverse_rotate_a_b(t_list	*a, t_list	*b, char	*s)
{
	reverse_rotate(a, " ");
	reverse_rotate(b, " ");
	ft_printf("%s\n", s);
}

