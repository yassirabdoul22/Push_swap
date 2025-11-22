#include "../../includes/stack.h"
#include <stdio.h>

//swap the first and the second elements in a
void    ft_sa(stack **a)
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
}
//swap the first and the second elements in b
void    ft_sb(stack **b)
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
}
//do the sa and sb 
void    ft_ss( stack **a,stack **b)
{
    ft_sa(a);
    ft_sb(b);
}


