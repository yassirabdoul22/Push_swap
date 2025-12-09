#include "includes/stack.h"

void push_swap(stack **a, stack **b)
{
    int size = stack_size(*a);

    if (size <= 1)
        return;
    else if (size == 2)
    {
        if ((*a)->element > (*a)->next->element)
            sa(a, 1);
    }
    else if (size == 3)
        sort_three(a);
    else if (size <= 5)
        sort_five(a, b);
    //else
        //sort_big(a, b);
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

    push_swap(&a, &b);

    // // Afficher stack après tri
    // printf("Stack a après tri : ");
    // display_data(&a);

    while (a)
        Remove_first(&a);
    while (b)
        Remove_first(&b);

    return 0;
}
