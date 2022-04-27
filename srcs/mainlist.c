/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:35:13 by rmamison          #+#    #+#             */
/*   Updated: 2022/04/27 22:27:25 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <xlocale.h>
/*void	free_stack(t_stack *stack)
{
	
}*/
/*int	is_not_digit(char **s)
{
	int	i;
	int	j;

	i = 0;
	//ft_printf("%d\n",ft_isdigit(ft_atoi(&s[1][0])));
	while (s[++i])
	{
		j = -1;
		while (s[i][++j])
		{
			if(ft_isdigit(ft_atoi(&s[i][j])) == 0)
			{
				ft_printf("Error\nThere is no digit\n");
				return (1);
			}
		}
	}
	return (0);
}
*/
void	tab_split(char *s, t_node **stack)
{
	char	**tab_s;
	int		i;

	i = -1;
	tab_s = ft_split(s, ' ');
	while (tab_s[++i])
		insert_back_list(stack, ft_atoi(tab_s[i]));
}

void	tab(char **av, t_node **stack)
{
	int	i;
	
	i = 1;
	while (av[i] != NULL)
		insert_back_list(stack, ft_atoi(av[i++]));
}

int	main(int argc, char **argv)
{
	t_node	*stackA = NULL;

	//stackA = malloc(sizeof(t_node));
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
	//ft_printf("	stackA\n");
	print_list(stackA);
	//stackA = swap_a(stackA);
	//print_node(stackA);
	return (0);
}
