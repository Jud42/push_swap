/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:35:13 by rmamison          #+#    #+#             */
/*   Updated: 2022/05/10 22:00:20 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define INT_MAX 2147483647
#define INT_MIN -2147483648

/*void	free_stack(t_stack *stack)
{
	
}*/
void	error_msg(char	*s)
{
	ft_printf("Error\n%s\n", s);
	exit (1);
}

void	check_sort(int	a, int	b)
{
	
	if (a > b)
	{	
		ft_printf("%d, %d\n pas ordre croissant\n", a, b);
	}
}
void	check_duplicate(char	**av, int i)
{
	int	j;

	while (av[++i])
	{
		if (ft_atoi(av[i]) > INT_MAX || ft_atoi(av[i]) < INT_MIN)
			error_msg("Integer above Max or below Min for type INT");
		j = i + 1;
		while (av[j])
		{
			check_sort((int)ft_atoi(av[i]), (int)ft_atoi(av[j]));
			if (ft_atoi(av[i]) == ft_atoi(av[j]) || ft_atoi(av[i]) > INT_MAX)
				error_msg("There are a integer duplicate\n");
			j++;
		}
	}
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
	check_duplicate(tab_s, i);
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
	check_duplicate(av, i);
	while (av[++i])
	{	
		if(check_alpha(av[i]))
			error_msg("There are a caracter in your arg\n");
		insert_back_list(stack, ft_atoi(av[i]));
	}
}
/*------------------------------------*/

int	main(int argc, char **argv)
{
	t_list	stack_a;
	t_list	stack_b;
	stack_a.head = NULL;
   	stack_a.last = NULL;	
	stack_b.head = NULL;
	stack_b.last = NULL;
	
	if (argc == 1)
		exit(EXIT_FAILURE);
	if (ft_strchr(argv[1], ' '))
		tab_split(argv[1], &stack_a);
	else
		tab(argv, &stack_a);
	list_size(&stack_a);
	if (stack_a.size == 0)
		exit (EXIT_FAILURE);
	if (stack_a.size == 3)
		mini_sort(&stack_a);
/*	ft_printf("sizelist => %d\n", stack_a.size);
	ft_printf("	stack_a\n	-------\n");
	print_list(&stack_a);*/
//	_quickSort(stack_a.head, stack_a.last, &stack_a);
	print_list(&stack_a);
	return (0);
}
