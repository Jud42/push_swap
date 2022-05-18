/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:52:15 by rmamison          #+#    #+#             */
/*   Updated: 2022/05/18 22:51:23 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


static void	part_b(t_list	*a, t_list	*b, s_nb_oper	*op)
{
	if (b->head->value > op->piv_b)
	{
		push_stack(b, a, A);
		op->pa++;
		if (a->head->value <= op->piv)
		{
			rotate_stack(a, A);
			op->ra++;
		}
	}
	else
	{
		rotate_stack(b, B);
		op->rb++
	}
}

static void	reversing_ra(t_list	*a, t_list	*b, s_nb_oper	*op, int	*count)
{
	int	i;
	int	j;
	
	i = op->rb;
	j = op->ra - op->rb;
	while (i--)
		reverse_rotate_a_b(a, b);
	while (j--)
		reverse_rotate(a, A);
}

static void	reversing_rb(t_list	*a, t_list	*b, s_nb_oper	*op, int	*count)
{
	int	i;
	int	j;
	
	i = op->ra;
	j = op->rb - op->ra;
	while (i--)
		reverse_rotate_a_b(a, b);
	while (j--)
		reverse_rotate(b, B);
}

void	sort_b(t_list	*a, t_list	*b, int	size, int	*count)
{
	s_nb_oper	op;
	int	i;

	(*count)++;
	if (!small_nbr(a, b, size, A))
		return ;
	init_oper(&op);
	init_pivot(b, size, &op);
	i = size;
	while (i--)
		part_b(a, b, &op);
	sort_a(a, b, (op->pa - op->ra), count);
	if (op.ra > op.rb)
		reversing_ra(a, b, &op, count);
	else
		reversing_rb(a, b, &op, count);
	sort_a(a, b, op->ra, count);
	sort_b(a, b, op->rb, count);
}
