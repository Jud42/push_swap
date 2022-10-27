/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:36:34 by rmamison          #+#    #+#             */
/*   Updated: 2022/06/24 16:58:45 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	error_msg(void)
{
	ft_putendl_fd("Error", 1);
	exit (1);
}
/*--------------------------------*/

int	check_numeric(char	*s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == '-' || s[i] == '+')
			i++;
		if (!ft_isdigit(s[i]))
			return (0);
	}
	return (1);
}
/*---------------------------------*/

void	tab_split(char *s, t_list	*stack)
{
	int		i;
	char	**tab_s;

	i = -1;
	tab_s = ft_split(s, ' ');
	while (tab_s[++i])
	{
		if (!check_numeric(tab_s[i]))
			error_msg();
		insert_back_list(stack, atoi_pswap(tab_s[i]));
		free(tab_s[i]);
	}
	free(tab_s);
}
/*---------------------------------------------*/

void	parse_in(int argc, char **argv, t_list *stack)
{	
	int	i;
	int	sort;

	if (!argv[1])
		error_msg();
	i = 0;
	while (++i < argc)
		tab_split(argv[i], stack);
	sort = check_need_sort(stack);
	if (stack->size == 0 || sort == 0 || sort == DUP)
	{	
		clear_list(stack);
		if (sort == DUP)
			error_msg();
		exit(0);
	}
}
/*--------------------------------------------*/

int	check_need_sort(t_list *li)
{
	t_node	*temp;
	t_node	*i;
	int		sort;

	sort = 0;
	temp = li->head;
	while (temp && temp->next)
	{
		i = temp->next;
		while (i)
		{
			if (temp->value == i->value)
				return (DUP);
			else if (temp->value > i->value)
				sort = true;
			i = i->next;
		}
		temp = temp->next;
	}
	return (sort);
}
