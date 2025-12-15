/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdoul <yaabdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 23:03:12 by yaabdoul          #+#    #+#             */
/*   Updated: 2025/12/14 13:17:48 by yaabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/stack.h"

void	push_swap(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size <= 1)
		return ;
	else if (size == 2)
	{
		if (!ft_is_sorted(*a))
			sa(a, 0);
	}
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, b);
	else
		turk_sort(a, b);
}

int	main(int ac, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	if (!parse_args(&a, ac, argv))
		return (1);
	if (check_stack(&a))
	{
		while (a)
			remove_first(&a);
		return (0);
	}
	assign_index(a);
	push_swap(&a, &b);
	while (a)
		remove_first(&a);
	while (b)
		remove_first(&b);
	return (0);
}
