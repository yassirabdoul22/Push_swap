/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdoul <yaabdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 23:37:10 by yaabdoul          #+#    #+#             */
/*   Updated: 2025/12/28 16:11:34 by yaabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

char	*read_operation(int fd)
{
	char	c;
	char	*op;
	int		i;
	int		r;

	op = ft_calloc(4, sizeof(char)); 
	if (!op)
		return (NULL);
	i = 0;
	while (i < 3)
	{
		r = read(fd, &c, 1);
		if (r <= 0)
			break ;
		if (c == '\n')
			break ;
		op[i++] = c;
	}
	if (i == 0 && r <= 0)
	{
		ft_fr(op);
		return (NULL);
	}
	op[i] = '\0';
	return (op);
}

int	execute_operations(t_stack **a, t_stack **b)
{
	char	*op;

	while ((op = read_operation(0)) != NULL)
	{
		if (!apply_operation(a, b, op))
		{
			write(2, "Error\n", 6);
			ft_fr(op);
			return -1 ;
		}
		ft_fr(op);
	}
	return (1);
}