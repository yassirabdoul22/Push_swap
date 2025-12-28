/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdoul <yaabdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:00:00 by yaabdoul          #+#    #+#             */
/*   Updated: 2025/12/28 16:16:30 by yaabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	if (!a || !*a || !(*a)->next || !(*a)->next->next)
		return ;
	first = (*a)->element;
	second = (*a)->next->element;
	third = (*a)->next->next->element;
	if (first > second && second < third && first < third)
		sa(a, 0);
	else if (first > second && second > third)
	{
		sa(a, 0);
		rra(a, 0);
	}
	else if (first > second && second < third && first > third)
		ra(a, 0);
	else if (first < second && second > third && first < third)
	{
		sa(a, 0);
		ra(a, 0);
	}
	else if (first < second && second > third && first > third)
		rra(a, 0);
}

int	find_index(t_stack *a, int value)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->element == value)
			return (i);
		a = a->next;
		i++;
	}
	return (-1);
}

int	find_min(t_stack *a)
{
	int	min;

	min = a->element;
	while (a)
	{
		if (a->element < min)
			min = a->element;
		a = a->next;
	}
	return (min);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	min;
	int	idx;
	int	size;

	if (!a || !*a)
		return ;
	if (ft_is_sorted(*a))
		return ;
	while (stack_size(*a) > 3)
	{
		min = find_min(*a);
		while ((*a)->element != min)
		{
			idx = find_index(*a, min);
			size = stack_size(*a);
			if (idx <= size / 2)
				ra(a, 0);
			else
				rra(a, 0);
		}
		pb(a, b, 0);
	}
	sort_three(a);
	while (*b)
		pa(a, b, 0);
}
