/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 11:58:40 by rmamison          #+#    #+#             */
/*   Updated: 2022/05/19 21:06:58 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_list	*li, int	flag)
{

	if (!li->head || !li->head->next)
		return ;
	t_node	*a;
	t_node	*b;
	
	a = li->head;
	b = li->head->next;
	if (li->size > 2)
		b->next->prev = li->head;
	a->next = b->next;
   	li->head = b;
	li->head->prev = NULL;
	li->head->next = a;
	a->prev = li->head;
	if (li->size == 2)
		li->last = li->head->next;
	if (flag == A)
		ft_putendl_fd("sa", 1);
	else if (flag == B)
		ft_putendl_fd("sb", 1);
}

void	swap_a_b(t_list	*a, t_list	*b)
{
	swap_stack(a, 0);
	swap_stack(b, 0);
	ft_putendl_fd("ss", 1);
}
/*------------------------------------------*/
static void	push_follow(t_list	*from, t_list	*to)
{
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

void	push_stack(t_list	*from, t_list	*to, int	flag)
{
	if (from->head == NULL)
		return ;
	if (from->head->next == NULL)
	{
		if (to->head == NULL)
			to->head = from->head;
		else
		{	
			to->head->prev = from->head;
			from->head->next = to->head;
			to->head = from->head;
		}
		from->head = NULL;
	}	
	else
		push_follow(from, to);
	if (flag == A)
		ft_putendl_fd("pa", 1);
	else if (flag == B)	
		ft_putendl_fd("pb", 1);
	to->size++;
	from->size--;
	to->last = last_node(to);
}
/*--------------------------------------------------*/
void	rotate_stack(t_list	*li, int	flag)
{
	t_node	*temp;
	t_node	*temp_nxt;
	
	if (li->size < 2)
		return ;
	
	temp = li->head;
	temp_nxt = li->head->next;
	li->last->next = temp;
	temp->prev = li->last;
	temp->next = NULL;
	li->last = temp;
	li->head = temp_nxt;
	li->head->prev = NULL;
	if (flag == A)
		ft_putendl_fd("ra", 1);
	else if (flag == B)
		ft_putendl_fd("rb", 1);
}

void	rotate_a_b(t_list	*a, t_list	*b)
{
	rotate_stack(a, 0);
	rotate_stack(b, 0);
	ft_putendl_fd("rr", 1);
}
/*---------------------------------------------------*/
void	reverse_rotate(t_list	*li, int flag)
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
	if (flag == A)
		ft_putendl_fd("rra", 1);
	else if (flag == B)
		ft_putendl_fd("rrb", 1);
}

void	reverse_rotate_a_b(t_list	*a, t_list	*b)
{
	reverse_rotate(a, 0);
	reverse_rotate(b, 0);
	ft_putendl_fd("rrr", 1);
}

