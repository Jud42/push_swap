/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:28:48 by rmamison          #+#    #+#             */
/*   Updated: 2022/05/24 20:09:51 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*find_place(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = -1;
	temp = 0;
	while (++i < size)
	{
		j = i;
		while (++j < size)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[j];
				tab[j] = tab[i];
				tab[i] = temp;
			}
		}
	}
	return (tab);
}

static int	*tab_i(t_list	*li)
{
	int		i;
	int		*tab;
	t_node	*temp;

	tab = (int *)malloc(sizeof(int) * li->size);
	if (!tab)
		return (NULL);
	temp = li->head;
	i = -1;
	while (++i < li->size)
	{
		tab[i] = temp->value;
		temp = temp->next;
	}
	tab = find_place(tab, li->size);
	return (tab);
}

void	replace_data(t_list	*li)
{
	int		i;
	int		*tab;
	t_node	*temp;

	tab = tab_i(li);
	temp = li->head;
	while (temp)
	{
		i = -1;
		while (++i < li->size)
		{
			if (temp->value == tab[i])
			{
				temp->pos = i + 1;
				break ;
			}
		}
		temp = temp->next;
	}
	free(tab);
}
