/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdoul <yaabdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 23:37:10 by yaabdoul          #+#    #+#             */
/*   Updated: 2025/12/28 17:23:24 by yaabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

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
	r = 0;
	while (i < 3)
	{
		r = read(fd, &c, 1);
		if (r <= 0 || c == '\n')
			break ;
		op[i] = c;
		i++;
	}
	if (i == 0 && r <= 0)
	{
		return (ft_fr(op), (NULL));
	}
	op[i] = '\0';
	return (op);
}

int	execute_operations(t_stack **a, t_stack **b)
{
	char	*op;

	op = NULL;
	op = read_operation(0);
	while (op != NULL)
	{
		if (!apply_operation(a, b, op))
		{
			write(2, "Error\n", 6);
			ft_fr(op);
			return (-1);
		}
		ft_fr(op);
		op = read_operation(0);
	}
	return (1);
}
