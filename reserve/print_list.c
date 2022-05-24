/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utit_node.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:57:58 by rmamison          #+#    #+#             */
/*   Updated: 2022/05/11 21:50:13 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list	*a, t_list	*b)
{
	if (a->head == NULL)
	{
		ft_printf("Empty list\n");
		return ;
	}
	t_node	*temp1;
	t_node	*temp2;
	int i = 1;

	temp1 = a->head;
	temp2 = b->head;

	ft_printf(" stack_A		stack_B\n ------			------\n");
	while (temp1)
	{
		if (!temp2)
		{
			ft_printf(" %d\n", temp1->value);
			temp1 = temp1->next;
		}
		else if (temp2 && temp1->next)
		{
			ft_printf(" %d", temp1->value);
			ft_printf("			%d\n", temp2->value);
			temp2 = temp2->next;
			temp1 = temp1->next;
		}
		else 
		{
			while (temp2)
			{
				if (temp1->value && i == 1)
				{
					ft_printf(" %d", temp1->value);
					i++;
				}	
				ft_printf("			%d\n", temp2->value);
				temp2 = temp2->next;
			}
			ft_printf("\n");
			return ;
		}
	}
	ft_printf("\n");
	return ;
}
