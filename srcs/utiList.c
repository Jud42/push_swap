/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utit_node.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:57:58 by rmamison          #+#    #+#             */
/*   Updated: 2022/05/06 19:56:05 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_new_node(int	x)
{
	t_node	*new;

	new = malloc(sizeof(*new));
	if (!new)
	{
		ft_printf("Error\n Allocation memory failure\n");
		exit(1);
	}
	new->value = x;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

/*void	last_node(t_list	*li)
{
	t_node	*temp;

	temp = li->head->next;
	ft_printf("test = %d\n, prev = %d\n", temp->value, temp->prev->value);
}*/

void	list_size(t_list *li)
{
	t_node	*actual;
   	
	actual = li->head;
	li->size = 0;
	if (li->head)
	{
		while (actual != NULL)
		{
			li->size++;
			actual = actual->next;
		}
	}
	free(actual);
	actual = NULL;
}

void	print_list(t_list *li)
{
	if (li->head == NULL)
	{
		ft_printf("Empty list\n");
		return ;
	}
	t_node	*temp;

	temp = li->head;
	while (temp != NULL)
	{
		ft_printf("	%d\n", temp->value); // I move just the pointer temp not li->head
		temp = temp->next;
	}
	ft_printf("\n");
}

void	insert_back_list(t_list	*li, int	nbr)
{
	t_node	*news; 
	
	news = get_new_node(nbr);
	if (li->head == NULL)
	{
		li->head = news;
		return ;
	}
	t_node	*temp;

	temp = li->head;
	while (temp->next != NULL)
		temp = temp->next;
	news->prev = temp;
	temp->next = news;
	li->last = temp->next;
}

void	insert_front_list(t_list	*li, int	nbr)
{
	t_node	*news;

	news = get_new_node(nbr);
	if (li->head != NULL)
	{
		news->next = li->head;
		li->head = news;
		return ;
	}
	li->head = news;
}

void	delete_back_list(t_list	*li)
{
	if (!li->head)
		return ;
	else if (li->head->next == NULL)
	{
		free(li->head);
		li->head = NULL;
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
}

void	delete_front_list(t_list	*li)
{
	if (!li->head)
		return ;
	if (li->head->next == NULL)
	{
		free(li->head);
		li->head = NULL;
		return;
	}
	t_node	*temp;

	temp = li->head->next;
	free(temp->prev);
	temp->prev = NULL;
	li->head = temp;
}

void	clear_list(t_list *li)
{
	if (!li)
		return ;
	while (li->head != NULL)
		delete_back_list(li);
}
