/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utit_node.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:57:58 by rmamison          #+#    #+#             */
/*   Updated: 2022/04/27 22:27:22 by rmamison         ###   ########.fr       */
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
	if (!li)
		return ;
	t_node	*temp;

	temp = li;
	while (temp != NULL)
	{
		ft_printf("	%d\n", temp->value);
		temp = temp->next;
	}
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

/*t_node	insert_front_node(t_node	li, int	nbr)
{
	t_node	*element;

	element = malloc(sizeof(*element));
	if (!element)
	{
		ft_printf("Allocation element failed\n");
		exit(EXIT_FAILURE);
	}
	element->value = nbr;
	element->next = NULL;
	if (!empty_list(li))
		element->next = li;
	return (element);
}

t_node	delete_back_list(t_node	li)
{
	if (empty_list(li))
		return NULL;
	else if (li->next == NULL)
	{
		free(li);
		li = NULL;
		return NULL;
	}
	t_node	*temp;
	t_node	*before;

	temp = li;
	before = li;
	while(temp->next != NULL)
	{
		before = temp;
		temp = temp->next;
	}
	before->next = NULL;
	free(temp);
	temp = NULL;
	return (li);
}

t_node	delete_front_node(t_node	li)
{
	if (empty_list(li))
		return NULL;
	t_node	*element;

	element = malloc(sizeof(*element));
	if (!element)
	{
		ft_printf("Allocation element failed\n");
		exit(EXIT_FAILURE);
	}
	element = li->next;
	free(li);
	li = NULL;
	return (element);
}

t_node	clear_list(t_node li)
{
	if (empty_list(li))
		return NULL;
	while (li != NULL)
		li = delete_front_node(li);
	return (li);
}*/
