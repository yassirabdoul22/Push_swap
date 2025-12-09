/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdoul <yaabdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:27:41 by yaabdoul          #+#    #+#             */
/*   Updated: 2025/12/09 17:51:14 by yaabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"


void pa(stack **a, stack **b)
{
    if(!b || !*b)
        return;

    int value = pop(b);
    push(a, value);

    write(1, "pa\n", 3);
}

void pb(stack **a, stack **b)
{
    if(!a || !*a)
        return;

    int value = pop(a);
    push(b, value);

    write(1, "pb\n", 3);
}