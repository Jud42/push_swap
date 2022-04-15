/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:35:13 by rmamison          #+#    #+#             */
/*   Updated: 2022/04/15 18:24:52 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../so_long/libft/libft.h"

int	*tab_split(char *s, int *size)
{
	char	**tab_s;
	int		*tab_i;
	int		i;

	i = -1;
	tab_s = ft_split(s, ' ');
	while (tab_s[++i])
		;
	tab_i = (int *)malloc(sizeof(int) * i);
	*size = i;
	i = -1;
	while (tab_s[++i])
		tab_i[i] = ft_atoi(tab_s[i]);
	return (tab_i);
}

int	*tab(char **av, int ac)
{
	int *ret;
	int	i;
	int j;

	ret = (int *)malloc(sizeof(int) * (ac - 1));
	i = 1;
	j = 0;
	while (av[i] != NULL)
		ret[j++] = ft_atoi(av[i++]);
	return (ret);
}

int	main(int argc, char **argv)
{
	int *stackA;
	int	size;
	int	i;
	
	i = -1;
	size = 0;
	if (ft_strchr(argv[1], ' '))
		stackA = tab_split(argv[1], &size);
	else
		stackA = tab(argv, argc);
	printf("	stackA	|	stackB\n");
	if (size > 0)
		while (++i < size)
			printf("	%d\n", stackA[i]);
	else
		while (++i < argc - 1)
			printf("	%d\n", stackA[i]);
	free(stackA);
	return (0);
}
