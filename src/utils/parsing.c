/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdoul <yaabdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 17:10:19 by yaabdoul          #+#    #+#             */
/*   Updated: 2025/12/22 18:53:46 by yaabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

void	ft_free(char **elements)
{
	int	k;

	k = 0;
	while (elements[k] != NULL)
	{
		free(elements[k]);
		k++;
	}
	free(elements);
}

void	clear_stack(t_stack **s)
{
	t_stack	*tmp;

	if (!s || !*s)
		return ;
	while (*s)
	{
		tmp = (*s)->next;
		free(*s);
		*s = tmp;
	}
	*s = NULL;
}

int	insert_digits(t_stack **a, char **digits)
{
	int	j;

	j = 0;
	while (digits[j])
	{
		if (!is_number(digits[j]) || !insert_value(a, digits[j]))
		{
			write(2, "Error\n", 6);
			clear_stack(a);
			ft_free(digits);
			return (0);
		}
		j++;
	}
	ft_free(digits);
	return (1);
}

int	parse_args(t_stack **a, int ac, char **argv)
{
	int		i;
	char	**digits;

	i = 1;
	while (i < ac)
	{
		digits = ft_split(argv[i], ' ');
		if (!digits)
			return (0);
		if (!insert_digits(a, digits))
			return (0);
		i++;
	}
	return (1);
}
