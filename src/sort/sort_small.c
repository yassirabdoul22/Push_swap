/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdoul <yaabdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:27:54 by yaabdoul          #+#    #+#             */
/*   Updated: 2025/12/08 18:27:55 by yaabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

int stack_size(stack *a)
{
    int i;

    i = 0;
    while(a)
    {
        i++;
        a = a->next;
    }    
    return (i);
}

int find_index(stack *a , int value)
{
    int index;

    index = 0;

    while(a)
    {
        if(a->element == value)
            return index;
        a = a->next;
        index++;
    }
    return (-1);
}


void    sort_three(stack **a)
{
    int x;
    int y;
    int z;

    x = (*a)->element;
    y = (*a)->next->element;
    z = (*a)->next->next->element;

    if(x > y && y < z && x < z)
        sa(a,0);
    else if(x > y && y > z)
    {
        sa(a,0);
        rra(a,0);
    }
    else if(x > z && y < z)
        ra(a,0);
    else if(x < y && y > z && x < z)
    {
        sa(a,0);
        ra(a,0);
    }
    else if(x < y && y > z && x > z)
        rra(a,0);
}
int find_min(stack *a)
{
    int min;

    min = a->element;
    while(a)
    {
        if(a->element < min)
            min = a->element;
        a = a->next;
        
    }
    return min;
}


void    sort_five(stack **a,stack **b)
{
    int min;

    while(stack_size(*a)>3)
    {
        min = find_min(*a);
        if(find_index(*a,min) <= stack_size(*a) / 2)
            while((*a)->element != min)
                ra(a,0);
        else
            while((*a)->element != min)
                rra(a,0);
        pb(a,b);
    }
    sort_three(a);
    while (*b)
        pa(a, b);
}