/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:35:13 by rmamison          #+#    #+#             */
/*   Updated: 2022/04/28 18:18:31 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	free_stack(t_stack *stack)
{
	
}*/

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
		if (ft_isalpha(*temp) || no_dig_check(*temp))
		{
			ft_printf("Error\nThere are a caracter in your arg");
			return (1);
		}
		temp++;
	}
	return (0);
}
/*---------------------------------*/

void	tab_split(char *s, t_node **stack)
{
	char	**tab_s;
	int		i;

	i = -1;
	tab_s = ft_split(s, ' ');
	while (tab_s[++i])
	{
		if(check_alpha(tab_s[i]))
		{
			free(tab_s);
			exit(1);
		}
		insert_back_list(stack, ft_atoi(tab_s[i]));
	}
}
/*-----------------------------------*/

void	tab(char **av, t_node **stack)
{
	int	i;
	
	i = 0;
	while (av[++i])
	{	
		if(check_alpha(av[i]))
			exit(1);
		insert_back_list(stack, ft_atoi(av[i]));
	}
}
/*------------------------------------*/

int	main(int argc, char **argv)
{
	t_node	*stackA = NULL;

	if (argc == 1)
		exit(EXIT_FAILURE);
	if (ft_strchr(argv[1], ' '))
		tab_split(argv[1], &stackA);
	else
		tab(argv, &stackA);
	list_size(stackA);
	if (stackA->size == 0)
		exit (EXIT_FAILURE);
	ft_printf("sizelist => %d\n", stackA->size);
	ft_printf("	stackA\n	-------\n");
	print_list(stackA);
	//clear_list(&stackA);
	//print_list(head);
	//stackA = swap_a(stackA);
	//print_list(stackA);
	return (0);
}
