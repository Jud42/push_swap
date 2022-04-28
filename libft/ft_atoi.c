/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:13:27 by rmamison          #+#    #+#             */
/*   Updated: 2022/04/28 18:18:27 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned int	conv;
	int				negative;

	conv = 0;
	negative = 1;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			negative = -1;
		str++;
	}
	while (*str && (ft_isdigit(*str)))
		conv = conv * 10 + (*str++ - '0');
	return (conv * negative);
}
