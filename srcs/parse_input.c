/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:36:34 by rmamison          #+#    #+#             */
/*   Updated: 2022/05/20 15:36:12 by rmamison         ###   ########.fr       */
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
	char	**tab_s;

	i = -1;
	tab_s = ft_split(s, ' ');
	while (tab_s[++i])
	{
		if(!check_numeric(tab_s[i]))
			error_msg();
		insert_back_list(stack, atoi_pswap(tab_s[i]));
		free(tab_s[i]);
	}
	free(tab_s);
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

	if (!check_need_sort(stack))
	{	
		clear_list(stack);
		error_msg();
	}
	if (stack->size == 0)
		exit (1);
}
