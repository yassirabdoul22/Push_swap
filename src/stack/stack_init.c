/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdoul <yaabdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:28:03 by yaabdoul          #+#    #+#             */
/*   Updated: 2025/12/14 13:36:46 by yaabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

t_stack	*create_stack(int element)
{
	t_stack	*s;

	s = malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->element = element;
	s->next = NULL;
	return (s);
}

int	insert_at_top(t_stack **head, int element)
{
	t_stack	*node;

	node = create_stack(element);
	if (!node)
		return (-1);
	node->next = *head;
	*head = node;
	return (0);
}

int	insert_at_bottom(t_stack **head, int element)
{
	t_stack	*node;
	t_stack	*tmp;

	node = create_stack(element);
	if (!node)
		return (-1);
	if (!*head)
	{
		*head = node;
		return (0);
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	node->next = NULL;
	return (0);
}

int	check_stack(t_stack **head)
{
	return (*head == NULL);
}

void	remove_first(t_stack **head)
{
	t_stack	*temp;

	if (!head || !*head)
		return ;
	temp = *head;
	*head = (*head)->next;
	free(temp);
}
