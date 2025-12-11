/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdoul <yaabdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:27:49 by yaabdoul          #+#    #+#             */
/*   Updated: 2025/12/10 23:07:01 by yaabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include <stdio.h>


void sa(stack **a, int iscalled)
{
    stack *first;
    stack *second;

    if(!a || !*a || !(*a)->next)
        return;

    first = *a;
    second = first->next;

    first->next = second->next;
    second->next = first;
    *a = second;

    if(!iscalled)
        write(1, "sa\n", 3);
}

void sb(stack **b, int iscalled)
{
    stack *first;
    stack *second;

    if(!b || !*b || !(*b)->next)
        return;

    first = *b;
    second = first->next;

    first->next = second->next;
    second->next = first;
    *b = second;

    if(!iscalled)
        write(1, "sb\n", 3);
}

void ss(stack **a, stack **b,int check)
{
    sa(a, 1);
    sb(b, 1);
    if(!check)
        write(1, "ss\n", 3);
}