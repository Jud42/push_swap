/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:25:39 by rmamison          #+#    #+#             */
/*   Updated: 2022/05/12 14:39:15 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_list *stack)
{
	stack->head = NULL;
   	stack->last = NULL;
	stack->size = 0;
	stack->max  = 0;
	stack->min  = 0;
	stack->mid  = 0;
}
