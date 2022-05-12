/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:36:34 by rmamison          #+#    #+#             */
/*   Updated: 2022/05/12 17:02:01 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_msg(char	*s)
{
	ft_printf("Error\n%s\n", s);
	exit (1);
}
/*-----------------------------*/

void	check_dup_sort(char	**av, int i)
{
	int	j;
	int	sort;

	sort = 0;
	while (av[++i])
	{
		if (ft_atoi(av[i]) > INT_MAX || ft_atoi(av[i]) < INT_MIN)
			error_msg("Integer above Max or below Min for type INT");
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]) || ft_atoi(av[i]) > INT_MAX)
				error_msg("There are a integer duplicate\n");
			if (ft_atoi(av[i]) > ft_atoi(av[j]))
				sort++;
			j++;
		}
	}
	if (sort == false)
		exit (1);
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
			error_msg("There are a caracter in your arg\n");
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
			error_msg("There are a caracter in your arg\n");
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
	list_size(stack);
	if (stack->size == 0)
		exit (EXIT_FAILURE);
}
