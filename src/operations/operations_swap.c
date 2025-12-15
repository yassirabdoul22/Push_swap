/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdoul <yaabdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:27:49 by yaabdoul          #+#    #+#             */
/*   Updated: 2025/12/14 13:22:57 by yaabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

void	sa(t_stack **a, int iscalled)
{
	t_stack	*first;
	t_stack	*second;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*a = second;
	if (!iscalled)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, int iscalled)
{
	t_stack	*first;
	t_stack	*second;

	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*b = second;
	if (!iscalled)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, int check)
{
	sa(a, 1);
	sb(b, 1);
	if (!check)
		write(1, "ss\n", 3);
}
