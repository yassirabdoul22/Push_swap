/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdoul <yaabdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:00:00 by yaabdoul          #+#    #+#             */
/*   Updated: 2025/12/09 14:10:00 by yaabdoul         ###   ########.fr       */
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

void sort_three(stack **a)
{
    if (!a || !*a || !(*a)->next || !(*a)->next->next)
        return;

    int first = (*a)->element;
    int second = (*a)->next->element;
    int third = (*a)->next->next->element;

   
    if (first > second && second < third && first < third)
    {
        sa(a, 0);
      
    }
    else if (first > second && second > third)
    {
        sa(a, 0);
        rra(a, 0);
    }
    else if (first > second && second < third && first > third)
    {
        ra(a, 0);
    }
    else if (first < second && second > third && first < third)
    {
        sa(a, 0);
        ra(a, 0);
     
    }
    else if (first < second && second > third && first > third)
    {
        rra(a, 0);
    }
}
int find_index(stack *a, int value)
{
    int i = 0;
    while (a)
    {
        if (a->element == value)
            return i;
        a = a->next;
        i++;
    }
    return -1;
}

int find_min(stack *a)
{
    int min = a->element;
    while (a)
    {
        if (a->element < min)
            min = a->element;
        a = a->next;
    }
    return min;
}

void sort_five(stack **a, stack **b)
{
    while (stack_size(*a) > 3)
    {
        int min = find_min(*a);
        int idx = find_index(*a, min);
        int size = stack_size(*a);

        if (idx <= size / 2)
            while ((*a)->element != min)
                ra(a, 0);
        else
            while ((*a)->element != min)
                rra(a, 0);

        pb(a, b);
    }

    sort_three(a);

    while (*b)
        pa(a, b);
}

