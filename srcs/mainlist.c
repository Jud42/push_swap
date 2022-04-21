/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:35:13 by rmamison          #+#    #+#             */
/*   Updated: 2022/04/21 22:09:16 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	free_stack(t_stack *stack)
{
	
}*/

List	tab_split(char *s, List stack)
{
	char	**tab_s;
	int		i;

	i = -1;
	tab_s = ft_split(s, ' ');
	while (tab_s[++i])
		stack = insert_back_list(stack, ft_atoi(tab_s[i]));
	return (stack);
}

List	tab(char **av, List stack)
{
	int	i;
	
	i = 1;
	while (av[i] != NULL)
		stack = insert_back_list(stack, ft_atoi(av[i++]));
	return (stack);
}

int	main(int argc, char **argv)
{
	List	stackA;
	int	i;
	
	i = -1;
	stackA = NULL;
	if (argc == 1)
		exit(EXIT_FAILURE);
	if (ft_strchr(argv[1], ' '))
		stackA = tab_split(argv[1], stackA);
	else
		stackA = tab(argv, stackA);
	if (list_size(stackA) == 0)
		exit (EXIT_FAILURE);
	ft_printf("sizelist => %d\n", list_size(stackA));
	ft_printf("	stackA\n");
	print_list(stackA);
	stackA = delete_back_list(stackA);
	print_list(stackA);
	stackA = delete_front_list(stackA);
	print_list(stackA);
	stackA = clear_list(stackA);
	print_list(stackA);
	return (0);
}
