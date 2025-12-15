/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdoul <yaabdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 19:10:45 by yaabdoul          #+#    #+#             */
/*   Updated: 2025/12/14 13:24:42 by yaabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

static void	fill_array(t_stack *a, int *arr)
{
	int	i;

	i = 0;
	while (a)
	{
		arr[i++] = a->element;
		a = a->next;
	}
}

static void	sort_array(int *arr, int size)
{
	int	j;
	int	k;
	int	t;

	j = 0;
	while (j < size - 1)
	{
		k = j + 1;
		while (k < size)
		{
			if (arr[j] > arr[k])
			{
				t = arr[j];
				arr[j] = arr[k];
				arr[k] = t;
			}
			k++;
		}
		j++;
	}
}

static void	assign_indexes_to_stack(t_stack *a, int *arr, int size)
{
	int	i;

	while (a)
	{
		i = 0;
		while (i < size)
		{
			if (a->element == arr[i])
			{
				a->index = i;
				break ;
			}
			i++;
		}
		a = a->next;
	}
}

void	assign_index(t_stack *a)
{
	int		size;
	int		*arr;

	size = stack_size(a);
	if (size == 0)
		return ;
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return ;
	fill_array(a, arr);
	sort_array(arr, size);
	assign_indexes_to_stack(a, arr, size);
	free(arr);
}
