/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 11:58:40 by rmamison          #+#    #+#             */
/*   Updated: 2022/05/24 20:10:54 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_list *li, int flag)
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
/*---------------------------------*/

void	rotate_a_b(t_list *a, t_list *b)
{
	rotate_stack(a, 0);
	rotate_stack(b, 0);
	ft_putendl_fd("rr", 1);
}
/*---------------------------------------------------*/

void	reverse_rotate(t_list *li, int flag)
{
	t_node	*temp;
	t_node	*last_prv;

	if (li->head == NULL || li->head->next == NULL)
		return ;
	temp = li->last;
	last_prv = li->last->prev;
	li->head->prev = temp;
	temp->next = li->head;
	temp->prev = NULL;
	last_prv->next = NULL;
	li->head = temp;
	li->last = last_prv;
	if (flag == A)
		ft_putendl_fd("rra", 1);
	else if (flag == B)
		ft_putendl_fd("rrb", 1);
}
/*--------------------------------*/

void	reverse_rotate_a_b(t_list	*a, t_list	*b)
{
	reverse_rotate(a, 4);
	reverse_rotate(b, 4);
	ft_putendl_fd("rrr", 1);
}
