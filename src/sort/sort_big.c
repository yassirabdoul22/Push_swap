/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdoul <yaabdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 18:00:00 by yaabdoul          #+#    #+#             */
/*   Updated: 2025/12/30 20:13:11 by yaabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

void	calculate_costs(t_stack *a, t_stack *b)
{
	int		size_a;
	int		size_b;
	t_stack	*tmp;

	if (!a || !b)
		return ;
	size_a = stack_size(a);
	size_b = stack_size(b);
	tmp = b;
	while (tmp)
	{
		if (tmp->target)
		{
			tmp->cost_b = get_cost(
					find_position(b, tmp->index), size_b);
			tmp->cost_a = get_cost(
					find_position(a, tmp->target->index), size_a);
		}
		tmp = tmp->next;
	}
}

void	double_move(t_stack **a, t_stack **b, t_stack *n)
{
	while (n->cost_a > 0 && n->cost_b > 0)
	{
		rr(a, b, 0);
		n->cost_a--;
		n->cost_b--;
	}
	while (n->cost_a < 0 && n->cost_b < 0)
	{
		rrr(a, b, 0);
		n->cost_a++;
		n->cost_b++;
	}
}

static void	push_chunks(t_stack **a, t_stack **b)
{
	int		min;
	int		max;
	int		chunk;
	t_stack	*tmp;
	int		size;

	size = stack_size(*a);
	chunk = get_chunk_size(size);
	min = 0;
	max = chunk - 1;
	while (stack_size(*a) > 3)
	{
		tmp = find_in_chunk(*a, min, max);
		if (!tmp)
			update_chunk_limits(&min, &max, chunk);
		else
		{
			bring_to_top(a, tmp->index);
			pb(a, b, 0);
		}
	}
}

void	turk_sort(t_stack **a, t_stack **b)
{
	t_stack	*cheap;

	push_chunks(a, b);
	sort_three(a);
	while (*b)
	{
		find_target(*a, *b);
		calculate_costs(*a, *b);
		cheap = find_cheapest(*b);
		execute_move(a, b, cheap);
	}
	final_align(a);
}
