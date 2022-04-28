/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utit_node.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:57:58 by rmamison          #+#    #+#             */
/*   Updated: 2022/04/28 14:38:12 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_size(t_node *li)
{
	t_node	*actual = li;	
	li->size = 0;
	if (li)
		while (actual != NULL)
		{
			li->size++;
			actual = actual->next;
		}
	free(actual);
	actual = NULL;
}

void	print_list(t_node *li)
{
	if (li == NULL)
	{
		ft_printf("Empty list\n");
		return ;
	}
	t_node	*temp;

	temp = li;
	while (temp != NULL)
	{
		ft_printf("	%d\n", temp->value);
		temp = temp->next;
	}
	ft_printf("\n");
}

void	insert_back_list(t_node	**li, int	nbr)
{
	t_node	*news = malloc(sizeof(*news));
	if (news == NULL)
	{
		ft_printf("Allocation element failed\n");
		exit(1);
	}
	news->value = nbr;
	news->next = NULL;
	if (*li == NULL)
	{
		*li = news;
		return ;
	}
	t_node	*temp;

	temp = *li;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = news;
}

void	insert_front_node(t_node	**li, int	nbr)
{
	t_node	*element;

	element = malloc(sizeof(*element));
	if (!element)
	{
		ft_printf("Allocation element failed\n");
		exit(1);
	}
	element->value = nbr;
	element->next = NULL;
	if (*li != NULL)
		element->next = *li;
	*li = element;
}

void	delete_back_list(t_node	**li)
{
	if (!*li)
		return ;
	t_node	*temp;
 
	temp = *li;
	if (temp->next == NULL)
	{
		free(*li);
		*li = NULL;
		return ;
	}
	t_node	*before;

	before = *li;
	while(temp->next != NULL)
	{
		before = temp;
		temp = temp->next;
	}
	before->next = NULL;
	free(temp);
	temp = NULL;
}

void	delete_front_list(t_node	**li)
{
	if (!*li)
		return ;
	t_node	*element;

	element = malloc(sizeof(*element));
	if (!element)
	{
		ft_printf("Allocation element failed\n");
		exit(EXIT_FAILURE);
	}
	t_node	*temp;

	temp = *li;
	element = temp->next;
	*li = element;
	free(temp);
	temp = NULL;
}

void	clear_list(t_node **li)
{
	if (!*li)
		return ;
	while (*li != NULL)
		delete_back_list(li);
}
