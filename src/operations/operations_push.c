/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdoul <yaabdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:27:41 by yaabdoul          #+#    #+#             */
/*   Updated: 2025/12/28 17:32:56 by yaabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

void	ft_fr(char *ptr)
{
	if (ptr)
		free(ptr);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	pa(t_stack **a, t_stack **b, int called)
{
	t_stack	*tmp;

	if (!b || !*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	if (!called)
		write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b, int called)
{
	t_stack	*tmp;

	if (!a || !*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	if (!called)
		write(1, "pb\n", 3);
}
