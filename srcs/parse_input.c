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
int	check_numeric(char	*s)
{
	int	i;

	i = -1;
	while(s[++i])
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
	int	i;
	int	no_num;
	char	**tab_s;

	i = -1;
	no_num = 0;
	tab_s = ft_split(s, ' ');
	//check_dup_sort(tab_s, i);
	ft_printf("b\n");
	while (tab_s[++i])
	{
		if(!check_numeric(tab_s[i]))
		{
			no_num = 1;
			break ;
		}
		insert_back_list(stack, ft_atoi(tab_s[i]));
		free(tab_s[i]);
	}
	free(tab_s[i]);
	if (no_num == 1)
		error_msg();
}

/*---------------------------------------------*/

void	parse_in(int	argc, char	**argv, t_list	*stack)
{	
	int	i;

	if (!argv[1])
		error_msg();
	i = 0;
	while (++i < argc)
		tab_split(argv[i], stack);
	
	ft_printf("a");
	if (stack->size == 0)
		exit (1);
}
