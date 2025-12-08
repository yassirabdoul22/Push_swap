/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdoul <yaabdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:27:49 by yaabdoul          #+#    #+#             */
/*   Updated: 2025/12/08 18:27:50 by yaabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include <stdio.h>

//swap the first and the second elements in a
void    sa(stack **a,int iscalled)
{
    stack *second;
    stack *first;
    
    if(check_stack(a) || !*a || !(*a)->next)
        return;
    first = *a;
    second = (*a)->next;
    
    first->next=second->next;
    second->next=first;
    *a =second;
    if(!iscalled)
        write(1,"sa\n",3);
}
//swap the first and the second elements in b
void    sb(stack **b,int iscalled)
{
    stack *second;
    stack *first;

    if(check_stack(b) || !*b || (*b)->next)
        return;
    first = *b;
    second = (*b)->next;    
    first->next = second->next;
    second->next = first;
    *b = second;
    if(!iscalled)
        write(1,"sb\n",3);
}
//do the sa and sb 
void    ss( stack **a,stack **b)
{
    sa(a,1);
    sb(b,1);
    write(1,"ss\n",3);
}


