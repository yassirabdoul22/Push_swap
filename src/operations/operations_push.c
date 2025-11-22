#include "../../includes/stack.h"

//add the first element of the stack b int the top of a
void    ft_pa(stack **a,stack **b)
{   
    if(!b || !*b)
        return;
    int value;

    value = pop(b);
    push(a,value);
}    
//add the first element of the stack a int the top of b
void    ft_pb(stack **a,stack **b)
{   
    if(!a || !*a)
        return;
    int value;

    value = pop(a);
    push(b,value);
}    
