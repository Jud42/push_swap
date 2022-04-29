/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:35:13 by rmamison          #+#    #+#             */
/*   Updated: 2022/04/29 13:52:49 by rmamison         ###   ########.fr       */
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

void	tab_split(char *s, t_list	*stack)
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

void	tab(char **av, t_list	*stack)
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
	t_list	stack_a;
	t_list	stack_b;

	stack_a.head = NULL; 
	stack_b.head = NULL;
	if (argc == 1)
		exit(EXIT_FAILURE);
	if (ft_strchr(argv[1], ' '))
		tab_split(argv[1], &stack_a);
	else
		tab(argv, &stack_a);
	list_size(&stack_a);
	if (stack_a.head->size == 0)
		exit (EXIT_FAILURE);
	ft_printf("sizelist => %d\n", stack_a.head->size);
	ft_printf("	stack_a\n	-------\n");
	print_list(&stack_a);
	return (0);
}
