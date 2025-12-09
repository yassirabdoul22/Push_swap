/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdoul <yaabdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:28:06 by yaabdoul          #+#    #+#             */
/*   Updated: 2025/12/09 16:11:44 by yaabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

int check_stack(stack **head)
{
    return (*head == NULL);
}

void Remove_first(stack **head)
{
    stack *temp;

    if (!head || !*head)
        return;
    temp = *head;
    *head = (*head)->next;
    free(temp);
}

int pop(stack **st)
{
    int value;

    if (check_stack(st))
        return -1;
    value = (*st)->element;
    Remove_first(st);
    return value;
}

void push(stack **head, int element)
{
    if (insert_at_top(head, element))
        printf("Stack Overflow!\n");
}

int peek(stack **st)
{
    if (check_stack(st))
        return -1;
    return (*st)->element;
}
