/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdoul <yaabdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 22:50:22 by yaabdoul          #+#    #+#             */
/*   Updated: 2025/12/15 20:53:42 by yaabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

void	find_target(t_stack *a, t_stack *b)
{
	t_stack	*tmp;

	while (b)
	{
		tmp = a;
		b->target = NULL;
		while (tmp)
		{
			if (tmp->index > b->index
				&& (!b->target || tmp->index < b->target->index))
				b->target = tmp;
			tmp = tmp->next;
		}
		if (!b->target)
			b->target = find_smallest(a);
		b = b->next;
	}
}

int	get_chunk_size(int size)
{
	if (size <= 100)
		return (20);
	if (size <= 500)
		return (50);
	return (100);
}

t_stack	*find_in_chunk(t_stack *a, int min, int max)
{
	while (a && (a->index < min || a->index > max))
		a = a->next;
	return (a);
}

void	update_chunk_limits(int *min, int *max, int chunk)
{
	*min += chunk;
	*max += chunk;
}

t_stack	*find_cheapest(t_stack *b)
{
	t_stack	*cheap;
	t_stack	*tmp;
	int		best;
	int		total;

	cheap = b;
	tmp = b;
	best = 2147483647;
	while (tmp)
	{
		total = ft_abs(tmp->cost_a) + ft_abs(tmp->cost_b);
		if (total < best)
		{
			best = total;
			cheap = tmp;
		}
		tmp = tmp->next;
	}
	return (cheap);
}
