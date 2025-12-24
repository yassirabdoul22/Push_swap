/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdoul <yaabdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:38:35 by yaabdoul          #+#    #+#             */
/*   Updated: 2025/12/20 21:04:43 by yaabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

void	ft_fr(char *ptr)
{
	if (ptr)
		free(ptr);
}

void	ft_strncpy(char *dst, const char *src, int n)
{
	int	i;

	i = 0;
	while (i < n && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dst[i] = '\0';
		i++;
	}
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	apply_operation(t_stack **a, t_stack **b, const char *op)
{
	if (ft_strcmp(op, "sa") == 0)
		sa(a, 1);
	else if (ft_strcmp(op, "sb") == 0)
		sb(b, 1);
	else if (ft_strcmp(op, "ss") == 0)
		ss(a, b, 1);
	else if (ft_strcmp(op, "pa") == 0)
		pa(a, b, 1);
	else if (ft_strcmp(op, "pb") == 0)
		pb(a, b, 1);
	else if (ft_strcmp(op, "ra") == 0)
		ra(a, 1);
	else if (ft_strcmp(op, "rb") == 0)
		rb(b, 1);
	else if (ft_strcmp(op, "rr") == 0)
		rr(a, b, 1);
	else if (ft_strcmp(op, "rra") == 0)
		rra(a, 1);
	else if (ft_strcmp(op, "rrb") == 0)
		rrb(b, 1);
	else if (ft_strcmp(op, "rrr") == 0)
		rrr(a, b, 1);
	else
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (!parse_args(&a, argc, argv))
		return (-1);
	execute_operations(&a, &b);
	if (ft_is_sorted(a) && b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	while (a)
		remove_first(&a);
	while (b)
		remove_first(&b);
	return (0);
}
