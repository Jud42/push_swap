/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:36:34 by rmamison          #+#    #+#             */
/*   Updated: 2022/05/19 22:15:36 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_msg(void)
{
	ft_putendl_fd("Error", 1);
	exit (1);
}
/*-----------------------------*/

void	check_dup_sort(char	**av, int i)
{
	int	j;
	int	need_sort;

	need_sort = 0;
	while (av[++i])
	{
		if (ft_atoi(av[i]) > INT_MAX || ft_atoi(av[i]) < INT_MIN)
			error_msg();
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]) || ft_atoi(av[i]) > INT_MAX)
				error_msg();
			if (ft_atoi(av[i]) > ft_atoi(av[j]))
				need_sort++;
			j++;
		}
	}
	if (need_sort == false)
		exit (0);
	return ;
}
/*--------------------------------*/
int	no_dig_check(int	c)
{
	if (c >= 48 && c <= 57)
		return (0);
	return (1);
}

int	check_alpha(char	*s)
{
	char	*temp = s;
	while((int)*temp)
	{
		if (*temp == '-')
			temp++;
		if (ft_isalpha(*temp) || no_dig_check(*temp))
			return (1);
		temp++;
	}
	return (0);
}
/*---------------------------------*/

void	tab_split(char *s, t_list	*stack)
{
	char	**tab_s;
	int		i;

	i = -1;
	tab_s = ft_split(s, ' ');
	check_dup_sort(tab_s, i);
	while (tab_s[++i])
	{
		if(check_alpha(tab_s[i]))
		{
			free(tab_s);
			error_msg();
		}
		insert_back_list(stack, ft_atoi(tab_s[i]));
	}
}
/*-----------------------------------*/

void	tab(char **av, t_list	*stack)
{
	int	i;
	
	i = 0;
	check_dup_sort(av, i);
	while (av[++i])
	{	
		if(check_alpha(av[i]))
			error_msg();
		insert_back_list(stack, ft_atoi(av[i]));
	}
}
/*---------------------------------------------*/

void	parse_in(char	**argv, t_list	*stack)
{	
	if (ft_strchr(argv[1], ' '))
		tab_split(argv[1], stack);
	else
		tab(argv, stack);
	if (stack->size == 0)
		exit (EXIT_FAILURE);
}
