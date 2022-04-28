#include "../include/push_swap.h"
#include <stdlib.h>
#include <stdio.h>
t_node	*get_new_node(int	x)
{
	t_node	*new = malloc(sizeof(*new));
	if (!new)
		exit (1);
	new->value = x;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	insert_head(int	x, t_list	*list)
{
	t_node	*new;

	new = get_new_node(x);
	if (list->head == NULL)
	{
		list->head = new;
		return ;
	}
	new->prev = list->head;
	list->head->next = new;
	//new->next = list->head;
	//list->head = new;
}

int	main()
{
	t_node	node;
	t_list	list;
	
	list.head = NULL;
	insert_head(2, &list);
	insert_head(3, &list);
	printf("%d\n", list.head->next->value);
	return (0);
}
