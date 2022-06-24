/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiList.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 20:38:22 by rmamison          #+#    #+#             */
/*   Updated: 2022/06/24 16:58:47 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_new_node(int x)
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
/*--------------------------*/

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
/*--------------------------------*/

void	insert_back_list(t_list *li, int nbr)
{
	t_node	*news;
	t_node	*temp;

	news = get_new_node(nbr);
	if (li->head == NULL)
	{
		li->head = news;
		li->size++;
		return ;
	}
	temp = li->head;
	while (temp->next != NULL)
		temp = temp->next;
	news->prev = temp;
	temp->next = news;
	li->last = temp->next;
	li->size++;
}
/*-------------------------------------*/

void	delete_front_list(t_list	*li)
{
	t_node	*temp;

	if (!li->head)
		return ;
	if (li->head->next == NULL)
	{
		free(li->head);
		li->head = NULL;
		li->size--;
		return ;
	}
	temp = li->head->next;
	temp->prev = NULL;
	free(li->head);
	li->head = temp;
	li->size--;
}
/*------------------------------------------*/

void	clear_list(t_list *li)
{
	if (!li->head)
		return ;
	while (li->head != NULL)
		delete_front_list(li);
}
