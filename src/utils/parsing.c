/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdoul <yaabdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 17:10:19 by yaabdoul          #+#    #+#             */
/*   Updated: 2025/12/28 17:34:50 by yaabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

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

int	insert_digits(t_stack **a, char **digits)
{
	int	j;

	j = 0;
	while (digits[j])
	{
		if (digits[j][0] == '\0' || !is_number(digits[j])
			|| !insert_value(a, digits[j]))
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

int	contain_only_white(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	return (i == ft_strlen(str));
}

int	parse_args(t_stack **a, int ac, char **argv)
{
	int		i;
	char	**digits;

	i = 1;
	while (i < ac)
	{
		if (!argv[i] || contain_only_white(argv[i]))
		{
			write(2, "Error\n", 6);
			clear_stack(a);
			return (-1);
		}
		digits = ft_split(argv[i], ' ');
		if (!digits)
			return (0);
		if (!insert_digits(a, digits))
			return (-1);
		i++;
	}
	return (1);
}
