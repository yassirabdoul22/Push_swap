/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdoul <yaabdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 16:25:56 by yaabdoul          #+#    #+#             */
/*   Updated: 2025/12/08 18:27:45 by yaabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

void rra(stack **a,int called)
{
    if(!a || !*a || !(*a)->next)
        return;
    stack *prev = NULL;
    stack *last = *a;
    
    while(last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = *a;
    *a = last;
    if(!called)
        write(1,"rra\n",4);
}

void rrb(stack **b,int called)
{
    if(!b || !*b || !(*b)->next)
        return;

    stack *prev = NULL;
    stack *last = *b;

    while(last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = *b;
    *b = last;
    if(!called)
        write(1,"rrb\n",4);
}

void rrr(stack **a,stack **b)
{
    rra(a,1);
    rrb(b,1);
    write(1,"rrr\n",4);
}
