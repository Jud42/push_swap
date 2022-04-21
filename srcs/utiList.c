/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiList.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:57:58 by rmamison          #+#    #+#             */
/*   Updated: 2022/04/21 22:09:18 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	empty_list(List li)
{
	if (!li)
	{
		ft_printf("Empty list\n");
		return (true);
	}
	return (false);
}

int	list_size(List li)
{
	int	i;
	
	i = 0;
	if (!empty_list(li))
		while (li != NULL)
		{
			i++;
			li = li->next;
		}
	return (i);
}

void	print_list(List li)
{
	if (empty_list(li))
		return ;
	while (li != NULL)
	{
		ft_printf("	%d\n", li->value);
		li = li->next;
	}
	ft_printf("\n");
}

List	insert_back_list(List	li, int	nbr)
{

	ListElement	*element;

	element = malloc(sizeof(*element));
	if (!element)
	{
		ft_printf("Allocation element failed\n");
		exit(EXIT_FAILURE);
	}
	element->value = nbr;
	element->next = NULL;
	if (empty_list(li))
		return (element);

	ListElement	*temp;

	temp = li;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = element;
	return (li);
}

List	insert_front_list(List	li, int	nbr)
{
	ListElement	*element;

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

List	delete_back_list(List	li)
{
	if (empty_list(li))
		return NULL;
	else if (li->next == NULL)
	{
		free(li);
		li = NULL;
		return NULL;
	}
	ListElement	*temp;
	ListElement	*before;

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

List	delete_front_list(List	li)
{
	if (empty_list(li))
		return NULL;
	ListElement	*element;

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

List	clear_list(List li)
{
	if (empty_list(li))
		return NULL;
	while (li != NULL)
		li = delete_front_list(li);
	return (li);
}
