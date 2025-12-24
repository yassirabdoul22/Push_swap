/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdoul <yaabdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 19:07:02 by yaabdoul          #+#    #+#             */
/*   Updated: 2025/12/23 16:16:30 by yaabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

void	execute_move(t_stack **a, t_stack **b, t_stack *n)
{
	double_move(a, b, n);
	single_move(a, b, n);
	pa(a, b, 0);
}

void	bring_to_top(t_stack **a, int index)
{
	int	pos;
	int	size;
	int	moves;

	pos = find_position(*a, index);
	if (pos < 0)
		return ;
	size = stack_size(*a);
	if (pos <= size / 2)
		while (pos--)
			ra(a, 0);
	else
	{
		moves = size - pos;
		while (moves--)
			rra(a, 0);
	}
}

void	single_move(t_stack **a, t_stack **b, t_stack *n)
{
	while (n->cost_a > 0)
	{
		ra(a, 0);
		n->cost_a--;
	}
	while (n->cost_a < 0)
	{
		rra(a, 0);
		n->cost_a++;
	}
	while (n->cost_b > 0)
	{
		rb(b, 0);
		n->cost_b--;
	}
	while (n->cost_b < 0)
	{
		rrb(b, 0);
		n->cost_b++;
	}
}

void	final_align(t_stack **a)
{
	int	min_idx;
	int	size;
	int	moves;

	min_idx = find_position(*a, 0);
	if (min_idx < 0)
		return ;
	size = stack_size(*a);
	if (min_idx <= size / 2)
		while (min_idx--)
			ra(a, 0);
	else
	{
		moves = size - min_idx;
		while (moves--)
			rra(a, 0);
	}
}

int	get_cost(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	return (-(size - pos));
}
