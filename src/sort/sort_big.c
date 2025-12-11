/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdoul <yaabdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 18:00:00 by yaabdoul          #+#    #+#             */
/*   Updated: 2025/12/11 20:18:19 by yaabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

int ft_abs(int n)
{
    return (n < 0) ? -n : n;
}

int stack_size(stack *s)
{
    int size = 0;
    while (s)
    {
        size++;
        s = s->next;
    }
    return size;
}

int find_position(stack *s, int index)
{
    int pos = 0;
    while (s)
    {
        if (s->index == index)
            return pos;
        pos++;
        s = s->next;
    }
    return -1;
}

int get_cost(int pos, int size)
{
    if (pos <= size / 2)
        return pos;
    return -(size - pos);
}
stack *find_smallest(stack *a)
{
    stack *min = a;
    while (a)
    {
        if (a->index < min->index)
            min = a;
        a = a->next;
    }
    return min;
}

void find_target(stack *a, stack *b)
{
    stack *tmp;
    while (b)
    {
        tmp = a;
        b->target = NULL;
        while (tmp)
        {
            if (tmp->index > b->index && (!b->target || tmp->index < b->target->index))
                b->target = tmp;
            tmp = tmp->next;
        }
        if (!b->target)
            b->target = find_smallest(a);
        b = b->next;
    }
}

void calculate_costs(stack *a, stack *b)
{
    if (!a || !b)
        return;
    int size_a = stack_size(a);
    int size_b = stack_size(b);
    stack *tmp = b;

    while (tmp)
    {
        if (!tmp->target)
        {
            tmp = tmp->next;
            continue;
        }
        tmp->cost_b = get_cost(find_position(b, tmp->index), size_b);
        tmp->cost_a = get_cost(find_position(a, tmp->target->index), size_a);
        tmp = tmp->next;
    }
}

stack *find_cheapest(stack *b)
{
    stack *cheap = b;
    int best = 2147483647;
    stack *tmp = b;

    while (tmp)
    {
        int total = ft_abs(tmp->cost_a) + ft_abs(tmp->cost_b);
        if (total < best)
        {
            best = total;
            cheap = tmp;
        }
        tmp = tmp->next;
    }
    return cheap;
}

void double_move(stack **a, stack **b, stack *n)
{
    while (n->cost_a > 0 && n->cost_b > 0)
    {
        rr(a, b, 0);
        n->cost_a--;
        n->cost_b--;
    }
    while (n->cost_a < 0 && n->cost_b < 0)
    {
        rrr(a, b, 0);
        n->cost_a++;
        n->cost_b++;
    }
}

void single_move(stack **a, stack **b, stack *n)
{
    while (n->cost_a > 0) { ra(a, 0); n->cost_a--; }
    while (n->cost_a < 0) { rra(a, 0); n->cost_a++; }
    while (n->cost_b > 0) { rb(b, 0); n->cost_b--; }
    while (n->cost_b < 0) { rrb(b, 0); n->cost_b++; }
}

void execute_move(stack **a, stack **b, stack *n)
{
    double_move(a, b, n);
    single_move(a, b, n);
    pa(a, b, 0);
}

void bring_to_top(stack **a, int index)
{
    int pos = find_position(*a, index);
    if (pos < 0) return;

    int size = stack_size(*a);
    if (pos <= size / 2)
        while (pos--) ra(a, 0);
    else
    {
        int moves = size - pos;
        while (moves--) rra(a, 0);
    }
}

void final_align(stack **a)
{
    int min_idx = find_position(*a, 0);
    if (min_idx < 0) return;

    int size = stack_size(*a);
    if (min_idx <= size / 2)
        while (min_idx--) ra(a, 0);
    else
    {
        int moves = size - min_idx;
        while (moves--) rra(a, 0);
    }
}

void turk_sort(stack **a, stack **b)
{
    int size = stack_size(*a);
    int chunk_size = (size <= 100) ? 20 : (size <= 500) ? 50 : 100;
    int min = 0;
    int max = chunk_size - 1;

    while (*a)
    {
        int moved = 0;
        stack *tmp = *a;
        while (tmp)
        {
            if (tmp->index >= min && tmp->index <= max)
            {
                bring_to_top(a, tmp->index);
                pb(a, b, 0);
                moved = 1;
                break;
            }
            tmp = tmp->next;
        }
        if (!moved)
        {
            min += chunk_size;
            max += chunk_size;
            if (min > size) break;
        }
    }

    if (stack_size(*a) == 2) ra(a, 0);
    else if (stack_size(*a) == 3) sort_three(a);

    while (*b)
    {
        find_target(*a, *b);
        calculate_costs(*a, *b);
        stack *cheap = find_cheapest(*b);
        execute_move(a, b, cheap);
    }

    final_align(a);
}
