/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdoul <yaabdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:27:52 by yaabdoul          #+#    #+#             */
/*   Updated: 2025/12/08 18:27:53 by yaabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include <unistd.h>

int	stack_size(stack *a)
{
	int i = 0;

	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}


/* Push_swap radix sort pour grands ensembles */
void	sort_big(stack **a, stack **b)
{
	int i;
	int j;
	int size;
	int max_num;
	stack *tmp;

	size = stack_size(*a);
	max_num = 0;
	tmp = *a;
	while (tmp)
	{
		if (tmp->element > max_num)
			max_num = tmp->element;
		tmp = tmp->next;
	}
	i = 0;
	while ((max_num >> i) != 0)
	{
		j = 0;
		while (j++ < size)
		{
			if (((*a)->element >> i & 1) == 0)
				pb(a, b);
			else
				ra(a, 0);
		}
		while (*b)
			pa(a, b);
		i++;
	}
}
