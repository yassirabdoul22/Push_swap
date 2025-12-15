/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdoul <yaabdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:43:41 by yaabdoul          #+#    #+#             */
/*   Updated: 2025/12/14 13:19:12 by yaabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	already_exist(t_stack *stk, int value)
{
	while (stk)
	{
		if (stk->element == value)
			return (1);
		stk = stk->next;
	}
	return (0);
}

long	ft_atol(char *str)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	if (!str)
		return (0);
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

int	insert_value(t_stack **a, char *str)
{
	long	val;
	int		ival;

	if (!is_number(str))
		return (0);
	val = ft_atol(str);
	if (val > INT_MAX || val < INT_MIN)
		return (0);
	ival = (int)val;
	if (already_exist(*a, ival))
		return (0);
	insert_at_bottom(a, ival);
	return (1);
}
