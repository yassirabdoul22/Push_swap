/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdoul <yaabdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 19:19:54 by yaabdoul          #+#    #+#             */
/*   Updated: 2025/12/23 19:04:42 by yaabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	stack_size(t_stack *s)
{
	int	size;

	size = 0;
	while (s)
	{
		size++;
		s = s->next;
	}
	return (size);
}

int	ft_is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->element > a->next->element)
			return (0);
		a = a->next;
	}
	return (1);
}

int	find_position(t_stack *s, int index)
{
	int	pos;

	pos = 0;
	while (s)
	{
		if (s->index == index)
			return (pos);
		pos++;
		s = s->next;
	}
	return (-1);
}

t_stack	*find_smallest(t_stack *a)
{
	t_stack	*min;

	min = a;
	while (a)
	{
		if (a->index < min->index)
			min = a;
		a = a->next;
	}
	return (min);
}
