/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdoul <yaabdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:27:47 by yaabdoul          #+#    #+#             */
/*   Updated: 2025/12/09 17:50:29 by yaabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/stack.h"
#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>

void ra(stack **a, int iscalled)
{
    if(!a || !*a || !(*a)->next)
        return;

    stack *first = *a;
    stack *last = *a;

    while(last->next)
        last = last->next;

    *a = first->next;
    first->next = NULL;
    last->next = first;

    if(!iscalled)
        write(1, "ra\n", 3);
}

void rb(stack **b, int iscalled)
{
    if(!b || !*b || !(*b)->next)
        return;

    stack *first = *b;
    stack *last = *b;

    while(last->next)
        last = last->next;

    *b = first->next;
    first->next = NULL;
    last->next = first;

    if(!iscalled)
        write(1, "rb\n", 3);
}

void rr(stack **a, stack **b)
{
    ra(a, 1);
    rb(b, 1);
    write(1, "rr\n", 3);
}
