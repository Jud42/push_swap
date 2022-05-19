/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:54:33 by rmamison          #+#    #+#             */
/*   Updated: 2022/05/19 14:57:08 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	two_mng(t_list	*a, t_list	*b, int flag)
{
	if (flag == A)
	{	
		if (a->head->value > a->head->next->value)
			swap_stack(a, A);
	}
	else
	{
		if (b->head->value < b->head->next->value)
			swap_stack(b, B);
		push_stack(b, a, A);
		push_stack(b, a, A);
	}
}
