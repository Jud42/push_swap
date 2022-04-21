/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:35:13 by rmamison          #+#    #+#             */
/*   Updated: 2022/04/21 19:26:18 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	free_stack(t_stack *stack)
{
	
}*/

void	tab_split(char *s, t_stack *stack)
{
	char	**tab_s;
	int		i;

	i = -1;
	tab_s = ft_split(s, ' ');
	while (tab_s[++i])
		;
	stack->stack_A = (int *)malloc(sizeof(int) * i);
	stack->size = i;
	i = -1;
	while (tab_s[++i])
		stack->stack_A[i] = ft_atoi(tab_s[i]);
}

void	tab(char **av, int ac, t_stack *stack)
{
	int	i;
	int j;
	
	stack->size = ac - 1;
	stack->stack_A = (int *)malloc(sizeof(int) * (stack->size));
	i = 1;
	j = 0;
	while (av[i] != NULL)
		stack->stack_A[j++] = ft_atoi(av[i++]);
}

int	main(int argc, char **argv)
{
	t_stack stack;
	int	i;
	
	i = -1;
	stack.stack_B = 0;
	if (argc == 1)
		exit(EXIT_FAILURE);
	stack.size = 0;
	if (ft_strchr(argv[1], ' '))
		tab_split(argv[1], &stack);
	else
		tab(argv, argc, &stack);
	ft_printf("size => %d\n", stack.size);
	ft_printf("\n	stackA	|	stackB\n");
	if (stack.size == 0)
		exit (EXIT_FAILURE);
	while (++i < stack.size)
		ft_printf("	%d\n", stack.stack_A[i]);
	swap_a(&stack);
	i = -1;
	swap_b(&stack);
	ft_printf("\n	stackA	|	stackB\n");
	if (stack.size > 0)
		while (++i < stack.size)
			ft_printf("	%d			%d\n", stack.stack_A[i], stack.stack_B[i]);
	return (0);
}
