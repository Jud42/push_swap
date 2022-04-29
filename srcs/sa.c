/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 11:58:40 by rmamison          #+#    #+#             */
/*   Updated: 2022/04/29 13:52:47 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_list *li, char	*s)
{
	int	a;

	if (!li->head || li->head->size == 1)
		return ;

	a = li->head->value;
	li->head->value = li->head->next->value;
	li->head->next->value = a;
	ft_printf("%s\n", s);
}

void	swap_a_b(t_list *a, t_list *b)
{
	swap_stack(a, " ");
	swap_stack(b, " ");
	ft_printf("ss\n");
}

void	push_stack(t_list	*li_a, t_list	*li_b, char	*s)
{
	if (li_b == NULL)
		return ;
	insert_front_list(li_a, li_b->head->value);
	delete_front_list(li_b);
	ft_printf("%s\n", s);
}

void	rotate_stack(t_list	*li, char	*s)
{
	if (li->head == NULL || li->head->size == 1)
		return ;
	t_node	*temp;

}
