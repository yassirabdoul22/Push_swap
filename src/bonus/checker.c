/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdoul <yaabdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:38:35 by yaabdoul          #+#    #+#             */
/*   Updated: 2025/12/28 17:30:22 by yaabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (!nmemb || !size)
		return (NULL);
	if (size == 0 || size > SIZE_MAX / nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;
	int	res;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
		{
			res = (unsigned char)s1[i] - (unsigned char)s2[i];
			return (res);
		}
		i++;
	}
	res = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (res);
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

void	ft_free_stacks(t_stack *a, t_stack *b)
{
	while (a)
		remove_first(&a);
	while (b)
		remove_first(&b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		is_parsed;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	is_parsed = parse_args(&a, argc, argv);
	if (is_parsed < 0)
		return (-1);
	if (!execute_operations(&a, &b))
	{
		write(2, "Error\n", 6);
		ft_free_stacks(a, b);
		return (0);
	}
	if (ft_is_sorted(a) && b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free_stacks(a, b);
	return (0);
}
