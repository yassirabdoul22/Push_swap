#include "includes/stack.h"

void push_swap(stack **a, stack **b)
{
    int size = stack_size(*a);

    if (size <= 1)
        return;
    else if (size == 2)
    {
        if (!ft_is_sorted(*a))
            sa(a, 0);
    }
    else if (size == 3)
        sort_three(a);
    else if (size <= 5)
        sort_five(a, b);
    else
        turk_sort(a, b);
}

int main(int ac, char **argv)
{
    stack *a = NULL;
    stack *b = NULL;

    if (ac < 2)
        return 0;

    if (!parse_args(&a, ac, argv))
        return 1;

    if (check_stack(&a))
    {
        while (a)
            Remove_first(&a);
        return 0;
    }

    assign_index(a);
    push_swap(&a, &b);

    while (a)
        Remove_first(&a);
    while (b)
        Remove_first(&b);

    return 0;
}
