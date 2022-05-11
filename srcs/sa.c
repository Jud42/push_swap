/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 11:58:40 by rmamison          #+#    #+#             */
/*   Updated: 2022/05/11 21:53:41 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_node	*a, t_node	*b, char	*s)
{
	if (!a->next)
		return ;
	int	x;

	x = a->value;
	a->value = b->value;
	b->value = x;
	ft_printf("%s\n", s);
}

void	swap_a_b(t_list	*a, t_list	*b)
{
	swap_stack(a->head, a->head->next, " ");
	swap_stack(b->head, b->head->next, " ");
	ft_printf("ss\n");
}

void	push_stack(t_list	*li_a, t_list	*li_b, char	*s)
{
	if (li_b->head == NULL)
		return ;
	insert_front_list(li_a, li_b->head->value);
	delete_front_list(li_b);
	ft_printf("%s\n", s);
}

void	rotate_stack(t_list	*li, char	*s)
{
	if (li->head == NULL || li->size == 1)
		return ;
	t_node	*temp;
	int	a;
	int	b;

	temp = li->last;
	a = temp->value;
	while (temp->prev != NULL)
	{
		b = temp->prev->value;
		temp->prev->value = a;
		a = b;
		temp = temp->prev;
	}
	li->last->value = a;
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
	if (li->head == NULL || li->size == 1)
		return ;
	t_node	*temp;
	int	a;
	int	b;

	temp = li->head;
	a = temp->value;
	while (temp->next != NULL)
	{
		b = temp->next->value;
		temp->next->value = a;
		a = b;
		temp = temp->next;
	}
	li->head->value = a;
	ft_printf("%s\n", s);
}

void	reverse_rotate_a_b(t_list	*a, t_list	*b, char	*s)
{
	reverse_rotate(a, " ");
	reverse_rotate(b, " ");
	ft_printf("%s\n", s);
}

