/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdoul <yaabdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:28:03 by yaabdoul          #+#    #+#             */
/*   Updated: 2025/12/08 18:28:04 by yaabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

stack *creatstack(int element)
{
    stack *s = malloc(sizeof(stack));
    if (!s)
        return NULL;
    s->element = element;
    s->next = NULL;
    return s;
}

int isert_at_top(stack **head, int element)
{
    stack *node = creatstack(element);
    if (!node)
        return -1;
    node->next = *head;
    *head = node;
    return 0;
}
