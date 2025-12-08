/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdoul <yaabdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:27:41 by yaabdoul          #+#    #+#             */
/*   Updated: 2025/12/08 18:27:42 by yaabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

//add the first element of the stack b int the top of a
void    pa(stack **a,stack **b)
{   
    if(!b || !*b)
        return;
    int value;

    value = pop(b);
    push(a,value);
    write(1,"pa\n",3);
}    
//add the first element of the stack a int the top of b
void    pb(stack **a,stack **b)
{   
    if(!a || !*a)
        return;
    int value;

    value = pop(a);
    push(b,value);
    write(1,"pb\n",3);
}    
