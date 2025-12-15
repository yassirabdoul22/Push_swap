/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdoul <yaabdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 16:25:56 by yaabdoul          #+#    #+#             */
/*   Updated: 2025/12/14 13:23:49 by yaabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

void	ra(t_stack **a, int iscalled)
{
	t_stack	*first;
	t_stack	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	last = *a;
	while (last->next)
		last = last->next;
	*a = first->next;
	first->next = NULL;
	last->next = first;
	if (!iscalled)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, int iscalled)
{
	t_stack	*first;
	t_stack	*last;

	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	last = *b;
	while (last->next)
		last = last->next;
	*b = first->next;
	first->next = NULL;
	last->next = first;
	if (!iscalled)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, int check)
{
	ra(a, 1);
	rb(b, 1);
	if (!check)
		write(1, "rr\n", 3);
}
